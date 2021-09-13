# TurtleGraphics

Simple GUI Application for drawing [Turtle Graphics](https://en.wikipedia.org/wiki/Turtle_graphics).

# Language

The general syntax is `<char>(<space>+<integer>)?` where char is used to identify the type of instruction which may take an optional argument. The instructions are

| Code          | Takes argument| Description     |
| ------------- |:-------------:| --------------- |
| U             |               | lift pen        |
| D             |               | lower pen       |
| N             | yes           | move pen up     |
| E             | yes           | move pen right  |
| S             | yes           | move pen down   |
| W             | yes           | move pen left   |
| A             | yes           | change angle    |

 # Requirements
 
 To build the project you need
  * C++17 compatible compiler
  * CMake 3.16.0+
  * Qt5
