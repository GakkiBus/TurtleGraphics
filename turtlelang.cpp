#include "turtlelang.h"

#include <iostream>
#include <string>

Command commands[] = {
    Command{ PEN_UP,        "U" },
    Command{ PEN_DOWN,      "D" },
    Command{ MOVE_NORTH,    "N" },
    Command{ MOVE_EAST,     "E" },
    Command{ MOVE_SOUTH,    "S" },
    Command{ MOVE_WEST,     "W" },
    Command{ ROTATE,        "R" },
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
