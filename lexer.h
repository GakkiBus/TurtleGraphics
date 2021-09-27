#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <sstream>

enum class TokenType
{
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    SEPARATOR,
    OPERATOR,

    UNKNOWN,
    EOS,
};

struct Token
{
    TokenType type;
    std::string value{};
};

class Lexer
{
public:
    Lexer(const std::string& input) : parseStream{std::istringstream{input}}, currToken{Token{TokenType::UNKNOWN}} {}
    Token peek();
    void next();

private:
    std::istringstream parseStream;
    Token currToken;

    Token tokenize();
    Token tokenizeNumber();
    Token tokenizeKeywordOrIdentifier();
    Token tokenizeOperatorOrSeparator();
};

#endif
