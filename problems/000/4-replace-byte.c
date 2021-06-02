#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Return a copy of the input value `x` with `byte` at significant byte `index`.
//
// little-endian system only.
unsigned replace_byte(unsigned x, int index, unsigned char byte) {
  char *block = (char *)&x + index;
  *block = byte;
  return x;
}

int main(int argc, char **argv) {
  printf("0x%0.8x", replace_byte(0x11223344, 3, 0xFF));
  return 0;
}
