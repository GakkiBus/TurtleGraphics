# ifndef PARSER_H
# define PARSER_H

#include <vector>
#include <string>

struct Action
{
    char code;
    int arg {0};
};

std::vector<Action> parseInput(std::string in);

# endif
