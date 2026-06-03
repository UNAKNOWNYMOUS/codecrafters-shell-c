#define _GNU_SOURCE
#include <stddef.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setvbuf(stdout, NULL, _IONBF, 0);

  char *command = NULL;
  size_t len = 0;
  ssize_t read;

  printf("$ ");

  read = getline(&command, &len, stdin);
  if (read == -1) {
    printf("Error reading from stdin\n");
  } else {
    printf("Line read is: %s\n", command);
  }

  return 0;
}
