#include "lexer.h"
#include "turtlelang.h"

#include <sstream>

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
    if (isdigit(c)) {
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
    bool beforePoint{true};
    while (isdigit(parseStream.peek()) || (parseStream.peek() == '.' && beforePoint)) {
        if (parseStream.peek() == '.') { beforePoint = false; }
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
    return Token{isKeyword(value) ? TokenType::KEYWORD : TokenType::IDENTIFIER, value};
}

Token Lexer::tokenizeOperatorOrSeparator()
{
    std::string value{};
    while (ispunct(parseStream.peek())) {
        value += parseStream.get();
    }
    if (isOperator(value)) {
        return Token{TokenType::OPERATOR, value};
    } else if (isSeparator(value)) {
        return Token{TokenType::SEPARATOR, value};
    } else {
        return Token{TokenType::UNKNOWN, value};
    }
}
