#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define FILE_PATH    "/home/si-mediaserver18/susheel/demo_files/18MB.mp4"
#define SERVER_IP "127.0.0.1"
#define PORT 9090  // User's preferred port
#define BUFFER_SIZE 1024
#define FILE_SIZE_LIMIT 10485760  // 10 MB

typedef struct {
    int client_sock;
    struct sockaddr_in server_addr;
    FILE *fp;
} thread_args;

void* send_file_thread(void* arg) {
    thread_args* args = (thread_args*) arg;
    char buffer[BUFFER_SIZE];
    char ack[BUFFER_SIZE];
    ssize_t sent_size = 0;
    ssize_t total_sent = 0;

    while ((sent_size = fread(buffer, 1, BUFFER_SIZE, args->fp)) > 0 && total_sent < FILE_SIZE_LIMIT) {
        // Send packet to server
        if (sendto(args->client_sock, buffer, sent_size, 0, (struct sockaddr*)&(args->server_addr), sizeof(args->server_addr)) < 0) {
            perror("Sending error");
            break;
        }

        // Wait for acknowledgment
        socklen_t server_len = sizeof(args->server_addr);
        if (recvfrom(args->client_sock, ack, sizeof(ack), 0, (struct sockaddr*)&(args->server_addr), &server_len) < 0) {
            perror("Acknowledgment error");
            break;
        }

        total_sent += sent_size;
    }

    printf("Total bytes sent: %ld\n", total_sent);
    fclose(args->fp);
    free(arg); // Free the memory allocated for thread arguments
    pthread_exit(NULL);
}

int main() {
    int client_sock;
    struct sockaddr_in server_addr;
    FILE *fp;
    pthread_t thread;
    client_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(PORT);

    for(int i = 0; i < 5; i++)
    {
    fp = fopen(FILE_PATH, "rb");
    if (!fp) {
        perror("File opening error");
        close(client_sock);
        exit(EXIT_FAILURE);
    }

    // Allocate memory for thread arguments
    thread_args* args = (thread_args*) malloc(sizeof(thread_args));
    args->client_sock = client_sock;
    args->server_addr = server_addr;
    args->fp = fp;

    // Create the thread to handle file transfer
    if (pthread_create(&thread, NULL, send_file_thread, (void*)args) != 0) {
        perror("Thread creation failed");
        fclose(fp);
        close(client_sock);
        exit(EXIT_FAILURE);
    }

    // Wait for the thread to complete
    pthread_join(thread, NULL);
    }
    close(client_sock);
    return 0;
}

