# Parser
Parsing is when a program analyzes symbols according to the rules of a grammar. In my case, my grammar currently only includes the basic arithmetic oparators and integer literals.

## Abstract Syntax Trees
Abstract syntax trees are a data structure that organizes expressions into their structure. 
### Nodes
AST's are organized into nodes, where each node of the tree holds important information about an expression. In my compiler, every node has a operation type, a left/right subtree and either the integer value (for literals) or the name of a variable.
~~~C
struct ASTnode {
  int op;
  struct ASTnode *left;
  struct ASTnode *right;
  union {
    int intvalue;
    int id;
  } v;
};
~~~
### Pratt Parsing
Parsing an AST is done using a recursive descent algorithm, where the parser starts at the root node of the tree and works it's way down. However, with no modifications, parsers will not be able to account for operator precedence. Pratt Parsing is a type of recursive descent parsing algorithm that is able to account for precendence. This is done by first assigning each operator a precedence. Then, while parsing, if the current operator's precedence is greater than the previous', continue recursive descent. Otherwise, return the left subtree.
### Variable Declaration
Variable declaration is handled using a global symbol table that is added to whenever a T_INT (integer variable token) is found by the parser. To assign a value to these variables, the parser looks for the T_IDENT (variable identifier token) and adds a value to the pre-existing entry in the symbol table.
### Print Call
Printing values is handled by the parser looking for T_PRINT tokens and generating an AST for the following expression.