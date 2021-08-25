#ifndef TURTLE_LANG_H
#define TURTLE_LANG_H

enum Instruction
{
    PEN_UP,
    PEN_DOWN,
    MOVE_NORTH,
    MOVE_EAST,
    MOVE_SOUTH,
    MOVE_WEST,
};

struct Command
{
    Instruction instruction;
    char code;
    bool takesArgs;
    void (*action)(int);
};

Command lookupCmd(char code);

#endif
