#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "scanner.h"
#include "token.h"

typedef struct {
  char *source_code;
  bool has_error;
  TokenList *tokens;
  Scanner *scanner;
} Interpreter;

#endif

// Lifecycle
void interpreter_init(Interpreter *interp);
void interpreter_free(Interpreter *interp);

// High-level run
void interpreter_run_file(Interpreter *interp, const char *path);
void interpreter_run_prompt(Interpreter *interp);
void interpreter_run_source(Interpreter *interp, const char *source);

// Internal pipeline steps
void interpreter_scan(Interpreter *interp);
void interpreter_parse(Interpreter *interp);
void interpreter_execute(Interpreter *interp);
