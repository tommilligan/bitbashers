#include <stdio.h>   // C standard I/O functions
#include <stdlib.h>  // Additional common C standard library functions
#include <unistd.h>  // Common functions and constants for Unix systems

// Returns 0 on a little-endian machine and 1 on a big-endian machine
//
// We want to arrange our memory such that:
// - little endian: [0x00000000, 0x00000001]
// - big endian: [0x00000001, 0x00000000]
//
// Then take the first byte.
//
// This equates to the number 256 as a short, then casting to a char.
int endian(void) {
  // unsigned short block = 256;
  // return (unsigned char)block;
  int i = 1;
  return *((unsigned char *)&i + 3);
}

int main(int argc, char **argv) {
  printf("%d", endian());
  return 0;  // Successful exit. Nonzero return indicates failure.
}
