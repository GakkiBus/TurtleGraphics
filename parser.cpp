#include "parser.h"
#include "turtlelang.h"
#include "instruction.h"

#include <list>
#include <string>
#include <sstream>
#include <memory>

static bool isVarname(const std::string& literal);
static std::unique_ptr<Instruction> parseInstruction(const std::string& parseString);
static std::unique_ptr<Instruction> parseHaltInstruction(InstructionType type, std::istringstream& parseStream);
static std::unique_ptr<Instruction> parsePenInstruction(InstructionType type, std::istringstream& parseStream);
static std::unique_ptr<Instruction> parseMoveInstruction(InstructionType type, std::istringstream& parseStream);
static std::unique_ptr<Instruction> parseVarInstruction(InstructionType type, std::istringstream& parseStream);

std::list<std::unique_ptr<Instruction>> parseInput(std::string in)
{
    std::list<std::unique_ptr<Instruction>> instructions{};
    std::istringstream streamIn(in);
    while (!streamIn.eof()) {
        std::string line{};
        getline(streamIn, line);
        if (!line.empty())
            instructions.push_back(parseInstruction(line));
    }
    
    // insert HALT instruction as last statement
    instructions.push_back(std::make_unique<HaltInstruction>(InstructionType::HALT));
    return instructions;
}

static std::unique_ptr<Instruction> parseInstruction(const std::string& parseString)
{
    std::istringstream parseStream(parseString);
    std::string code{};
    parseStream >> code;

    InstructionType type{lookupCommand(code)};
    switch (type)
    {
        case InstructionType::HALT:
            return parseHaltInstruction(type, parseStream);
        case InstructionType::PEN_UP:
        case InstructionType::PEN_DOWN:
            return parsePenInstruction(type, parseStream); 
        case InstructionType::MOVE_NORTH:
        case InstructionType::MOVE_EAST:
        case InstructionType::MOVE_SOUTH:
        case InstructionType::MOVE_WEST:
        case InstructionType::ROTATE:
            return parseMoveInstruction(type, parseStream);
        case InstructionType::VAR_SET:
        case InstructionType::VAR_INC:
        case InstructionType::VAR_DEC:
            return parseVarInstruction(type, parseStream);
    }
    exit(1);
}

static bool isVarname(const std::string& literal)
{
    return literal[0] == variablePrefix;
}

static std::unique_ptr<Instruction> parseHaltInstruction(InstructionType type, std::istringstream&)
{
    return std::make_unique<HaltInstruction>(type);
}

static std::unique_ptr<Instruction> parsePenInstruction(InstructionType type, std::istringstream&)
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
