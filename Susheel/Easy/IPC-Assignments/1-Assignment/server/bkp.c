#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 9090  // User's preferred port
#define BUFFER_SIZE 1024
#define FILE_SIZE_LIMIT 10485760  // 10 MB

void* handle_client(void* arg) {
    int sock = *((int*)arg);  // No need to free arg, as it's a shared socket in this case.
    
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    char ack[] = "ACK";
    ssize_t received_size = 0;
    ssize_t bytes_received = 0;
    FILE *fp = fopen("./received_file.mp4", "wb");

    if (!fp) {
        perror("File opening error");
        pthread_exit(NULL);
    }

    // Debug statement to ensure file opened successfully
    printf("File opened for writing\n");

    while (received_size < FILE_SIZE_LIMIT) {
        // Receiving data from client
        bytes_received = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &client_len);
        if (bytes_received <= 0) {
            perror("Receiving error");
            break;
        }

        // Debug statement to check received bytes
        printf("Received %ld bytes\n", bytes_received);

        // Write received data to file
        fwrite(buffer, 1, bytes_received, fp);
        received_size += bytes_received;

        // Debug statement to check if data is written to the file
        printf("Total bytes written to file: %ld\n", received_size);

        // Send acknowledgment after receiving each buffer
        sendto(sock, ack, sizeof(ack), 0, (struct sockaddr*)&client_addr, client_len);
    }

    printf("Total bytes received: %ld\n", received_size);
    fclose(fp);
    pthread_exit(NULL);
}

int main() {
    int server_sock;
    struct sockaddr_in server_addr;

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
        // Create a new thread for each client connection
        pthread_t thread;

        // Pass the same socket to all threads as UDP does not need a new socket per connection
        if (pthread_create(&thread, NULL, handle_client, &server_sock) != 0) {
            perror("Thread creation error");
            close(server_sock);
            exit(EXIT_FAILURE);
        }

        // Wait for the thread to finish (optional, can remove if you want concurrent connections)
        pthread_join(thread, NULL);
    }

    // Close the server socket (this will rarely happen due to the infinite loop)
    close(server_sock);
    return 0;
}

