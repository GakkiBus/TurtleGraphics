# ifndef PARSER_H
# define PARSER_H

#include "instruction.h"

#include <list>
#include <string>
#include <sstream>

std::list<std::unique_ptr<Instruction>> parseInput(std::string in);

constexpr int variablePrefix{'$'};

# endif
