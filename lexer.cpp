#include "lexer.h"

#include <sstream>
#include <string>

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
    if (parseStream.eof()) { return Token{TokenType::EOS}; }
    
    int c{parseStream.peek()};
    if (isdigit(c) || c == '%') {
        return tokenizeNumber();
    } else if (isalpha(c)) {
        return tokenizeKeywordOrIdentifier();
    } else if (ispunct(c)) {
        return tokenizeOperatorOrSeparator();
    } else {
        return Token{TokenType::UNKNOWN};
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
    return Token{TokenType::NUMBER, value};
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
            return Token{TokenType::IF, ""};
        case "else":
            return Token{TokenType::ELSE, ""};
        case "while":
            return Token{TokenType::WHILE, ""};
        case "function":
            return Token{TokenType::FUNCTION, ""};
        case "return":
            return Token{TokenType::RETURN, ""};
        case "declare":
            return Token{TokenType::DECLARE, ""};
        default:
            return Token{TokenType::IDENTIFIER, value};
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
            return Token{TokenType::ASSIGNMENT, ""};
        case ",":
            return Token{TokenType::KOMMA, ""};
        case ";":
            return Token{TokenType::SEMICOLON, ""};
        case "(":
            return Token{TokenType::OPEN_ROUND_BRACKET, ""};
        case ")":
            return Token{TokenType::CLOSED_ROUD_BRACKET, ""};
        case "{":
            return Token{TokenType::OPEN_CURLY_BRACKET, ""};
        case "}":
            return Token{TokenType::CLOSED_CURLY_BRACKET, ""};
        case "==":
            return Token{TokenType::EQUALITY, ""};
        case "<":
            return Token{TokenType::LESS_THAN, ""};
        case "+":
            return Token{TokenType::PLUS, ""};
        case "-":
            return Token{TokenType::MINUS, ""};
        case "*":
            return Token{TokenType::MULT, ""};
        case "/":
            return Token{TokenType::DIV, ""};
        default:
            return Token{TokenType::UNKNOWN, value};
    }
}
