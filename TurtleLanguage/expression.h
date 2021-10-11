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
        std::shared_ptr<Expression> leftOperand;
        std::shared_ptr<Expression> rightOperand;

    public:
        PlusExpression(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) 
            : leftOperand{l}, rightOperand{r} {}
        ~PlusExpression() {};
        Rational evaluate(SymbolTable& table);
    };

    class MinusExpression : public Expression
    {
    private:
        std::shared_ptr<Expression> leftOperand;
        std::shared_ptr<Expression> rightOperand;

    public:
        MinusExpression(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) 
            : leftOperand{l}, rightOperand{r} {}
        ~MinusExpression() {};
        Rational evaluate(SymbolTable& table);
    };

    class MultExpression : public Expression
    {
    private:
        std::shared_ptr<Expression> leftOperand;
        std::shared_ptr<Expression> rightOperand;

    public:
        MultExpression(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) 
            : leftOperand{l}, rightOperand{r} {}
        ~MultExpression() {};
        Rational evaluate(SymbolTable& table);
    };

    class DivExpression : public Expression
    {
    private:
        std::shared_ptr<Expression> leftOperand;
        std::shared_ptr<Expression> rightOperand;

    public:
        DivExpression(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) 
            : leftOperand{l}, rightOperand{r} {}
        ~DivExpression() {};
        Rational evaluate(SymbolTable& table);
    };
}

#endif
