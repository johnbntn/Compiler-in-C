# Parser
Parsing is when a program analyzes symbols according to the rules of a grammar. In my case, my grammar currently only includes the basic arithmetic oparators and integer literals.
For my parser, a file containing:

`2 + 3 * 5 - 8 / 3 `

will output:
~~~
int 2
int 3
int 5
3 * 5
2 + 15
int 8
int 3
8 / 3
17 - 2
15
~~~
## Abstract Syntax Trees
### Nodes
## Pratt Parsing