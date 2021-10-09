#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "rational.h"
#include "symbol_table.h"

#include <string>
#include <memory>

namespace Turtle
{
    class Expression
    {
    public:
        virtual ~Expression() = default;
        virtual Rational evaluate(SymbolTable& table) = 0;
    };

    class NumberExpression : public Expression
    {
    private:
        const Rational number;

    public:
        NumberExpression(const Rational& n) : number{n} {}
        ~NumberExpression() {};
        Rational evaluate(SymbolTable& table);
    };

    class VarExpression : public Expression
    {
    private:
        const std::string identifier;

    public:
        VarExpression(const std::string& id) : identifier{id} {}
        ~VarExpression() {};
        Rational evaluate(SymbolTable& table);
    };

    class PlusExpression : public Expression
    {
    private:
        std::unique_ptr<Expression> leftOperand;
        std::unique_ptr<Expression> rightOperand;

    public:
        PlusExpression(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r) 
            : leftOperand{std::move(l)}, rightOperand{std::move(r)} {}
        ~PlusExpression() {};
        Rational evaluate(SymbolTable& table);
    };

    class MinusExpression : public Expression
    {
    private:
        std::unique_ptr<Expression> leftOperand;
        std::unique_ptr<Expression> rightOperand;

    public:
        MinusExpression(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r) 
            : leftOperand{std::move(l)}, rightOperand{std::move(r)} {}
        ~MinusExpression() {};
        Rational evaluate(SymbolTable& table);
    };

    class MultExpression : public Expression
    {
    private:
        std::unique_ptr<Expression> leftOperand;
        std::unique_ptr<Expression> rightOperand;

    public:
        MultExpression(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r) 
            : leftOperand{std::move(l)}, rightOperand{std::move(r)} {}
        ~MultExpression() {};
        Rational evaluate(SymbolTable& table);
    };

    class DivExpression : public Expression
    {
    private:
        std::unique_ptr<Expression> leftOperand;
        std::unique_ptr<Expression> rightOperand;

    public:
        DivExpression(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r) 
            : leftOperand{std::move(l)}, rightOperand{std::move(r)} {}
        ~DivExpression() {};
        Rational evaluate(SymbolTable& table);
    };
}

#endif
