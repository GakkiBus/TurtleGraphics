#ifndef TURTLELANG_H
#define TURTLELANG_H

#include <string>
#include <string_view>

enum class InstructionType
{
    HALT,
    RETURN,
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
    BLOCK_START,
    BLOCK_END,
};

struct Command
{
    InstructionType type;
    std::string_view code;
};

InstructionType lookupCode(const std::string& code);

bool isKeyword(const std::string& value);
bool isOperator(const std::string& value);
bool isSeparator(const std::string& value);

#endif
