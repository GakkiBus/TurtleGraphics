#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <sstream>

enum class TokenType
{
    IDENTIFIER,
    NUMBER,
    SEMICOLON,
    OPEN_ROUND_BRACKET,
    CLOSED_ROUND_BRACKET,
    OPEN_CURLY_BRACKET,
    CLOSED_CURLY_BRACKET,
    FUNCTION,
    WHILE,
    IF,
    ELSE,
    RETURN,
    DECLARE,
    EQUALITY,
    LESS_THAN,
    MINUS,
    PLUS,
    MULT,
    DIV,
    ASSIGNMENT,
    KOMMA,

    EOS,
    UNKNOWN,

    // Tokens that will be added during parsing
    BLOCK_STMT,
    STMT,
    STMTS,
    EXPR,
    EXPRS,
    EXPRS1,
    P1,
    P2,
    P3,
    P4,
    IDS,
    IDS1,
};

struct Token
{
    TokenType type;
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
    Token tokenizeOperatorOrSeparator();
};

#endif
