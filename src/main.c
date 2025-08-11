#include "interpreter.h"
#include "run.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  Interpreter interp;
  interpreter_init(&interp);

  if (argc > 2) {
    printf("%s", "Usage: clox [script]");
    return 64;
  } else if (argc == 2) {
    interpreter_run_file(&interp, argv[1]);
  } else {
    interpreter_run_prompt(&interp);
  }

	interpreter_free(&interp);
  return 0;
}
