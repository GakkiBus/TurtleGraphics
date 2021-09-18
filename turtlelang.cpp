#include "turtlelang.h"

#include <iostream>
#include <string>

Command commands[] = {
    Command{ HALT,          "HALT" },
    Command{ PEN_UP,        "U" },
    Command{ PEN_DOWN,      "D" },
    Command{ MOVE_NORTH,    "N" },
    Command{ MOVE_EAST,     "E" },
    Command{ MOVE_SOUTH,    "S" },
    Command{ MOVE_WEST,     "W" },
    Command{ ROTATE,        "R" },
    Command{ VAR_SET,       "SET" },
    Command{ VAR_INC,       "INC" },
    Command{ VAR_DEC,       "DEC" },
};

Command lookupCommand(std::string code)
{
    int size {(int) (sizeof(commands)/sizeof(Command))};
    for (Command command : commands)
    {
        if (command.code == code)
            return command;
    }
    
    std::cout << "Error looking up code [" << code << "]\n";
    exit(1);
}
