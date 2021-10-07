#ifndef TURTLELANG_H
#define TURTLELANG_H

#include <string>
#include <string_view>

namespace Grammar 
{
    enum Symbol 
    {
        EOS,
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
        PROCEDURE,
        RETURN,
        WHILE,
        OPEN_CURLY_BRACKET,
        CLOSED_CURLY_BRACKET,

        BLOCK_STMT,
        BOOL_EXPR,
        BOOL_EXPR_LF,
        EXPR,
        EXPR_LR,
        EXPRS,
        EXPRS1,
        EXPRS1_LF,
        EXPRS_LF,
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

    inline constexpr int NUMBER_OF_TERMINALS{24};
    inline constexpr int NUMBER_OF_NONTERMINALS{21};
    bool isTerminal(Symbol symbol);
    int strToSymbol(const std::string& str);
}

#endif
