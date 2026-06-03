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
  printf("%c", command[len - 1]);
  if (read != -1) {
    printf("%s: command not found", command);
  }
  return 0;
}
