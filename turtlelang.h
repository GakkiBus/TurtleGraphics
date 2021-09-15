#ifndef TURTLELANG_H
#define TURTLELANG_H

#include <string>

enum InstructionType
{
    PEN_UP,
    PEN_DOWN,
    MOVE_NORTH,
    MOVE_EAST,
    MOVE_SOUTH,
    MOVE_WEST,
    ROTATE,
};

struct Command
{
    InstructionType type;
    std::string code;
    bool takesArg;
};

Command lookupCommand(std::string code);

#endif
