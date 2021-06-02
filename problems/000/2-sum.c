#include <stdio.h>   // C standard I/O functions
#include <stdlib.h>  // Additional common C standard library functions
#include <unistd.h>  // Common functions and constants for Unix systems

int main(int argc, char **argv) {
  char *endptr, *line = NULL;
  size_t len = 0;
  ssize_t read;

  long acc = 0;
  long val = 0;
  while ((read = getline(&line, &len, stdin)) != -1) {
    val = strtol(line, &endptr, 0);
    acc = acc + val;
  }
  printf("%ld", acc);
  return 0;  // Successful exit. Nonzero return indicates failure.
}
