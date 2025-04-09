#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define NAMED_PIPE          "/tmp/pipefile"
#define SENDER_FILE_PATH    "/home/si-mediaserver18/susheel/demo_files/18MB.mp4"
#define RECEIVER_FILE_PATH  "./received.mp4"
#define MAX_BUFFER_SIZE     128
#define MAX_READ_FILE_SIZE  (10 * 1024 * 1024)

int file_read(FILE *fp, int offset, char* data)
{
    if (fseek(fp, offset, SEEK_SET) < 0)
    {
        printf("Failed to seek to position: %d\n",offset);
        return -1;
    }

    return fread(data, sizeof(char), MAX_BUFFER_SIZE, fp);
}

int file_write(FILE* fp, char* data, int bufsize)
{
    return fwrite(data, sizeof(char), bufsize, fp);
}
   
int file_size(const char *filepath)
{
    int size = 0;
    struct stat filestat;

    if (stat(filepath, &filestat) < 0)
    {
        printf("Failed to get the file size of %s file", filepath);
    }
    else
    {
        size = filestat.st_size;
    }
    
    return size;
}   


int main()
{
    char *path = NAMED_PIPE;
    mkfifo(path, 0777);

    int pid = 0;
    
    pid = fork();
    if (pid == -1)
    {
        printf("Failed to create the child process...exiting");
        return pid;
    }

    if (0 == pid)
    {
        int fsize = file_size(SENDER_FILE_PATH);
        fsize = (fsize > MAX_READ_FILE_SIZE) ? MAX_READ_FILE_SIZE : fsize;
        int fd = open(path, O_WRONLY);
        int total_data_read = 0;
        char *data = (char*)malloc(MAX_BUFFER_SIZE);
        FILE *fp = NULL;

        fp = fopen(SENDER_FILE_PATH,"rb");
        if(NULL == fp)
        {
            printf("Failed to open the %s file", SENDER_FILE_PATH);
            return -1;
        }
       
        while (total_data_read < fsize)
        {
            memset(data, 0, MAX_BUFFER_SIZE);    
            int read_size = file_read(fp, total_data_read, data);
            if (read_size < 0)
            {
                printf("Failed to get the buffer data from file...");
                break;
            }
            else if (read_size == 0)
            {
                printf("Reached End of File and closing the file");
                break;
            }
            else
            {
                total_data_read += read_size;
                int ssize = write(fd, data,read_size);
                if (ssize < 0)
                {
                    printf("Failed to write with error: %d", ssize);
                    break;
                }
            }
        }

        fclose(fp);
        close(fd);
        free(data);
    }
    else
    {
        char *data = (char*)malloc(MAX_BUFFER_SIZE);
        int fd = open(path, O_RDONLY);
        int ssize = 0;
        FILE *fp = NULL;
    
        fp = fopen(RECEIVER_FILE_PATH,"wb");
        if(NULL == fp)
        {
            printf("Failed to open the %s file", RECEIVER_FILE_PATH);
            return -1;
        }

        while(1)
        {
            memset(data, 0, MAX_BUFFER_SIZE);
            ssize = read(fd, data, MAX_BUFFER_SIZE - 1);
            if (ssize < 0)
            {
                printf("Failed to read with error: %d", ssize);
                break;
            }
            else if (ssize == 0)
            {
                break;
            }

            int write_size = file_write(fp, data, ssize);
            if (write_size < 0)
            {
                printf("Failed to write the content into file...");
                break;
            }
        }

        close(fd);
        fclose(fp);
        free(data);
    }

    unlink(path);
    return 0;
}
