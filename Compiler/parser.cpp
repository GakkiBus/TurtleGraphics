#include "parser.h"
#include "grammar.h"
#include "parse_table.h"
#include "lexer.h"
#include "code_generation.h"

#include <iostream>
#include <set>
#include <list>

const static std::set<Grammar::Symbol> keptSymbols{
    Grammar::MULT, Grammar::PLUS, Grammar::MINUS, Grammar::DIV,
    Grammar::LESS_THAN, Grammar::EQUALS, Grammar::CALL, Grammar::DECLARE,
    Grammar::IDENTIFIER, Grammar::IF, Grammar::NUMBER, Grammar::PROCEDURE, 
    Grammar::WHILE, Grammar::BLOCK_STMT, Grammar::BOOL_EXPR, Grammar::EXPR, 
    Grammar::EXPRS, Grammar::FACTOR, Grammar::IDS, Grammar::STMT, Grammar::TERM
};

static bool isKept(Grammar::Symbol symbol)
{
    return keptSymbols.find(symbol) != keptSymbols.end();
}

/* static void printParseTree(PTNode root, int depth) */
/* { */
/*     std::cerr << root.token.symbol << " [" << depth << "]\n"; */ 
/*     for (auto& node : root.children) { */
/*         printParseTree(node, depth + 1); */
/*     } */
/* } */

PTNode Parser::parse()
{
    PTNode root{Token{Grammar::BLOCK_STMT}};
    pushSymbol(Grammar::EOS, &root);
    pushSymbol(Grammar::BLOCK_STMT, &root);

    do {
        PTPush parseTop{parseStack.top()};
        parseStack.pop();
        Token inputTop{lexer.peek()};

        if (Grammar::isTerminal(parseTop.symbol) && parseTop.symbol == inputTop.symbol) {
            insertIntoParseTree(parseTop, inputTop);
            lexer.next();
        } else if (!Grammar::isTerminal(parseTop.symbol) 
                && ParseTable::getEntry(parseTop.symbol, inputTop.symbol) != -1) {
            PTNode* parent = insertIntoParseTree(parseTop, Token{parseTop.symbol});
            pushRule(ParseTable::rules[ParseTable::getEntry(parseTop.symbol, inputTop.symbol)], parent);
        } else {
            std::cerr << "Syntax error: " << inputTop.symbol << '\n';
            exit(1);
        }
    } while (!parseStack.empty());

    return root;
}

void Parser::pushRule(const std::list<Grammar::Symbol>& rule, PTNode* parent)
{
    for(auto it{rule.rbegin()}; it != rule.rend(); ++it) {
        pushSymbol(*it, parent);
    }
}

void Parser::pushSymbol(Grammar::Symbol symbol, PTNode* parent)
{
    parseStack.push(PTPush{symbol, parent});
}

PTNode* Parser::insertIntoParseTree(PTPush parseTop, Token token)
{
    if (isKept(parseTop.symbol)) {
        parseTop.insertAt->children.push_back(PTNode{token});
        PTNode* inserted{&(parseTop.insertAt->children.back())};
        return inserted;
    } else {
        return parseTop.insertAt;
    }
}
