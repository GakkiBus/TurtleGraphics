#include "symbol_table.h"

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

// Delete local variables from table on block exit
void SymbolicTable::exitBlock()
{
    auto it{symbolicTable.begin()};
    while (it != symbolicTable.end()) {
        if (it->second.front().second == currBlocklevel) {
            it->second.pop_front();
        }

        if (it->second.empty()) {
            it = symbolicTable.erase(it);
        } else {
            ++it;
        }
    }
    --currBlocklevel;
}

