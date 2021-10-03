#include "turtlelang.h"

#include <iostream>
#include <string>
#include <string_view>

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
