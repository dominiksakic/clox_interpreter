= Interpreter API

#heading(level: 2)[Capabilities]
The interpreter can provide the following information:

  - source_code → `string`
  - errors → `list<Error>`
  - tokens → `list<Token>`
  - ast → `AST` (abstract syntax tree)
  - scanner → `Scanner` (internal instance)
  - parser → `Parser` (internal instance)
  - execution_state → `Error` or `null`


#heading(level: 2)[Actions]
The interpreter can perform these actions:

  - read_from_cli() → reads user input from command line
  - read_file(path: `string`) → loads code from file
  - scan(source_code: `string`) → returns tokens
  - parse(tokens: `list<Token>`) → returns AST
  - execute(ast: `AST`) → runs program
  - run(source_code: `string`) → scan → parse → execute
  - report_error(error: `Error`) → prints formatted error message
