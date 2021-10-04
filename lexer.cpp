#include "lexer.h"

#include <sstream>
#include <string>
#include <iostream>

Lexer::Lexer(const std::string input)
{
    parseStream{std::istringstream{input}};
    tokenize();
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
    if (parseStream.eof()) { return Token{Symbol::EOS, true, ""}; }
    
    int c{parseStream.peek()};
    if (isdigit(c) || c == '%') {
        return tokenizeNumber();
    } else if (isalpha(c)) {
        return tokenizeKeywordOrIdentifier();
    } else if (ispunct(c)) {
        return tokenizeOperatorOrSeparator();
    } else {
        std::cerr << "Error: Encountered unknown sequence '" << c << "' while parsing input.\n" ;
        exit(1);
    }
}

Token Lexer::tokenizeNumber()
{
    std::string value{};
    bool beforDenominator{true};
    while (isdigit(parseStream.peek()) || (beforeDenominator && parseStream.peek() == '%')) {
        if (parseStream.peek() == '%') { beforeDenominator = false; }
        value += parseStream.get();
    }
    return Token{Symbol::NUMBER, true, value};
}

Token Lexer::tokenizeKeywordOrIdentifier()
{
    std::string value{};
    while (isalnum(parseStream.peek())) {
        value += parseStream.get();
    }

    switch (value)
    {
        case "if":
            return Token{Symbol::IF, ""};
        case "else":
            return Token{Symbol::ELSE, ""};
        case "while":
            return Token{Symbol::WHILE, ""};
        case "function":
            return Token{Symbol::FUNCTION, ""};
        case "return":
            return Token{Symbol::RETURN, ""};
        case "declare":
            return Token{Symbol::DECLARE, ""};
        default:
            return Token{Symbol::IDENTIFIER, value};
    }
}

Token Lexer::tokenizeOperatorOrSeparator()
{
    std::string value{};
    while (ispunct(parseStream.peek())) {
        value += parseStream.get();
    }
    
    switch (value)
    {
        case "=":
            return Token{Symbol::ASSIGNMENT, ""};
        case ",":
            return Token{Symbol::KOMMA, ""};
        case ";":
            return Token{Symbol::SEMICOLON, ""};
        case "(":
            return Token{Symbol::OPEN_ROUND_BRACKET, ""};
        case ")":
            return Token{Symbol::CLOSED_ROUD_BRACKET, ""};
        case "{":
            return Token{Symbol::OPEN_CURLY_BRACKET, ""};
        case "}":
            return Token{Symbol::CLOSED_CURLY_BRACKET, ""};
        case "==":
            return Token{Symbol::EQUALITY, ""};
        case "<":
            return Token{Symbol::LESS_THAN, ""};
        case "+":
            return Token{Symbol::PLUS, ""};
        case "-":
            return Token{Symbol::MINUS, ""};
        case "*":
            return Token{Symbol::MULT, ""};
        case "/":
            return Token{Symbol::DIV, ""};
        case "$":
            return Token{Symbol::DOLLAR_SIGN, ""};
        default:
            std::cerr << "Error: Encountered unknown sequence '" << value << "' while parsing input.\n" ;
            exit(1);
    }
}
