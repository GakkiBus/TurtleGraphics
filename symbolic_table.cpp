#include "symbolic_table.h"

#include <unordered_map>
#include <string>
#include <list>

int SymbolicTable::lookup(std::string varname)
{
    auto search{symbolicTable.find(varname)};
    if (search != symbolicTable.end()) {
        return search->second.front().first;
    } else {
        return 0;
    }
}

void SymbolicTable::update(std::string varname, int value)
{
    auto search{symbolicTable.find(varname)};
    if (search != symbolicTable.end()) {
        search->second.front().first = value;
    } else {
        symbolicTable.insert_or_assign(varname, std::list<std::pair<int, int>>{std::make_pair(value, currBlocklevel)});
    }
}

void SymbolicTable::enterBlock()
{
    ++currBlocklevel;
}

void SymbolicTable::exitBlock(const std::list<std::string>& localVariables)
{
    for (auto& varname : localVariables) {
        auto search{symbolicTable.find(varname)};
        if (search != symbolicTable.end()) {
            return search->second.pop_front();
        }
    }
    --currBlocklevel;
}

