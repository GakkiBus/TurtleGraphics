#ifndef BOOL_EXPRESSION_H
#define BOOL_EXPRESSION_H

#include "expression.h"
#include "rational.h"
#include "symbol_table.h"

#include <memory>

namespace Turtle
{
    class BoolExpression
    {
    public:
        virtual ~BoolExpression() = default;
        virtual bool evaluate(SymbolTable& table) = 0;
    };

    class LessThanExpression : public BoolExpression
    {
    private:
        std::shared_ptr<Expression> leftOperand;
        std::shared_ptr<Expression> rightOperand;

    public:
        LessThanExpression(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) 
            : leftOperand{l}, rightOperand{r} {}
        ~LessThanExpression() {};
        bool evaluate(SymbolTable& table);
    };

    class EqualsExpression : public BoolExpression
    {
    private:
        std::shared_ptr<Expression> leftOperand;
        std::shared_ptr<Expression> rightOperand;

    public:
        EqualsExpression(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) 
            : leftOperand{l}, rightOperand{r} {}
        ~EqualsExpression() {};
        bool evaluate(SymbolTable& table);
    };
}

#endif
