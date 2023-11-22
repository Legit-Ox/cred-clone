// Append Content to a Newly Created File: Appends user input to a file.

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int n, fd;
    char b[40];
    n = read(0, b, 30);
    // Append input from user to a file
    fd = open("file4.txt", O_WRONLY | O_APPEND);
    write(fd, b, 30);
}
