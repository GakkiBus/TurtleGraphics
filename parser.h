# ifndef PARSER_H
# define PARSER_H

#include "instruction.h"

#include <vector>
#include <string>
#include <sstream>

std::vector<std::unique_ptr<Instruction>> parseInput(std::string in);

constexpr int variablePrefix{'$'};

static std::unique_ptr<Instruction> parseInstruction(std::string parseString);
static std::unique_ptr<Instruction> parseHaltInstruction(InstructionType type, std::istringstream& parseStream);
static std::unique_ptr<Instruction> parsePenInstruction(InstructionType type, std::istringstream& parseStream);
static std::unique_ptr<Instruction> parseMoveInstruction(InstructionType type, std::istringstream& parseStream);
static std::unique_ptr<Instruction> parseVarInstruction(InstructionType type, std::istringstream& parseStream);

# endif
