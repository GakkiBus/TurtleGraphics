# ifndef PARSER_H
# define PARSER_H

#include "grammar.h"
#include "lexer.h"

#include <stack>
#include <list>

struct PTNode 
{
    Token token;
    std::list<PTNode> children{};
};

struct PTPush 
{
    Grammar::Symbol symbol;
    PTNode* insertAt;
};

class Parser
{
private:
    Lexer* lexer;
    std::stack<PTPush> parseStack;
    void pushRule(const std::list<Grammar::Symbol>& rule, PTNode* parent);
    void pushSymbol(Grammar::Symbol symbol, PTNode* parent);
    PTNode* insertIntoParseTree(PTPush parseTop, Token token);

public:
    Parser(Lexer* lexer) : lexer{lexer}, parseStack{} {}
    PTNode parse();
};

# endif
