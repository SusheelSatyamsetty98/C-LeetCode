#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX 100

int calculate_max(int *a, int start, int end)
{
    int max = 0;
    for(int i = start; i < end; i++)
    {
        int prod = (a[i] * a[i+1]);
        max = max >  prod ? max : prod; 
    }

    return max;
}

int main() {
    int a[MAX] = {0};
    int no_of_elements = 0;
    int max = 0;
    int start = 0;
    int end = 0;
    int fd[2]; // file descriptors: fd[0] for reading, fd[1] for writing

    // Create an unnamed pipe
    if (pipe(fd) == -1) {
        perror("pipe failed");
        return 1;
    }


    printf("Enter no of elements: ");
    scanf("%d", &no_of_elements);

    for(int i = 0; i < no_of_elements; i++)
    {
        scanf("%d", &a[i]);
    }
    
    pid_t pid = fork(); // Fork a child process

    if (pid == 0) {  // Child process
        close(fd[1]);  // Close the write end
        start = 0;
        end = no_of_elements/2;
    } else {  // Parent process
        close(fd[0]);  // Close the read end
        start = no_of_elements/2;
        end = no_of_elements;
    }

    if (pid == 0) 
    {
        int get_max = 0; // Child process
        max = calculate_max(a,start,end);
        read(fd[0], &get_max, sizeof(get_max));
        max = max > get_max ? max : get_max;
        close(fd[0]);
    } else {  // Parent process
        max = calculate_max(a,start,end);
        write(fd[1], &max, sizeof(max));
        close(fd[1]);

        // wait(NULL);
        int status;
        waitpid(pid, &status, 0); 
    }

    if (pid == 0)
    {
        printf("MAX : %d\n", max);
    }
    
    return 0;
}