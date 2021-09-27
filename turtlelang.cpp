#include "turtlelang.h"

#include <iostream>
#include <string>
#include <string_view>
#include <set>

constexpr Command commands[] = {
    Command{ InstructionType::HALT,          "HALT" },
    Command{ InstructionType::RETURN,        "RETURN" },
    Command{ InstructionType::PEN_UP,        "U" },
    Command{ InstructionType::PEN_DOWN,      "D" },
    Command{ InstructionType::MOVE_NORTH,    "N" },
    Command{ InstructionType::MOVE_EAST,     "E" },
    Command{ InstructionType::MOVE_SOUTH,    "S" },
    Command{ InstructionType::MOVE_WEST,     "W" },
    Command{ InstructionType::ROTATE,        "R" },
    Command{ InstructionType::VAR_SET,       "SET" },
    Command{ InstructionType::VAR_INC,       "INC" },
    Command{ InstructionType::VAR_DEC,       "DEC" },
    Command{ InstructionType::BLOCK_START,   "{" },
    Command{ InstructionType::BLOCK_END,     "}" },
};

std::set<std::string_view> keywords {
    "HALT", "RETURN", "FOR", "IF"
};

std::set<std::string_view> operators {
    "=", "+", "-", "*", "/"
};

std::set<std::string_view> separators {
    "{", "}", "(", ")", ","
};

InstructionType lookupCode(const std::string& code)
{
    for (Command command : commands)
    {
        if (command.code == code)
            return command.type;
    }
    
    std::cout << "Error looking up code [" << code << "]\n";
    exit(1);
}

bool isKeyword(const std::string& value)
{
    return keywords.find(value) != keywords.end();
}

bool isOperator(const std::string& value)
{
    return operators.find(value) != operators.end();
}

bool isSeparator(const std::string& value)
{
    return separators.find(value) != separators.end();
}
