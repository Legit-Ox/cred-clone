// lseek System Call (Repositioning File Pointer): Demonstrates repositioning the file pointer.

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int n, f;
    char b[50];
    f = open("file2.txt", O_RDONLY);
    read(f, b, 10);
    write(1, b, 10);
    // Reposition the file pointer
    lseek(f, 10, SEEK_CUR);
    read(f, b, 10);
    write(1, b, 10);
}
