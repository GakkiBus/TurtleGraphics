#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "rational.h"

#include <unordered_map>
#include <string>
#include <list>
#include <memory>

namespace Turtle { class ProcedureStatement; }

struct tableEntry
{
    std::string identifier;
    int blockLevel;
    bool isProcedure;
    Turtle::ProcedureStatement* procedure;
    Turtle::Rational value;
};

using Table = std::list<std::shared_ptr<std::unordered_map<std::string, tableEntry>>>;

class SymbolTable
{
private:
    Table table;

public:
    SymbolTable(Table t) : table{t} {}
    tableEntry* lookup(const std::string& id);
    void addFunction(const std::string& id, Turtle::ProcedureStatement* procedure);
    void addVariable(const std::string& id);
    void updateVariable(const std::string& id, Turtle::Rational value);
    void enterBlock();
    void exitBlock();
    SymbolTable slice(int blockLevel);
};

#endif
