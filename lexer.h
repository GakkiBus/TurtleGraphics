#ifndef LEXER_H
#define LEXER_H

#include "turtlelang.h"

#include <string>
#include <sstream>

struct Token
{
    Grammar::Symbol symbol;
    std::string value{};
};

class Lexer
{
public:
    Lexer(const std::string& input);
    Token peek();
    void next();

private:
    std::istringstream parseStream;
    Token currToken;

    Token tokenize();
    Token tokenizeNumber();
    Token tokenizeKeywordOrIdentifier();
    Token tokenizeSeparator();
    Token tokenizeOperator();
};

#endif
