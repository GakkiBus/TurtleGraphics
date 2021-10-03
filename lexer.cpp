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
    if (parseStream.eof()) { return Token{TokenType::EOS, true, ""}; }
    
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
    return Token{TokenType::NUMBER, true, value};
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
            return Token{TokenType::IF, true, ""};
        case "else":
            return Token{TokenType::ELSE, true, ""};
        case "while":
            return Token{TokenType::WHILE, true, ""};
        case "function":
            return Token{TokenType::FUNCTION, true, ""};
        case "return":
            return Token{TokenType::RETURN, true, ""};
        case "declare":
            return Token{TokenType::DECLARE, true, ""};
        default:
            return Token{TokenType::IDENTIFIER, true, value};
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
            return Token{TokenType::ASSIGNMENT, true, ""};
        case ",":
            return Token{TokenType::KOMMA, true, ""};
        case ";":
            return Token{TokenType::SEMICOLON, true, ""};
        case "(":
            return Token{TokenType::OPEN_ROUND_BRACKET, true, ""};
        case ")":
            return Token{TokenType::CLOSED_ROUD_BRACKET, true, ""};
        case "{":
            return Token{TokenType::OPEN_CURLY_BRACKET, true, ""};
        case "}":
            return Token{TokenType::CLOSED_CURLY_BRACKET, true, ""};
        case "==":
            return Token{TokenType::EQUALITY, true, ""};
        case "<":
            return Token{TokenType::LESS_THAN, true, ""};
        case "+":
            return Token{TokenType::PLUS, true, ""};
        case "-":
            return Token{TokenType::MINUS, true, ""};
        case "*":
            return Token{TokenType::MULT, true, ""};
        case "/":
            return Token{TokenType::DIV, true, ""};
        default:
            std::cerr << "Error: Encountered unknown sequence '" << value << "' while parsing input.\n" ;
            exit(1);
    }
}
