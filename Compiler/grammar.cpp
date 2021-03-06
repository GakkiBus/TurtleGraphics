#include "grammar.h"

#include <iostream>
#include <string>
#include <string_view>
#include <map>

using namespace Grammar;

bool Grammar::isTerminal(Symbol symbol)
{
    return symbol < NUMBER_OF_TERMINALS;
}

const static std::map<std::string_view, Symbol> symbols {
    {"if", IF}, {"else", ELSE}, {"while", WHILE}, {"procedure", PROCEDURE},
    {"call", CALL}, {"declare", DECLARE}, {"=", ASSIGNMENT}, {",", COMMA}, {";", SEMICOLON},
    {"(", OPEN_ROUND_BRACKET}, {")", CLOSED_ROUND_BRACKET}, {"{", OPEN_CURLY_BRACKET},
    {"}", CLOSED_CURLY_BRACKET}, {"==", EQUALS}, {"<", LESS_THAN},
    {"+", PLUS}, {"-", MINUS}, {"*", MULT}, {"/", DIV}
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
