#ifndef ERROR_H
#define ERROR_H

#include "interpreter.h"

typedef struct {
  int line;
  char *message;
} Error;

void error_init(Error *err, int line, const char *message);
void error_free(Error *err);
void report(Interpreter *interp, const Error *err);

#endif
