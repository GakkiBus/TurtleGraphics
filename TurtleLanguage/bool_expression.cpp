#include "bool_expression.h"
#include "expression.h"

#include <memory>

using namespace Turtle;

bool LessThanExpression::evaluate(const SymbolTable& table)
{
    return leftOperand->evaluate(table) < rightOperand->evaluate(table);
}

bool EqualsExpression::evaluate(const SymbolTable& table)
{
    return leftOperand->evaluate(table) == rightOperand->evaluate(table);
}
