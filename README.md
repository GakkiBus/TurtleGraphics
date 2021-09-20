# TurtleGraphics

A simple GUI Application for drawing [turtle graphics](https://en.wikipedia.org/wiki/Turtle_graphics).

# Language

Drawing is done by specifying movement instructions on a pen which are written in a textbox. More precisely, instruction are separated by new lines and consist of an identifier and zero or more arguments. 

### Syntax
```
<instruction> ::= <halt-instruction> | <pen-instruction> | <move-instruction> | <var-instruction>

<halt-instruction> ::= <halt-identifier>
<halt-identifier> ::= HALT

<pen-instruction> ::= <pen-identifier>
<pen-identifier> ::= D | U

<move-instruction> ::= <move-identifier> <literal>
<move-identifier> ::= N | E | S | W | R

<var-instruction> ::= <var-identifier> <varname> <literal>
<var-identifier> ::= SET | INC | DEC
<varname> ::= <non-empty string>

<literal> ::= $<non-empty string> | <integer>
```

### Semantics
| Identifier    | Description                 |
| :-----------: | :-------------------------- |
| U             | lift pen                    |
| D             | lower pen                   |
| N             | move pen up                 |
| E             | move pen right              |
| S             | move pen down               |
| W             | move pen left               |
| R             | change angle                |
| SET           | set value of variable       |
| INC           | increment value of variable |
| DEC           | decrement value of variable |

 # Building
 
 To build the project you need
  * C++17 compatible compiler
  * CMake 3.16.0+
  * Qt5
