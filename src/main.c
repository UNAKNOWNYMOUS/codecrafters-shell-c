#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1

int main(int argc, char *argv[]) {
  // Flush after every printf
  setvbuf(stdout, NULL, _IONBF, 0);

  char *command = NULL;
  size_t len = 0;
  ssize_t read;

  while (TRUE) {
    printf("$ ");

    read = getline(&command, &len, stdin);
    if (read != -1) {
      command[read - 1] = '\0';
    }

    if (strcmp(command, "exit") == 0) {
      break;
    } else if (strncmp(command, "echo ", 5) == 0) {
      printf("%s\n", &command[5]);
    } else {
      printf("%s: command not found\n", command);
    }
    free(command);
  }
  return 0;
}
