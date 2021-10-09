#include "statement.h"
#include "rational.h"
#include "expression.h"
#include "bool_expression.h"

#include <list>
#include <iostream>

using namespace Turtle;

void BlockStatement::execute(SymbolTable& table)
{
    table.enterBlock();

    for (auto& statement : body) {
        statement->execute(table);
    }

    table.exitBlock();
}

void DeclareStatement::execute(SymbolTable& table)
{
    for (auto& identifier : identifiers) {
        table.addVariable(identifier);
    }
}

void AssignmentStatement::execute(SymbolTable& table)
{
    table.updateVariable(identifier, expression->evaluate(table));
}

void IfStatement::execute(SymbolTable& table)
{
    if (boolExpression->evaluate(table)) {
        ifBody->execute(table);
    } else {
        elseBody->execute(table);
    }
}

void WhileStatement::execute(SymbolTable& table)
{
    while (boolExpression->evaluate(table)) {
        body->execute(table);
    }
}

void ProcedureStatement::execute(SymbolTable& table)
{
    table.addFunction(identifier, this);
}

void ProcedureStatement::call(SymbolTable& table, const std::list<Rational>& arguments)
{
   if (parameters.size() != arguments.size()) {
       std::cerr << "Error while calling '" << identifier << "': required number of arguments is " << parameters.size() << " but given: " << arguments.size() << '\n';
       exit(1);
   }

    table.enterBlock();

    (DeclareStatement{parameters}).execute(table);
    auto pIt{parameters.begin()};
    auto aIt{arguments.begin()};
    while (pIt != parameters.end() && aIt != arguments.end()) {
        table.updateVariable(*pIt, *aIt);
    }
    body->execute(table);

    table.exitBlock();
}

void CallStatement::execute(SymbolTable& table)
{
    tableEntry* search{table.lookup(identifier)};
    if (search != nullptr && search->isProcedure) {
        std::list<Rational> evaluated{};
        for (auto& e : arguments) {
            evaluated.push_back(e->evaluate(table));
        }
        SymbolTable scope{table.slice(search->blockLevel)};
        (search->procedure)->call(scope, evaluated);
    } else {
        std::cerr << "Error looking up procedure '" << identifier << "'\n";
        exit(1);
    }
}
