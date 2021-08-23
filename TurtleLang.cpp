#include <iostream>

struct Command
{
    int cmd;
    bool hasArgs;
    void (*action)(int);
};

Command commands[] = {
    Command{ "U", false, &penUp },
    Command{ "D", false, &penDown },
    Command{ "N", true, &moveNorth },
    Command{ "E", true, &moveEast },
    Command{ "S", true, &moveSouth },
    Command{ "W", true, &moveSouth },
}

int penUp(int a) {
    std::cout << "Lifted pen\n";
}

int penDown(int a) {
    std::cout << "Lowered pen\n";
}

int moveNorth(int distance) {
    std::cout << "Moved pen north (" << distance << ")\n";
}

int moveEast(int distance) {
    std::cout << "Moved pen east (" << distance << ")\n";
}

int moveSouth(int distance) {
    std::cout << "Moved pen south (" << distance << ")\n";
}

int moveWest(int distance) {
    std::cout << "Moved pen west (" << distance << ")\n";
}
