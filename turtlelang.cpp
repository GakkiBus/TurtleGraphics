#include "turtlelang.h"

#include <iostream>
#include <string>

Command commands[] = {
    Command{ InstructionType::HALT,          "HALT" },
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
};

InstructionType lookupCommand(const std::string& code)
{
    for (Command command : commands)
    {
        if (command.code == code)
            return command.type;
    }
    
    std::cout << "Error looking up code [" << code << "]\n";
    exit(1);
}
