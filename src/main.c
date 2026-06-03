#define _GNU_SOURCE

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setvbuf(stdout, NULL, _IONBF, 0);

  char *command = NULL;
  size_t len = 0;
  ssize_t read;

  while (1) {
    printf("$ ");

    read = getline(&command, &len, stdin);
    if (read != -1) {
      command[read - 1] = '\0';
      printf("%s: command not found\n", command);
    }
    free(command);
  }

  return 0;
}
