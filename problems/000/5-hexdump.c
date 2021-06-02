#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char *ALPHABET = "0123456789ABCDEF";

// Encode a sequence of data as ASCII hex digits, written to `output` and null
// terminated.
//
// You may assume the output buffer has at least 2*sizeof(data) + 1 bytes of
// capacity.
void hexencode(char *data, unsigned len, char *output) {
  // So for an input say "h", we want an output "68"
  //
  // In binary, that would be:
  //
  // 01101000 -> 36, 38
  // 0110 1000 -> 6, 8
  //
  // we need an alphabet to index into, and then the bits give us the index
  int i;
  for (i = 0; i < len; ++i) {
    output[i * 2] = ALPHABET[data[i] >> 4];
    output[(i * 2) + 1] = ALPHABET[data[i] & 0x0F];
  }

  // null termination - implicit if malloc initializes memory?
  output[len * 2] = 0;
}

int main(int argc, char **argv) {
  char *input = malloc(6 * sizeof(char));
  strcpy(input, "hello");
  char *output = malloc(13 * sizeof(char));

  hexencode(input, 6, output);
  printf("%s", output);
  return 0;
}
