#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FILE_PATH       "/home/si-mediaserver18/susheel/demo_files/18MB.mp4"
#define SHM_KEY         1234
#define CHUNK_SIZE      5021
#define SHM_SIZE        (10 * 1024 * 1024)  // 10 MB + size header

int main() {
    // Create shared memory segment
    int shm_id = shmget(SHM_KEY, SHM_SIZE + sizeof(size_t), 0666 | IPC_CREAT);
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

    // Open the file to read content
    FILE *file = fopen(FILE_PATH, "rb");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }

    // Write the file size to shared memory first
    *((size_t *)shared_mem) = SHM_SIZE;

    // Allocate temp buffer for one chunk size
    char *temp_buffer = (char *)malloc(CHUNK_SIZE);
    if (temp_buffer == NULL) {
        perror("malloc");
        exit(1);
    }

    // Write the file content to shared memory in chunks
    size_t total_bytes_written = 0;
    size_t bytes_read;
    while (total_bytes_written < SHM_SIZE && (bytes_read = fread(temp_buffer, 1, CHUNK_SIZE, file)) > 0) 
    {
        // Ensure not to write more than the 10MB limit
        size_t remaining_space = SHM_SIZE - total_bytes_written;
        size_t bytes_to_copy = (bytes_read < remaining_space) ? bytes_read : remaining_space;

        // Copy the chunk from temp_buffer to shared memory at the correct offset
        memcpy(shared_mem + sizeof(size_t) + total_bytes_written, temp_buffer, bytes_to_copy);
        total_bytes_written += bytes_to_copy;
#ifdef DEBUG_MODE
        printf("Sender: Written %zu bytes to shared memory\n", total_bytes_written);
#endif
        if (total_bytes_written >= SHM_SIZE)
        {
            total_bytes_written = SHM_SIZE;
        }
        memset(temp_buffer, 0, CHUNK_SIZE);
    }

    printf("Sender: Finished writing %zu bytes to shared memory.\n", total_bytes_written);
    
    free(temp_buffer);
    // Close the file and detach from shared memory
    fclose(file);
    shmdt(shared_mem);

    return 0;
}

