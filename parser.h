# ifndef PARSER_H
# define PARSER_H

#include "instruction.h"

#include <string>
#include <sstream>
#include <memory>

std::shared_ptr<Instruction> parseInput(std::string in);

constexpr int variablePrefix{'$'};

# endif
