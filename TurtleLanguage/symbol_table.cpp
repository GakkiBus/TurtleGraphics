#include "symbol_table.h"
#include "rational.h"

#include <unordered_map>
#include <string>
#include <list>
#include <memory>
#include <iostream>

namespace Turtle { class ProcedureStatement; }

tableEntry* SymbolTable::lookup(const std::string& id)
{
    for (auto it{table.rbegin()}; it != table.rend(); ++it) {
        auto search{(*it)->find(id)};
        if (search != (*it)->end()) {
            return &(search->second);
        }
    }

    return nullptr;
}

void SymbolTable::addFunction(const std::string& id, Turtle::ProcedureStatement* procedure)
{
    tableEntry entry{id, static_cast<int>(table.size()), true, procedure, Turtle::Rational(1, 1)};
    (table.back())->insert_or_assign(id, entry); 
}

void SymbolTable::addVariable(const std::string& id)
{
    tableEntry entry{id, static_cast<int>(table.size()), false, nullptr, Turtle::Rational(0, 1)};
    (table.back())->insert_or_assign(id, entry); 
}

void SymbolTable::updateVariable(const std::string& id, Turtle::Rational value)
{
    tableEntry* search{lookup(id)};
    if (search != nullptr && !(search->isProcedure)) {
        search->value = value;
    } else {
        std::cerr << "Error looking up variable '" << id << "'\n";
        exit(1);
    }
}

void SymbolTable::enterBlock()
{
    table.push_back(std::make_shared<std::unordered_map<std::string, tableEntry>>(std::unordered_map<std::string, tableEntry>{}));
}

void SymbolTable::exitBlock()
{
    table.pop_back();
}

SymbolTable SymbolTable::slice(int blockLevel)
{
    Table subTable{};
    auto it{table.begin()};
    for (int i{0}; it != table.end() && i < blockLevel; ++i) {
        subTable.push_back(*it);
        ++it;
    }
    return SymbolTable{subTable};
}
