#include "parser.h"
#include "turtlelang.h"
#include "instruction.h"

#include <vector>
#include <string>
#include <sstream>
#include <memory>

std::vector<std::unique_ptr<Instruction>> parseInput(std::string in)
{
    std::vector<std::unique_ptr<Instruction>> instructions{};
    std::istringstream streamIn(in);
    while (!streamIn.eof()) {
        std::string line{};
        getline(streamIn, line);
        if (!line.empty())
            instructions.push_back(parseInstruction(line));
    }
    
    // insert HALT instruction as last statement
    instructions.push_back(std::make_unique<HaltInstruction>(HALT));
    return instructions;
}

/*
 * Statement ::= <space>*<string>(<space>+<integer>)?<space>*
 * where the string is used to identify the instruction
 * which may take a integers as arguments
 */
static std::unique_ptr<Instruction> parseInstruction(std::string parseString)
{
    std::istringstream parseStream(parseString);
    std::string code{};
    parseStream >> code;

    Command command{lookupCommand(code)};
    switch (command.type)
    {
        case HALT:
            return parseHaltInstruction(command.type, parseStream);
        case PEN_UP:
        case PEN_DOWN:
            return parsePenInstruction(command.type, parseStream); 
        case MOVE_NORTH:
        case MOVE_EAST:
        case MOVE_SOUTH:
        case MOVE_WEST:
        case ROTATE:
            return parseMoveInstruction(command.type, parseStream);
        case VAR_SET:
        case VAR_INC:
        case VAR_DEC:
            return parseVarInstruction(command.type, parseStream);
    }
    exit(1);
}

static bool isVarname(const std::string& literal)
{
    return literal[0] == variablePrefix;
}

static std::unique_ptr<Instruction> parseHaltInstruction(InstructionType type, std::istringstream& parseStream)
{
    return std::make_unique<HaltInstruction>(type);
}

static std::unique_ptr<Instruction> parsePenInstruction(InstructionType type, std::istringstream& parseStream)
{
    return std::make_unique<PenInstruction>(type);
}

static std::unique_ptr<Instruction> parseMoveInstruction(InstructionType type, std::istringstream& parseStream)
{
    std::string literal{};
    parseStream >> literal;
    if (isVarname(literal)) {
        return std::make_unique<MoveInstruction>(type, literal.substr(1));
    } else {
        return std::make_unique<MoveInstruction>(type, std::stoi(literal));
    }
}

static std::unique_ptr<Instruction> parseVarInstruction(InstructionType type, std::istringstream& parseStream)
{
    std::string varname{};
    parseStream >> varname;
    std::string literal{};
    parseStream >> literal;
    if (isVarname(literal)) {
        return std::make_unique<VarInstruction>(type, varname, literal.substr(1));
    } else {
        return std::make_unique<VarInstruction>(type, varname, std::stoi(literal));
    }
}
