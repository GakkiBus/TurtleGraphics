#include "lexer.h"
#include "turtlelang.h"

#include <sstream>
#include <string>
#include <iostream>
#include <map>

static bool isSep(char c);

Lexer::Lexer(const std::string& input)
{
    parseStream = std::istringstream{input};
    next();
}

Token Lexer::peek()
{
    return currToken;
}

void Lexer::next()
{
    currToken = tokenize();
}

Token Lexer::tokenize()
{
    parseStream >> std::ws;
    if (parseStream.eof()) { return Token{Grammar::EOS, ""}; }
    
    int c{parseStream.peek()};
    if (isdigit(c) || c == '%') {
        return tokenizeNumber();
    } else if (isalpha(c)) {
        return tokenizeKeywordOrIdentifier();
    } else if (isSep(c)) {
        return tokenizeSeparator();
    } else if (ispunct(c)) {
        return tokenizeOperator();
    } else {
        std::cerr << "Error: Encountered unknown sequence '" << c << "' while parsing input.\n" ;
        exit(1);
    }
}

Token Lexer::tokenizeNumber()
{
    std::string value{};
    bool beforeDenominator{true};
    while (isdigit(parseStream.peek()) || (beforeDenominator && parseStream.peek() == '%')) {
        if (parseStream.peek() == '%') { beforeDenominator = false; }
        value += parseStream.get();
    }
    return Token{Grammar::NUMBER, value};
}

Token Lexer::tokenizeKeywordOrIdentifier()
{
    std::string value{};
    while (isalnum(parseStream.peek())) {
        value += parseStream.get();
    }

    int search{Grammar::strToSymbol(value)};
    if (search != -1) {
        return Token{static_cast<Grammar::Symbol>(search)};
    } else {
        return Token{Grammar::IDENTIFIER, value};
    }
}

Token Lexer::tokenizeSeparator()
{
    std::string value{};
    value += parseStream.get();

    int search{Grammar::strToSymbol(value)};
    if (search != -1) {
        return Token{static_cast<Grammar::Symbol>(search)};
    } else {
        std::cerr << "Error: Encountered unknown sequence '" << value << "' while parsing input.\n" ;
        exit(1);
    }
}

Token Lexer::tokenizeOperator()
{
    std::string value{};
    while (ispunct(parseStream.peek())) {
        value += parseStream.get();
    }
    
    int search{Grammar::strToSymbol(value)};
    if (search != -1) {
        return Token{static_cast<Grammar::Symbol>(search)};
    } else {
        std::cerr << "Error: Encountered unknown sequence '" << value << "' while parsing input.\n" ;
        exit(1);
    }
}

static bool isSep(char c)
{
    return c == '(' || c == ')' || c == '{' || c == '}' || c == ';' || c == ',';
}
