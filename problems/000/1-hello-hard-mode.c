#include <stdio.h>   // C standard I/O functions
#include <stdlib.h>  // Additional common C standard library functions
#include <unistd.h>  // Common functions and constants for Unix systems

int main(int argc, char **argv) {
    write(STDOUT_FILENO, "Hello, world!", 14);
    return 0;  // Successful exit. Nonzero return indicates failure.
}
