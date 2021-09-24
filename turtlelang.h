#ifndef TURTLELANG_H
#define TURTLELANG_H

#include <string>

enum class InstructionType
{
    HALT,
    PEN_UP,
    PEN_DOWN,
    MOVE_NORTH,
    MOVE_EAST,
    MOVE_SOUTH,
    MOVE_WEST,
    ROTATE,
    VAR_SET,
    VAR_INC,
    VAR_DEC,
};

struct Command
{
    InstructionType type;
    std::string code;
};

InstructionType lookupCommand(const std::string& code);

#endif
