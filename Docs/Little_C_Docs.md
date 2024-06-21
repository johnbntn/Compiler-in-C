# Little C
This is the language documentation for Little C, outlining its regular expressions.
```
 statements: statement*

 statement: 'print' expression ';'
    | 'int'   identifier ';'
    | identifier '=' expression ';'

 identifier: T_IDENT

expression: number
    | expression '*' expression
    | expression '/' expression
    | expression '+' expression
    | expression '-' expression

number:  T_INTLIT
```
T_INTLIT: [0-9]*

T_IDENT: Variable name