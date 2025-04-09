#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SENDER 1
#define RECEIVER 1
#define TEST 1
#define MAX_BUFFER_SIZE 5021
#define SENDER_FILE_PATH "./file_example_MP4_480_1_5MG.mp4"
#define RECEIVER_FILE_PATH "./received_1_5mb.mp4"
//#define SENDER_FILE_PATH "demo_10mb_file-1k.bin"
//#define RECEIVER_FILE_PATH "./received_1kb.bin"

int file_read(FILE *fp, int offset, char* data)
{
    if (fseek(fp, offset, SEEK_SET) < 0)
    {
        printf("Failed to seek to position: %d\n",offset);
        return -1;
    }

    return fread(data, sizeof(char), MAX_BUFFER_SIZE - 1, fp);
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
    char *path = "./pipefile";
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
#if SENDER
        int fsize = file_size(SENDER_FILE_PATH);
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
#endif
    }
    else
    {
#if RECEIVER 
        char *data = (char*)malloc(MAX_BUFFER_SIZE);
        int fd = open(path, O_RDONLY | O_NONBLOCK);
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
            if (ssize <= 0)
            {
                printf("Failed to read with error: %d", ssize);
                break;
            }
//            data[ssize] = '\0';

            int write_size = file_write(fp, data, ssize);
            if (write_size < 0)
            {
                printf("Failed to write the content into file...");
                break;
            }
        }
        //} while(ssize > 0);

        close(fd);
        fclose(fp);
        free(data);
#endif
    }
    
//    system("C:\Program Files (x86)\VideoLAN\VLC\vlc C:\Users\lg\Downloads\file_example_MP4_480_1_5MG.mp4");
//    unlink(path);
    return 0;
}
