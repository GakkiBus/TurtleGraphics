#ifndef TURTLELANG_H
#define TURTLELANG_H

enum InstructionType
{
    PEN_UP,
    PEN_DOWN,
    MOVE_NORTH,
    MOVE_EAST,
    MOVE_SOUTH,
    MOVE_WEST,
    SET_ANGLE,
};

struct Command
{
    InstructionType type;
    char code;
    bool takesArg;
};

Command lookupCommand(char code);

#endif
