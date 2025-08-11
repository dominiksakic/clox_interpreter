typedef struct {
  char *source_code;
  char *errors;
  char *tokens;
  scanner *scanner;
  char *execution_state;
} Interpreter;
