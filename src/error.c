#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error_init(Error *err, int line, const char *message) {
  err->line = line;
  err->message = strdup(message);
}

void error_free(Error *err) {
  free(err->message);
  err->message = NULL;
}

void report(Interpreter *interp, const Error *err) {
  fprintf(stderr, "[line %d] Error: %s\n", err->line, err->message);
  interp->has_error = true;
}
