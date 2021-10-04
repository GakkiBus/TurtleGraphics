#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <sstream>

namespace Grammar 
{
    enum Symbol 
    {
        EOS = 0,
        OPEN_ROUND_BRACKET,
        CLOSED_ROUND_BRACKET,
        MULT,
        PLUS,
        COMMA,
        MINUS,
        DIV,
        SEMICOLON,
        LESS_THAN,
        ASSIGNMENT,
        EQUALITY,
        DOLLAR_SIGN,
        DECLARE,
        ELSE,
        FUNCTION,
        IDENTIFIER,
        IF,
        NUMBER,
        RETURN,
        WHILE,
        OPEN_CURLY_BRACKET,
        CLOSED_CURLY_BRACKET,

        BLOCK_STMT = 0,
        BOOL_EXPR,
        BOOL_EXPR_LF,
        EXPR,
        EXPR_LR,
        EXPRS,
        EXPRS1,
        EXPRS1_LF,
        FACTOR,
        FUNCTION_EXPR,
        IDS,
        IDS1,
        IDS1_LF,
        IDS_LF,
        PROGRAM,
        STMT,
        STMTS,
        TERM,
        TERM_LR,
        VAR_EXPR,
    };

    inline constexpr int NUMBER_OF_TERMINALS{23};
    inline constexpr int NUMBER_OF_NONTERMINALS{20};
}

struct Token
{
    Grammar::Symbol type;
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
