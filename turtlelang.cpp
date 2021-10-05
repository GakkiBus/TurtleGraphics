#include "turtlelang.h"

#include <iostream>
#include <string>
#include <string_view>
#include <map>

using namespace Grammar;

constexpr Command commands[] = {
    Command{ InstructionType::HALT,          "HALT" },
    Command{ InstructionType::RETURN,        "RETURN" },
    Command{ InstructionType::PEN_UP,        "U" },
    Command{ InstructionType::PEN_DOWN,      "D" },
    Command{ InstructionType::MOVE_NORTH,    "N" },
    Command{ InstructionType::MOVE_EAST,     "E" },
    Command{ InstructionType::MOVE_SOUTH,    "S" },
    Command{ InstructionType::MOVE_WEST,     "W" },
    Command{ InstructionType::ROTATE,        "R" },
    Command{ InstructionType::VAR_SET,       "SET" },
    Command{ InstructionType::VAR_INC,       "INC" },
    Command{ InstructionType::VAR_DEC,       "DEC" },
    Command{ InstructionType::BLOCK_START,   "{" },
    Command{ InstructionType::BLOCK_END,     "}" },
};

InstructionType lookupCode(const std::string& code)
{
    for (Command command : commands)
    {
        if (command.code == code)
            return command.type;
    }
    
    std::cout << "Error looking up code [" << code << "]\n";
    exit(1);
}

bool Grammar::isTerminal(Symbol symbol)
{
    return symbol < NUMBER_OF_TERMINALS;
}

const static std::map<std::string, Symbol> symbols {
    {"if", IF}, {"else", ELSE}, {"while", WHILE}, {"procedure", PROCEDURE},
    {"function", FUNCTION}, {"return", RETURN}, {"declare", DECLARE},
    {"=", ASSIGNMENT}, {",", COMMA}, {";", SEMICOLON},
    {"(", OPEN_ROUND_BRACKET}, {")", CLOSED_ROUND_BRACKET}, {"{", OPEN_CURLY_BRACKET},
    {"}", CLOSED_CURLY_BRACKET}, {"==", EQUALITY}, {"<", LESS_THAN},
    {"+", PLUS}, {"-", MINUS}, {"*", MULT}, {"/", DIV}, {"$", DOLLAR_SIGN}
};

int Grammar::strToSymbol(const std::string& str)
{
    auto search{symbols.find(str)};
    if (search != symbols.end()) {
        return search->second;
    } else {
        return -1;
    }
}
