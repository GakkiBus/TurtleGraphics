#ifndef SYMBOLIC_TABLE_H
#define SYMBOLIC_TABLE_H

#include <unordered_map>
#include <string>
#include <list>

// Mapping from variable names to list of respective values and block level during initialization.
// First entry of a varible name is last declared instance which will be deleted when respective block is left.
// Access on unitialized varibales will automatically intitialize them with 0. 
using table = std::unordered_map<std::string, std::list<std::pair<int, int>>>;

class SymbolicTable
{
private:
    table symbolicTable{};
    int currBlocklevel{0};

public:
    int lookup(std::string varname);
    void update(std::string varname, int value);
    void enterBlock();
    // Delete local variables from table on block exit
    void exitBlock(const std::list<std::string>& localVariables);
};

#endif
