// Open System Call (Existing File): Opens an existing file and writes its content to standard output.

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int n, fd;
    char b[40];
    // Open an existing file for reading
    fd = open("file1.txt", O_RDONLY);
    n = read(fd, b, 20);
    // Write file content to standard output
    write(1, b, 20);
    return 0;
}
