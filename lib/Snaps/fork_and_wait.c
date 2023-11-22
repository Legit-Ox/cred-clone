// Fork and Wait System Calls: Demonstrates fork and wait system calls to create child processes.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t p;
    p = fork();
    if (p == 0) {
        // Child process
        printf("I am child having id %d\\n", getpid());
        printf("My parent's id is %d\\n", getppid());
    } else {
        // Parent process
        wait(NULL);
        printf("My child's id is %d\\n", p);
        printf("I am parent having id %d\\n", getpid());
    }
}
