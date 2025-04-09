#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FILE_PATH       "/home/si-mediaserver18/susheel/demo_files/10MB.mp4"
#define SHM_KEY         1234
#define CHUNK_SIZE      5021
#define SHM_SIZE        (10 * 1024 * 1024 + sizeof(size_t))  // 10 MB + size header

int main() {
    // Create shared memory segment
    int shm_id = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
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

    // Write the file content to shared memory in chunks
    size_t total_bytes_written = 0;
    size_t bytes_read;
    while (total_bytes_written < SHM_SIZE && (bytes_read = fread(shared_mem + sizeof(size_t) + total_bytes_written, 1, CHUNK_SIZE, file)) > 0) {
        total_bytes_written += bytes_read;
        printf("Sender: Written %zu bytes to shared memory\n", total_bytes_written);
    }

    printf("Sender: Finished writing %zu bytes to shared memory.\n", total_bytes_written);

    // Close the file and detach from shared memory
    fclose(file);
    shmdt(shared_mem);

    return 0;
}
