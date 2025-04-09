#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 9090  // User's preferred port
#define BUFFER_SIZE 1024
#define FILE_SIZE_LIMIT 10485760  // 10 MB
#define MAX_CLIENTS 5  // Maximum number of clients allowed

int client_count = 0;
pthread_mutex_t client_count_mutex;  // Mutex to protect client count

void* handle_client(void* arg) {
    int sock = *((int*)arg);  // No need to free arg, as it's a shared socket in this case.
    
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    char ack[] = "ACK";
    ssize_t received_size = 0;
    ssize_t bytes_received = 0;

    // Generate the filename using client_count
    char filename[50];
    pthread_mutex_lock(&client_count_mutex);  // Lock to safely access client_count
    sprintf(filename, "./received_file_%d.mp4", client_count);
    pthread_mutex_unlock(&client_count_mutex);  // Unlock after updating the filename

    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("File opening error");
        pthread_exit(NULL);
    }
    printf("Opened file %s for writing\n", filename);  // Debug to check file creation

    while (received_size < FILE_SIZE_LIMIT) {
        // Receiving data from client
        bytes_received = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &client_len);
        if (bytes_received <= 0) {
            perror("Receiving error");
            break;
        }

        // Write received data to file
        ssize_t written_bytes = fwrite(buffer, 1, bytes_received, fp);
        if (written_bytes != bytes_received) {
            perror("File write error");
            break;
        }

        received_size += bytes_received;

        // Send acknowledgment after receiving each buffer
        sendto(sock, ack, sizeof(ack), 0, (struct sockaddr*)&client_addr, client_len);
    }

    printf("Total bytes received: %ld, saved to %s\n", received_size, filename);
    fclose(fp);

    pthread_exit(NULL);
}

int main() {
    int server_sock;
    struct sockaddr_in server_addr;

    // Initialize the client count mutex
    pthread_mutex_init(&client_count_mutex, NULL);

    // Create the UDP server socket once
    server_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        pthread_mutex_lock(&client_count_mutex);

        if (client_count >= MAX_CLIENTS) {
            printf("Max client limit reached. Exiting...\n");
            pthread_mutex_unlock(&client_count_mutex);
            break;  // Stop accepting new clients and exit the loop
        }

        // Increment the client count
        client_count++;
        pthread_mutex_unlock(&client_count_mutex);

        // Create a new thread for each client connection
        pthread_t thread;

        // Pass the same socket to all threads as UDP does not need a new socket per connection
        if (pthread_create(&thread, NULL, handle_client, &server_sock) != 0) {
            perror("Thread creation error");
            close(server_sock);
            exit(EXIT_FAILURE);
        }

        // Wait for the thread to finish
        pthread_join(thread, NULL);  // Wait for this thread to finish before accepting new clients
    }

    // Close the server socket (this will happen when max client count is reached)
    close(server_sock);

    // Destroy the mutex
    pthread_mutex_destroy(&client_count_mutex);

    return 0;
}

