#include "run.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

  if (argc > 2) {
    printf("%s", "Usage: clox [script]");
    return 64;

    // Execute file
  } else if (argc == 2) {
    runFile(argv[1]);

    // Enter RePL
  } else {
    runPrompt();
  }

  return 0;
}
