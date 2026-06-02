#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  char *command = NULL;
  size_t len = 0;
  ssize_t read;

  printf("$ ");
  read = getline(&command, &len, stdin);

  if (read != -1) {
    command[len - 2] = '\0';
    printf("%s: command not found", command);
  }

  free(command);
  return 0;
}
