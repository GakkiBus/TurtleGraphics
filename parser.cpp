#include "parser.h"

#include <vector>
#include <string>
#include <sstream>

Action parseLine(std::string line);

std::vector<Action> parseInput(std::string in)
{
    std::vector<Action> actions{};
    std::istringstream streamIn(in);
    while (!streamIn.eof()) {
        std::string line{};
        getline(streamIn, line);
        if (!line.empty())
            actions.push_back(parseLine(line));
    }
    return actions;
}

/*
 * Statement ::= <space>*<char>(<space>+<integer>)?<space>*
 * where the char is used to identify the instruction 
 * which may take a integers as arguments
 */
Action parseLine(std::string line)
{
    std::stringstream streamLine(line);
    char code{};
    streamLine >> code;
    int arg{};
    streamLine >> arg;
    Action action{code, arg};
    return action;
}
