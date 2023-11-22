// Open System Call (Creating New File): Reads content from an existing file and writes it to a newly created file.

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int n, fd, fd1;
    char b[50];
    fd = open("file1.txt", O_RDONLY);
    n = read(fd, b, 10);
    // Create a new file and write some content from an existing file
    fd1 = open("file4.txt", O_CREAT | O_WRONLY, S_IRWXU);
    write(fd1, b, 10);
    return 0;
}
