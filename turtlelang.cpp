#include "turtlelang.h"

#include <iostream>
#include <string>

Command commands[] = {
    Command{ PEN_UP,        "U",    false },
    Command{ PEN_DOWN,      "D",    false },
    Command{ MOVE_NORTH,    "N",    true },
    Command{ MOVE_EAST,     "E",    true },
    Command{ MOVE_SOUTH,    "S",    true },
    Command{ MOVE_WEST,     "W",    true },
    Command{ ROTATE,        "R",    true },
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
