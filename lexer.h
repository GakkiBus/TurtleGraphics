#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <sstream>

namespace TokenType
{
    enum TokenType
    {
        IDENTIFIER = 0,
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

        // Tokens that will be added during parsing
        BLOCK_STMT = 0,
        STMT,
        STMTS,
        EXPR,
        EXPR_LR,
        EXPRS,
        EXPRS1,
        EXPRS1_LF,
        P1,
        P1_LR,
        P2,
        P2_LR,
        P3,
        P3_LR,
        P4,
        PR_LF,
        IDS,
        IDS_LF,
        IDS1,
        IDS1_LF,
    };
}

struct Token
{
    TokenType type;
    bool isTerminal;
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
