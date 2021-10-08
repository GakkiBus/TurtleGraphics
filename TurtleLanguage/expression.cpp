#include "expression.h"
#include "rational.h"

using namespace Turtle;

Rational NumberExpression::evaluate(const SymbolTable&)
{
    return number;
}

Rational VarExpression::evaluate(const SymbolTable& table)
{
    /* return table.lookup(identifier); */
    return Rational(0, 1);
}

Rational PlusExpression::evaluate(const SymbolTable& table)
{
    return leftOperand->evaluate(table) + rightOperand->evaluate(table); 
}

Rational MinusExpression::evaluate(const SymbolTable& table)
{
    return leftOperand->evaluate(table) - rightOperand->evaluate(table); 
}

Rational MultExpression::evaluate(const SymbolTable& table)
{
    return leftOperand->evaluate(table) * rightOperand->evaluate(table); 
}

Rational DivExpression::evaluate(const SymbolTable& table)
{
    return leftOperand->evaluate(table) / rightOperand->evaluate(table); 
}
