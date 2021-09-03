#include "turtlelang.h"

#include <iostream>

void penUp(int a);
void penDown(int a);
void moveNorth(int distance);
void moveEast(int distance);
void moveSouth(int distance);
void moveWest(int distance);

const Command commands[] = {
    Command{ PEN_UP, 'U', false, &penUp },
    Command{ PEN_DOWN, 'D', false, &penDown },
    Command{ MOVE_NORTH, 'N', true, &moveNorth },
    Command{ MOVE_EAST, 'E', true, &moveEast },
    Command{ MOVE_SOUTH, 'S', true, &moveSouth },
    Command{ MOVE_WEST, 'W', true, &moveWest },
};

Command lookupCmd(char code)
{
    int size {(int) (sizeof(commands)/sizeof(Command))};
    for (int i {0}; i < size; i++) {
	if (commands[i].code == code) {
	    return commands[i];
	}
    }
    
    std::cout << "Error looking up code [" << code << "]\n";
    exit(1);
}
    
void penUp(int x)
{
    std::cout << "Lifted pen\n";
}

void penDown(int x)
{
    std::cout << "Lowered pen\n";
}

void moveNorth(int distance)
{
    std::cout << "Moved pen north (" << distance << ")\n";
}

void moveEast(int distance)
{
    std::cout << "Moved pen east (" << distance << ")\n";
}

void moveSouth(int distance)
{
    std::cout << "Moved pen south (" << distance << ")\n";
}

void moveWest(int distance)
{
    std::cout << "Moved pen west (" << distance << ")\n";
}
