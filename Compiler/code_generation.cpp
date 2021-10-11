#include "code_generation.h"
#include "grammar.h"
#include "lexer.h"
#include "parser.h"
#include "statement.h"
#include "expression.h"
#include "bool_expression.h"
#include "rational.h"

#include <memory>
#include <list>
#include <string>

using namespace Turtle;

static std::shared_ptr<Statement> generateStatement(PTNode root);
static std::shared_ptr<Statement> generateBlockStatement(PTNode root);
static std::shared_ptr<Statement> generateCallStatement(PTNode root);
static std::shared_ptr<Statement> generateDeclareStatement(PTNode root);
static std::shared_ptr<Statement> generateAssignmentStatement(PTNode root);
static std::shared_ptr<Statement> generateIfStatement(PTNode root);
static std::shared_ptr<Statement> generateProcedureStatement(PTNode root);
static std::shared_ptr<Statement> generateWhileStatement(PTNode root);

static std::shared_ptr<Expression> generateExpression(PTNode root);
static std::shared_ptr<BoolExpression> generateBoolExpression(PTNode root);

static std::list<std::string> generateIds(PTNode root);
static std::list<std::shared_ptr<Expression>> generateExpressions(PTNode root);

std::shared_ptr<Statement> generate(PTNode root)
{
   return generateBlockStatement(root.children.front()); 
}

static std::shared_ptr<Statement> generateStatement(PTNode root)
{
    switch (root.children.front().token.symbol)
    {
        case Grammar::CALL:
            return generateCallStatement(root);
        case Grammar::DECLARE:
            return generateDeclareStatement(root);
        case Grammar::IDENTIFIER:
            return generateAssignmentStatement(root);
        case Grammar::IF:
            return generateIfStatement(root);
        case Grammar::PROCEDURE:
            return generateProcedureStatement(root);
        case Grammar::WHILE:
            return generateWhileStatement(root);
        default:
            return generateBlockStatement(root);
    }
}

static std::shared_ptr<Statement> generateBlockStatement(PTNode root)
{
    std::list<std::shared_ptr<Statement>> body{};
    for (auto& node : root.children) {
        body.push_back(generateStatement(node));
    }
    return std::make_shared<BlockStatement>(BlockStatement{body});
}

static std::shared_ptr<Statement> generateCallStatement(PTNode root)
{
   auto it{root.children.begin()}; 
   ++it;
   std::string identifier{(*it).token.value};
   ++it;
   std::list<std::shared_ptr<Expression>> arguments{generateExpressions(*it)};
   return std::make_shared<CallStatement>(CallStatement{identifier, arguments});
}

static std::shared_ptr<Statement> generateDeclareStatement(PTNode root)
{
    auto it{root.children.begin()};
    ++it;
    std::list<std::string> parameters{generateIds(*it)};
    return std::make_shared<DeclareStatement>(DeclareStatement{parameters});
}

static std::shared_ptr<Statement> generateAssignmentStatement(PTNode root)
{
    auto it{root.children.begin()};
    std::string identifier{(*it).token.value};
    ++it;
    std::shared_ptr<Expression> expression{generateExpression(*it)};
    return std::make_shared<AssignmentStatement>(AssignmentStatement{identifier, expression});
}

static std::shared_ptr<Statement> generateIfStatement(PTNode root)
{
    auto it{root.children.begin()};
    ++it;
    std::shared_ptr<BoolExpression> boolExpression{generateBoolExpression(*it)};
    ++it;
    std::shared_ptr<Statement> ifBody{generateBlockStatement(*it)};
    ++it;
    std::shared_ptr<Statement> elseBody{generateBlockStatement(*it)};
    return std::make_shared<IfStatement>(IfStatement{boolExpression, ifBody, elseBody});
}

static std::shared_ptr<Statement> generateProcedureStatement(PTNode root)
{
    auto it{root.children.begin()};
    ++it;
    std::string identifier{(*it).token.value};
    ++it;
    std::list<std::string> parameters{generateIds(*it)};
    ++it;
    std::shared_ptr<Statement> body{generateBlockStatement(*it)};
    return std::make_shared<ProcedureStatement>(ProcedureStatement{identifier, parameters, body});
}

static std::shared_ptr<Statement> generateWhileStatement(PTNode root)
{
    auto it{root.children.begin()};
    ++it;
    std::shared_ptr<BoolExpression> boolExpression{generateBoolExpression(*it)};
    ++it;
    std::shared_ptr<Statement> body{generateBlockStatement(*it)};
    return std::make_shared<WhileStatement>(WhileStatement{boolExpression, body});
}

static std::shared_ptr<Expression> generateExpression(PTNode root)
{
    if (root.children.size() < 2) {
        switch (root.token.symbol)
        {
            case Grammar::NUMBER:
                return std::make_shared<NumberExpression>(NumberExpression{Rational{root.token.value}});
            case Grammar::IDENTIFIER:
                return std::make_shared<VarExpression>(VarExpression{root.token.value});
            default:
                return generateExpression(root.children.front());
        }
    } else {
        auto it{root.children.begin()};
        std::shared_ptr<Expression> leftOperand{generateExpression(*it)};
        ++it;
        while (it != root.children.end()) {
            Grammar::Symbol ExprOperator{(*it).token.symbol};
            std::shared_ptr<Expression> rightOperand{generateExpression(*(++it))};
            switch (ExprOperator)
            {
                case Grammar::PLUS:
                    leftOperand = std::make_shared<PlusExpression>(PlusExpression{leftOperand, rightOperand});
                    break;
                case Grammar::MINUS:
                    leftOperand = std::make_shared<MinusExpression>(MinusExpression{leftOperand, rightOperand});
                    break;
                case Grammar::MULT:
                    leftOperand = std::make_shared<MultExpression>(MultExpression{leftOperand, rightOperand});
                    break;
                default:
                    leftOperand = std::make_shared<DivExpression>(DivExpression{leftOperand, rightOperand});
                    break;
           }
           ++it;
        }
        return leftOperand;
    }
}

static std::shared_ptr<BoolExpression> generateBoolExpression(PTNode root)
{
    auto it{root.children.begin()};
    std::shared_ptr<Expression> leftOperand{generateExpression(*it)};
    ++it;
    Grammar::Symbol ExprOperator{(*it).token.symbol};
    std::shared_ptr<Expression> rightOperand{generateExpression(*(++it))};
    switch (ExprOperator)
    {
        case Grammar::LESS_THAN:
            return std::make_shared<LessThanExpression>(LessThanExpression{leftOperand, rightOperand});
        default:
            return std::make_shared<EqualsExpression>(EqualsExpression{leftOperand, rightOperand});
    }
}

static std::list<std::string> generateIds(PTNode root)
{
    std::list<std::string> parameters{};
    for (auto& node : root.children) {
        parameters.push_back(node.token.value);
    }
    return parameters;
}

static std::list<std::shared_ptr<Expression>> generateExpressions(PTNode root)
{
    std::list<std::shared_ptr<Expression>> arguments{};
    for (auto& node : root.children) {
        arguments.push_back(generateExpression(node));
    }
    return arguments;
}
