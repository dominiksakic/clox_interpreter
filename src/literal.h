typedef enum {
  LITERAL_NONE,
  LITERAL_NUMBER,
  LITERAL_STRING
} LiteralType;

typedef struct {
  LiteralType type;
  union {
    double number;
    char* string;
  } as;
} Literal;
