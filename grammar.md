# Grammar
In progress grammar for the language (not finalized).

**Warning** this is completely out of date. Will be rewritten when
  syntax and interpreter are more stable.

*written in pseudo BNF form*

```
ID             := [a-zA-Z_][a-zA-Z0-9_]+
PRIMARY        := FUNCTION | STRING | REAL | BOOLEAN | ARRAY | HASH | ID | NIL

BOOLEAN        := "true" | "false"
ARRAY          := "[" EXPRESSION* "]"
HASH           := "{" (STRING | ID ":" EXPRESSION)* "}"
NIL            := "nil"

FUNCTION       := "fn" ID? "(" (ID (":" ID)? )* ")" EXPRESSION

STRING         := "\"" [^"\n]* "\""
REAL           := [0-9]+(\.[0-9]+)?

LOOP           := "loop" EXPRESSION? "while" | "until" | "do" EXPRESSION

IF             := "if" EXPRESSION EXPRESSION ("elseif" EXPRESSION EXPRESSION)* ("else" EXPRESSION)?
WHEN           := "when" EXPRESSION EXPRESSION

CONDITIONAL    := ">" | "<" | ">=" | "<=" | "=" | "/="

CONDITIONALEXP := EXPRESSION CONDITIONAL EXPRESSION
BLOCK          := "(" EXPRESSION* ")"
ASSIGNMENT     := ID "<-" EXPRESSION

EXPRESSION     := PRIMARY | CONDITIONALEXP | LOOP | BLOCK | ASSIGNMENT

PROGRAM        := EXPRESSION* EOS
```
