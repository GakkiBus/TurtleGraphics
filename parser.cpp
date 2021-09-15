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
    return instructions;
}

/*
 * Statement ::= <space>*<char>(<space>+<integer>)?<space>*
 * where the char is used to identify the instruction 
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
        case PEN_UP:
        case PEN_DOWN:
            return parsePenInstruction(command.type, parseStream); 
        case MOVE_NORTH:
        case MOVE_EAST:
        case MOVE_SOUTH:
        case MOVE_WEST:
        case ROTATE:
            return parseMoveInstruction(command.type, parseStream);
    }
    exit(1);
}

static std::unique_ptr<Instruction> parsePenInstruction(InstructionType type, std::istringstream& parseStream)
{
    /* return std::unique_ptr<Instruction>(PenInstruction(type)); */
    return std::make_unique<PenInstruction>(type);
}

static std::unique_ptr<Instruction> parseMoveInstruction(InstructionType type, std::istringstream& parseStream)
{
   int unitsMoved{};
   parseStream >> unitsMoved;
   /* return std::unique_ptr<Instruction>(MoveInstruction(type, unitsMoved)); */
    return std::make_unique<MoveInstruction>(type, unitsMoved);
}
