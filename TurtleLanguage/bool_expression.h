#ifndef BOOL_EXPRESSION_H
#define BOOL_EXPRESSION_H

#include "expression.h"
#include "rational.h"
#include "symbol_table.h"

#include <string>
#include <memory>

namespace Turtle
{
    class BoolExpression
    {
    public:
        virtual ~BoolExpression() = default;
        virtual bool evaluate(SymbolTable table) = 0;
    };

    class LessThanExpression : public BoolExpression
    {
    private:
        std::unique_ptr<Expression> leftOperand;
        std::unique_ptr<Expression> rightOperand;

    public:
        LessThanExpression(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r) 
            : leftOperand{std::move(l)}, rightOperand{std::move(r)} {}
        ~LessThanExpression() {};
        bool evaluate(const SymbolTable& table);
    };

    class EqualsExpression : public BoolExpression
    {
    private:
        std::unique_ptr<Expression> leftOperand;
        std::unique_ptr<Expression> rightOperand;

    public:
        EqualsExpression(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r) 
            : leftOperand{std::move(l)}, rightOperand{std::move(r)} {}
        ~EqualsExpression() {};
        bool evaluate(const SymbolTable& table);
    };
}

#endif
