#ifndef STATEMENT_H
#define STATEMENT_H

#include "symbol_table.h"
#include "expression.h"
#include "bool_expression.h"

#include <string>
#include <memory>

namespace Turtle
{
    class Statement
    {
    public:
        virtual ~Statement() = default;
        virtual void execute(SymbolTable& table) = 0;
    };

    class BlockStatement : public Statement
    {
    private:
        std::list<std::shared_ptr<Statement>> body;

    public:
        BlockStatement(std::list<std::shared_ptr<Statement>> b)
            : body{b} {}
        ~BlockStatement() {};
        void execute(SymbolTable& table);
    };

    class DeclareStatement : public Statement
    {
    private:
        std::list<std::string> identifiers;

    public:
        DeclareStatement(const std::list<std::string> ids) : identifiers{ids} {}
        ~DeclareStatement() {};
        void execute(SymbolTable& table);
    };

    class AssignmentStatement : public Statement
    {
    private:
        const std::string identifier;
        std::shared_ptr<Expression> expression;

    public:
        AssignmentStatement(const std::string& id, std::shared_ptr<Expression> e)
            : identifier{id}, expression{e} {}
        ~AssignmentStatement() {};
        void execute(SymbolTable& table);
    };

    class IfStatement : public Statement
    {
    private:
        std::shared_ptr<BoolExpression> boolExpression;
        std::shared_ptr<Statement> ifBody;
        std::shared_ptr<Statement> elseBody;

    public:
        IfStatement(std::shared_ptr<BoolExpression> e, std::shared_ptr<Statement> iB, std::shared_ptr<Statement> eB)
            : boolExpression{e}, ifBody{iB}, elseBody{eB} {}
        ~IfStatement() {};
        void execute(SymbolTable& table);
    };

    class WhileStatement : public Statement
    {
    private:
        std::shared_ptr<BoolExpression> boolExpression;
        std::shared_ptr<Statement> body;

    public:
        WhileStatement(std::shared_ptr<BoolExpression> e, std::shared_ptr<Statement> b)
            : boolExpression{e}, body{b} {}
        ~WhileStatement() {};
        void execute(SymbolTable& table);
    };

    class ProcedureStatement : public Statement
    {
    private:
        const std::string identifier;
        std::list<std::string> parameters;
        std::shared_ptr<Statement> body;

    public:
        ProcedureStatement(const std::string& id, std::list<std::string> p, std::shared_ptr<Statement> b)
            : identifier{id}, parameters{p}, body{b} {}
        ~ProcedureStatement() {};
        void execute(SymbolTable& table);
        void call(SymbolTable& table, const std::list<Rational>& arguments);
    };

    class CallStatement : public Statement
    {
    private:
        const std::string identifier;
        std::list<std::shared_ptr<Expression>> arguments;

    public:
        CallStatement(const std::string& id, std::list<std::shared_ptr<Expression>> a)
            : identifier{id}, arguments{a} {}
        ~CallStatement() {};
        void execute(SymbolTable& table);
    };
}

#endif
