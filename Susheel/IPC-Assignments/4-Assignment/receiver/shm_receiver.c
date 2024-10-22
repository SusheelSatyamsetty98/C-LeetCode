#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define RECEIVER_FILE_PATH      "./received.mp4"
#define SHM_KEY         1234
#define CHUNK_SIZE      5021
#define SHM_SIZE        (10 * 1024 * 1024 + sizeof(size_t))  // 10 MB + size header
#define MAX_QUEUE_SIZE  5

struct queue_struct_t {
    char buf[CHUNK_SIZE];
    size_t size;
};

int front = 0;
int rear = 0;

int main() {
    struct queue_struct_t queue[MAX_QUEUE_SIZE];

    // Locate the shared memory segment
    int shm_id = shmget(SHM_KEY, sizeof(queue) + sizeof(size_t), 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory
    char *shared_mem = (char *)shmat(shm_id, NULL, 0);
    if (shared_mem == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Read the actual size of the file from shared memory
    size_t actual_file_size = *((size_t *)shared_mem);
    printf("Receiver: Actual file size to read: %zu bytes\n", actual_file_size);

    // Open a new file to write the received data
    FILE *file = fopen(RECEIVER_FILE_PATH, "wb");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }

    // Read from shared memory in chunks
    size_t total_bytes_read = 0;
    size_t bytes_to_read;

    while ((total_bytes_read < actual_file_size)  && (total_bytes_read < (SHM_SIZE - sizeof(size_t))))
    {
        // Calculate how many bytes to read
        bytes_to_read = (actual_file_size - total_bytes_read > CHUNK_SIZE) ? CHUNK_SIZE : (actual_file_size - total_bytes_read);
        // Allocate memory for the new buffer
        queue[rear].buf = (char *)malloc(bytes_to_read);
        if (queue[rear].buf == NULL) {
            perror("malloc");
            break; // Exit if memory allocation fails
        }
        queue[rear].size = bytes_to_read;

        // Copy data from shared memory to the queue buffer
        memcpy(queue[rear].buf, shared_mem + sizeof(size_t) + total_bytes_read, bytes_to_read);

        // Move rear to the next position
        rear = (rear + 1) % MAX_QUEUE_SIZE;

        // Write data to the file from the front of the queue
        while (front == rear) {  // Process items in the queue
            // Write the chunk to file
            size_t bytes_written = fwrite(queue[front].buf, 1, queue[front].size, file);
            if (bytes_written != queue[front].size) {
                printf("Receiver: fwrite error, breaking the loop.\n");
                break; // Exit if fwrite fails
            }
            total_bytes_read += bytes_written;
            // Stop once we have exactly 10MB
            if (total_bytes_read >= (SHM_KEY - sizeof(size_t)) ) {
                printf("Receiver : 10MB file received. Closing connection.\n");
                break;
            }

            // Free the buffer and reset its pointer
            free(queue[front].buf);
            queue[front].buf = NULL;

            // Move front to the next position
            front = (front + 1) % MAX_QUEUE_SIZE;

            #ifdef DEBUG_MODE
            printf("Receiver: Written %zu bytes from shared memory\n", total_bytes_read);
            #endif
        }
    }

    printf("Receiver: Finished writing %zu bytes to %s\n", total_bytes_read, RECEIVER_FILE_PATH);

    // Close the file
    fclose(file);

    // Detach from the shared memory
    shmdt(shared_mem);

    // Optionally, remove the shared memory segment after reading
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}