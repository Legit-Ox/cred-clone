// Preventing Zombie Processes: Demonstrates preventing zombie processes using wait system call.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t t;
    t = fork();
    if (t == 0) {
        // Child process
        printf("Child having id %d\\n", getpid());
    } else {
        // Parent process
        wait(NULL);
        sleep(5);
        printf("Parent having id %d\\n", getpid());
    }
}
