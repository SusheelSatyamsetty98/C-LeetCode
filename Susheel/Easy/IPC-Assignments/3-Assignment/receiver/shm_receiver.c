#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>

#define RECEIVER_FILE_PATH      "./received.mp4"
#define SHM_KEY                 1234
#define SHM_SIZE                (10 * 1024 * 1024) 
#define CHUNK_SIZE              5021

int main() {
    // Locate the shared memory segment
    int shm_id = shmget(SHM_KEY, SHM_SIZE + sizeof(size_t), 0666);
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
    while (total_bytes_read < actual_file_size) {
        bytes_to_read = (actual_file_size - total_bytes_read > CHUNK_SIZE) ? CHUNK_SIZE : (actual_file_size - total_bytes_read);

        // Write the chunk to file
        size_t bytes_written = fwrite(shared_mem + sizeof(size_t) + total_bytes_read, 1, bytes_to_read, file);
        if (bytes_written == 0) {
            printf("Receiver: fwrite returned 0, breaking the loop.\n");
            break;
        }
        total_bytes_read += bytes_written;
#ifdef DEBUG_MODE
        printf("Receiver: Written %zu bytes from shared memory\n", total_bytes_read);
#endif
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

