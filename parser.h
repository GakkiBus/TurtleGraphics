# ifndef PARSER_H
# define PARSER_H

#include "parse_table.h"
#include "turtlelang.h"
#include "lexer.h"

#include <string>
#include <stack>
#include <list>

class Parser
{
private:
    Lexer lexer;
    std::stack<Grammar::Symbol> parseStack;
    void pushRule(const std::list<Grammar::Symbol>& rule);

public:
    Parser(const std::string& input) : lexer{Lexer{input}}, parseStack{std::stack<Grammar::Symbol>{}} {}
    void parse();
};

# endif
