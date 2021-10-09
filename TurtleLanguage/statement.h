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
        std::list<std::unique_ptr<Statement>> body;

    public:
        BlockStatement(std::list<std::unique_ptr<Statement>> b)
            : body{std::move(b)} {}
        ~BlockStatement() {};
        void execute(SymbolTable& table);
    };

    class DeclareStatement : public Statement
    {
    private:
        std::list<std::string> identifiers;

    public:
        DeclareStatement(const std::list<std::string>& ids) : identifiers{ids} {}
        ~DeclareStatement() {};
        void execute(SymbolTable& table);
    };

    class AssignmentStatement : public Statement
    {
    private:
        const std::string identifier;
        std::unique_ptr<Expression> expression;

    public:
        AssignmentStatement(const std::string& id, std::unique_ptr<Expression> e)
            : identifier{id}, expression{std::move(e)} {}
        ~AssignmentStatement() {};
        void execute(SymbolTable& table);
    };

    class IfStatement : public Statement
    {
    private:
        std::unique_ptr<BoolExpression> boolExpression;
        std::unique_ptr<BlockStatement> ifBody;
        std::unique_ptr<BlockStatement> elseBody;

    public:
        IfStatement(std::unique_ptr<BoolExpression> e, std::unique_ptr<BlockStatement> iB, std::unique_ptr<BlockStatement> eB)
            : boolExpression{std::move(e)}, ifBody{std::move(iB)}, elseBody{std::move(eB)} {}
        ~IfStatement() {};
        void execute(SymbolTable& table);
    };

    class WhileStatement : public Statement
    {
    private:
        std::unique_ptr<BoolExpression> boolExpression;
        std::unique_ptr<BlockStatement> body;

    public:
        WhileStatement(std::unique_ptr<BoolExpression> e, std::unique_ptr<BlockStatement> b)
            : boolExpression{std::move(e)}, body{std::move(b)} {}
        ~WhileStatement() {};
        void execute(SymbolTable& table);
    };

    class ProcedureStatement : public Statement
    {
    private:
        const std::string identifier;
        std::list<std::string> parameters;
        std::unique_ptr<BlockStatement> body;

    public:
        ProcedureStatement(const std::string id, std::list<std::string> p, std::unique_ptr<BlockStatement> b)
            : identifier{id}, parameters{p}, body{std::move(b)} {}
        ~ProcedureStatement() {};
        void execute(SymbolTable& table);
        void call(SymbolTable& table, const std::list<Rational>& arguments);
    };

    class CallStatement : public Statement
    {
    private:
        const std::string identifier;
        std::list<std::unique_ptr<Expression>> arguments;

    public:
        CallStatement(const std::string id, std::list<std::unique_ptr<Expression>> a)
            : identifier{id}, arguments{std::move(a)} {}
        ~CallStatement() {};
        void execute(SymbolTable& table);
    };
}

#endif
