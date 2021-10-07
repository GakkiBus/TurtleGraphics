#include "parse_table.h"
#include "grammar.h"

#include<list>

using namespace Grammar;

static const int table[NUMBER_OF_NONTERMINALS][NUMBER_OF_TERMINALS] = {
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1},
    {-1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 1, -1, 1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, 2, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 4, -1, -1, -1, 4, -1, 4, -1, -1, -1, -1, -1},
    {-1, -1, 5, -1, 6, 5, 7, -1, 5, 5, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, 8, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8, -1, -1, -1, 8, -1, 8, -1, -1, -1, -1, -1},
    {-1, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 9, -1, -1, -1, 9, -1, 9, -1, -1, -1, -1, -1},
    {-1, -1, 5, -1, -1, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, 5, -1, -1, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 12, -1, -1, -1, 13, -1, 14, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 13, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, 5, -1, -1, -1, -1, -1, 5, -1, -1, -1, -1, -1, -1, -1, 15, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 16, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, 5, -1, -1, 17, -1, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, 5, -1, -1, 17, -1, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 18, -1, 19, 20, 21, -1, 22, 23, 24, 0, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 25, -1, 25, 25, 25, -1, 25, 25, 25, 25, 5},
    {-1, 26, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 26, -1, -1, -1, 26, -1, 26, -1, -1, -1, -1, -1},
    {-1, -1, 5, 27, 5, 5, 5, 28, 5, 5, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
};

int ParseTable::getEntry(Symbol A, Symbol a)
{
    return table[A - NUMBER_OF_TERMINALS][a];
}

const std::list<Symbol> ParseTable::rules[] = {
    std::list<Symbol>{OPEN_CURLY_BRACKET, STMTS, CLOSED_CURLY_BRACKET},
    std::list<Symbol>{TERM, EXPR_LR, BOOL_EXPR_LF},
    std::list<Symbol>{LESS_THAN, EXPR},
    std::list<Symbol>{EQUALITY, EXPR},
    std::list<Symbol>{TERM, EXPR_LR},
    std::list<Symbol>{},
    std::list<Symbol>{PLUS, TERM, EXPR_LR},
    std::list<Symbol>{MINUS, TERM, EXPR_LR},
    std::list<Symbol>{TERM, EXPR_LR, EXPRS_LF},
    std::list<Symbol>{TERM, EXPR_LR, EXPRS1_LF},
    std::list<Symbol>{COMMA, EXPRS1},
    std::list<Symbol>{OPEN_ROUND_BRACKET, EXPR, CLOSED_ROUND_BRACKET},
    std::list<Symbol>{VAR_EXPR},
    std::list<Symbol>{IDENTIFIER, OPEN_ROUND_BRACKET, EXPRS, CLOSED_ROUND_BRACKET},
    std::list<Symbol>{NUMBER},
    std::list<Symbol>{IDENTIFIER, IDS_LF},
    std::list<Symbol>{IDENTIFIER, IDS1_LF},
    std::list<Symbol>{COMMA, IDS1},
    std::list<Symbol>{DECLARE, IDS, SEMICOLON},
    std::list<Symbol>{FUNCTION, OPEN_ROUND_BRACKET, IDS, CLOSED_ROUND_BRACKET, BLOCK_STMT},
    std::list<Symbol>{IDENTIFIER, ASSIGNMENT, EXPR, SEMICOLON},
    std::list<Symbol>{IF, OPEN_ROUND_BRACKET, BOOL_EXPR, CLOSED_ROUND_BRACKET, BLOCK_STMT, ELSE, BLOCK_STMT},
    std::list<Symbol>{PROCEDURE, FUNCTION_EXPR, SEMICOLON},
    std::list<Symbol>{RETURN, EXPR, SEMICOLON},
    std::list<Symbol>{WHILE, OPEN_ROUND_BRACKET, BOOL_EXPR, CLOSED_ROUND_BRACKET, BLOCK_STMT},
    std::list<Symbol>{STMT, STMTS},
    std::list<Symbol>{FACTOR, TERM_LR},
    std::list<Symbol>{MULT, FACTOR, TERM_LR},
    std::list<Symbol>{DIV, FACTOR, TERM_LR},
    std::list<Symbol>{DOLLAR_SIGN, IDENTIFIER}
};

