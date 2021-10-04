#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H

#include "lexer.h"

#include <list>

namespace ParseTable 
{
    extern const std::list<Grammar::Symbol> rules[];
    extern const int table[Grammar::NUMBER_OF_NONTERMINALS][Token::NUMBER_OF_TERMINALS];
}

#endif
