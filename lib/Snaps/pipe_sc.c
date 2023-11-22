// Pipe System Call: Demonstrates inter-process communication using a pipe.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int fd[2], n;
    char buffer[90];
    pid_t p;
    // Create a pipe for communication between processes
    pipe(fd);
    p = fork();
    if (p > 0) {
        // Parent sends data to child
        printf("Parent send data to child\\n");
        write(fd[1], "hello class\\n", 12);
    } else {
        // Child receives data from parent
        printf("Child received the data\\n");
        n = read(fd[0], buffer, 90);
        write(1, buffer, n);
    }
}
