// Creating Orphan and Zombie Processes: Demonstrates creating child processes and handling orphan and zombie processes.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t p;
    p = fork();
    if (p == 0) {
        // Child process
        printf("I am child having PID %d\\n", getpid());
        printf("My parent PID is %d\\n", getppid());
    } else {
        // Parent process
        sleep(3);
        printf("I am parent having PID %d\\n", getpid());
        printf("My child PID is %d\\n", p);
    }
}
