#include <string>

struct Action
{
    void (*action)(int);
    int arg {0};
};

Action parseLine(std::string &statement);
