#include "parse_table.h"
#include "lexer.h"

#include<list>

using namespace Grammar;

const std::list<Symbol> ParseTable::rules[] = {
    std::list<Symbol>{OPEN_CURLY_BRACKET, STMTS, CLOSED_CURLY_BRACKET},
    std::list<Symbol>{EXPR, BOOL_EXPR_LF},
    std::list<Symbol>{LESS_THAN, EXPR},
    std::list<Symbol>{EQUALITY, EXPR},
    std::list<Symbol>{FACTOR, TERM_LR, EXPR_LR},
    std::list<Symbol>{},
    std::list<Symbol>{PLUS, TERM, EXPR_LR},
    std::list<Symbol>{MINUS, TERM, EXPR_LR},
    std::list<Symbol>{EXPRS1},
    std::list<Symbol>{EXPR, EXPRS1_LF},
    std::list<Symbol>{COMMA, EXPRS1},
    std::list<Symbol>{OPEN_ROUND_BRACKET, EXPR, CLOSED_ROUND_BRACKET},
    std::list<Symbol>{DOLLAR_SIGN, IDENTIFIER},
    std::list<Symbol>{FUNCTION_EXPR},
    std::list<Symbol>{NUMBER},
    std::list<Symbol>{IDENTIFIER, OPEN_ROUND_BRACKET, EXPRS, CLOSED_ROUND_BRACKET},
    std::list<Symbol>{IDENTIFIER, IDS_LF},
    std::list<Symbol>{IDENTIFIER, IDS1_LF},
    std::list<Symbol>{COMMA, IDS1},
    std::list<Symbol>{BLOCK_STMT},
    std::list<Symbol>{DECLARE, IDS},
    std::list<Symbol>{FUNCTION, OPEN_ROUND_BRACKET, IDS, CLOSED_ROUND_BRACKET, BLOCK_STMT},
    std::list<Symbol>{IDENTIFIER, ASSIGNMENT, EXPR},
    std::list<Symbol>{IF, OPEN_ROUND_BRACKET, BOOL_EXPR, CLOSED_ROUND_BRACKET, BLOCK_STMT, ELSE, BLOCK_STMT},
    std::list<Symbol>{RETURN, EXPR},
    std::list<Symbol>{WHILE, OPEN_ROUND_BRACKET, BOOL_EXPR, CLOSED_ROUND_BRACKET, BLOCK_STMT},
    std::list<Symbol>{OPEN_ROUND_BRACKET, STMTS, CLOSED_ROUND_BRACKET},
    std::list<Symbol>{STMT, SEMICOLON, STMTS},
    std::list<Symbol>{FACTOR, TERM_LR},
    std::list<Symbol>{MULT, FACTOR, TERM_LR},
    std::list<Symbol>{DIV, FACTOR, TERM_LR},
};

const int ParseTable::table[NUMBER_OF_NONTERMINALS][NUMBER_OF_TERMINALS] = {
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1},
    {-1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 1, -1, 1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, 2, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 4, -1, -1, -1, 4, -1, 4, -1, -1, -1, -1},
    {-1, -1, 5, -1, 6, -1, 7, -1, 5, 5, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, 8, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8, -1, -1, -1, 8, -1, 8, -1, -1, -1, -1},
    {-1, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 9, -1, -1, -1, 9, -1, 9, -1, -1, -1, -1},
    {-1, -1, 5, -1, -1, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 12, -1, -1, -1, 13, -1, 14, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 15, -1, -1, -1, -1, -1, -1},
    {-1, -1, 5, -1, -1, -1, -1, -1, 5, -1, -1, -1, -1, -1, -1, -1, 16, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 17, -1, -1, -1, -1, -1, -1},
    {-1, -1, 5, -1, -1, 18, -1, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, 5, -1, -1,  18, -1, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 20, -1, 21, 22, 23, -1, 24, 25, 26, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 27, -1, 27, 27, 27, -1, 27, 27, 27, 5},
    {-1, 28, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 28, -1, -1, -1, 28, -1, 28, -1, -1, -1, -1},
    {-1, -1, 5, 29, -1, -1, -1, 30, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 12, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
};
