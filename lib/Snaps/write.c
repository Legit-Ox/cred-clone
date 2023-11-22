// Write System Call: Reads input from standard input and writes it to standard output.

#include <unistd.h>

int main() {
    int n;
    char b[20];
    n = read(0, b, 20);
    // Write user input to standard output
    write(1, b, n);
    return 0;
}
