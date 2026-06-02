#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  char *command = NULL;
  size_t len = 0;

  printf("$ ");
  ssize_t read = getline(&command, &len, stdin);

  if (read != -1) {
    printf("%s: command not found", command);
  }

  free(command);
  return 0;
}
