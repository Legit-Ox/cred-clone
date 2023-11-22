// Read System Call: Reads input from standard input and writes it to standard output.

#include <unistd.h>

int main() {
    // Array to store input and read from standard input
    char b[15];
    read(0, b, 12);
    // Write the read input to standard output
    write(1, b, 12);
    return 0;
}
