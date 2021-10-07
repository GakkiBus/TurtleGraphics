#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H

#include "grammar.h"

#include <list>

namespace ParseTable 
{
    extern const std::list<Grammar::Symbol> rules[];
    int getEntry(Grammar::Symbol A, Grammar::Symbol a);
}

#endif
