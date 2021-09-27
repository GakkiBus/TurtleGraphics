#include "parser.h"
#include "turtlelang.h"
#include "instruction.h"

#include <list>
#include <string>
#include <sstream>
#include <memory>

#include <iostream>

static bool isVarname(const std::string& literal);
static std::shared_ptr<Instruction> parseInstruction(const std::string& parseString);
static std::shared_ptr<Instruction> parseHaltInstruction(InstructionType type, std::istringstream& parseStream);
static std::shared_ptr<Instruction> parseReturnInstruction(InstructionType type, std::istringstream&);
static std::shared_ptr<Instruction> parsePenInstruction(InstructionType type, std::istringstream& parseStream);
static std::shared_ptr<Instruction> parseMoveInstruction(InstructionType type, std::istringstream& parseStream);
static std::shared_ptr<Instruction> parseVarInstruction(InstructionType type, std::istringstream& parseStream);
static std::shared_ptr<Instruction> parseBlockInstruction(InstructionType type, std::istringstream& parseStream);

std::shared_ptr<Instruction> parseInput(std::string in)
{
    std::istringstream parseStream(in + "\n}");
    std::shared_ptr<Instruction> main{parseBlockInstruction(InstructionType::BLOCK_START, parseStream)};

    if (!parseStream.eof()) {
        std::cerr << "Unmatched closing brace\n"; 
        exit(1);
    }
    return main;
}

static std::shared_ptr<Instruction> parseInstruction(const std::string& parseString)
{
    std::istringstream parseStream(parseString);
    std::string code{};
    parseStream >> code;

    InstructionType type{lookupCode(code)};
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
        case InstructionType::BLOCK_START:
            return parseBlockInstruction(type, parseStream);
        case InstructionType::RETURN:
        case InstructionType::BLOCK_END:
            return parseReturnInstruction(type, parseStream);
        default:
            std::cerr << "Unknown instruction code ["<< code << "]\n"; 
            exit(1);
    }
}

static bool isVarname(const std::string& literal)
{
    return literal[0] == variablePrefix;
}

static std::shared_ptr<Instruction> parseHaltInstruction(InstructionType type, std::istringstream&)
{
    return std::make_shared<HaltInstruction>(type);
}

static std::shared_ptr<Instruction> parseReturnInstruction(InstructionType type, std::istringstream&)
{
    return std::make_shared<ReturnInstruction>(type);
}

static std::shared_ptr<Instruction> parsePenInstruction(InstructionType type, std::istringstream&)
{
    return std::make_shared<PenInstruction>(type);
}

static std::shared_ptr<Instruction> parseMoveInstruction(InstructionType type, std::istringstream& parseStream)
{
    std::string literal{};
    parseStream >> literal;
    if (isVarname(literal)) {
        return std::make_shared<MoveInstruction>(type, literal.substr(1));
    } else {
        return std::make_shared<MoveInstruction>(type, std::stoi(literal));
    }
}

static std::shared_ptr<Instruction> parseVarInstruction(InstructionType type, std::istringstream& parseStream)
{
    std::string varname{};
    parseStream >> varname;
    std::string literal{};
    parseStream >> literal;
    if (isVarname(literal)) {
        return std::make_shared<VarInstruction>(type, varname, literal.substr(1));
    } else {
        return std::make_shared<VarInstruction>(type, varname, std::stoi(literal));
    }
}


static std::shared_ptr<Instruction> parseBlockInstruction(InstructionType type, std::istringstream& parseStream)
{
    std::list<std::shared_ptr<Instruction>> body{};

    while (!parseStream.eof()) {
        std::string line{};
        getline(parseStream, line);
        std::cout << line << '\n';
        if (line.empty()) { 
            continue; 
        }

        std::shared_ptr<Instruction> instruction{parseInstruction(line)};
        body.push_back(instruction);
        if (instruction->getType() == InstructionType::BLOCK_END) {
            return std::make_shared<BlockInstruction>(type, body); 
        }
    }
    std::cerr << "Unmatched opening brace\n"; 
    exit(1);
}
