#include "expression.h"
#include "rational.h"
#include "symbol_table.h"

#include <iostream>

using namespace Turtle;

Rational NumberExpression::evaluate(SymbolTable&)
{
    return number;
}

Rational VarExpression::evaluate(SymbolTable& table)
{
    tableEntry* search{table.lookup(identifier)};
    if (search != nullptr && !(search->isProcedure)) {
        return search->value;
    } else {
        std::cerr << "Error looking up variable '" << identifier << "'\n";
        exit(1);
    }
}

Rational PlusExpression::evaluate(SymbolTable& table)
{
    return leftOperand->evaluate(table) + rightOperand->evaluate(table); 
}

Rational MinusExpression::evaluate(SymbolTable& table)
{
    return leftOperand->evaluate(table) - rightOperand->evaluate(table); 
}

Rational MultExpression::evaluate(SymbolTable& table)
{
    return leftOperand->evaluate(table) * rightOperand->evaluate(table); 
}

Rational DivExpression::evaluate(SymbolTable& table)
{
    return leftOperand->evaluate(table) / rightOperand->evaluate(table); 
}
