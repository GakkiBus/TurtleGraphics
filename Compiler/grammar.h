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
        EQUALS,
        CALL,
        DECLARE,
        ELSE,
        IDENTIFIER,
        IF,
        NUMBER,
        PROCEDURE,
        WHILE,
        OPEN_CURLY_BRACKET,
        CLOSED_CURLY_BRACKET,
        BLOCK_STMT, //
        BOOL_EXPR,
        BOOL_EXPR_LF,
        EXPR,
        EXPR_LR,
        EXPRS,
        EXPRS1,
        EXPRS1_LF,
        EXPRS_LF,
        FACTOR,
        IDS,
        IDS1,
        IDS1_LF,
        IDS_LF,
        STMT,
        STMTS,
        TERM,
        TERM_LR,
    };

    inline constexpr int NUMBER_OF_TERMINALS{22};
    inline constexpr int NUMBER_OF_NONTERMINALS{18};
    bool isTerminal(Symbol symbol);
    int strToSymbol(const std::string& str);
}

#endif
