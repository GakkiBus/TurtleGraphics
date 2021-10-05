#include "parser.h"
#include "lexer.h"
#include "turtlelang.h"

#include <iostream>

void Parser::parse()
{
    parseStack.push(Grammar::EOS);
    parseStack.push(Grammar::PROGRAM);

    do {
        Grammar::Symbol parseTop{parseStack.top()};
        parseStack.pop();
        Grammar::Symbol inputTop{lexer.peek().symbol};
        if (Grammar::isTerminal(parseTop) && parseTop == inputTop) {
            lexer.next();
        } else if (!Grammar::isTerminal(parseTop) && ParseTable::getEntry(parseTop, inputTop) != -1) {
            pushRule(ParseTable::rules[ParseTable::getEntry(parseTop, inputTop)]);
        } else {
            std::cerr << "Syntax error: " << inputTop << '\n';
            break;
        }
    } while (!parseStack.empty());
}

void Parser::pushRule(const std::list<Grammar::Symbol>& rule)
{
    for(auto it{rule.rbegin()}; it != rule.rend(); ++it) {
        parseStack.push(*it);
    }
}
