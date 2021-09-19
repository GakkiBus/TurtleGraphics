# ifndef PARSER_H
# define PARSER_H

#include "instruction.h"

#include <vector>
#include <string>
#include <sstream>

std::vector<std::unique_ptr<Instruction>> parseInput(std::string in);

constexpr int variablePrefix{'$'};


# endif
