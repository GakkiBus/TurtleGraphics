#include "parser.h"
#include "turtlelang.h"

#include <iostream>
#include <string>
#include <regex>

/*
 * Statement ::= <char>(<space>+<positive integer>)?<space>*
 * where the char is used to identify the instruction which may take a positive int as argument
 */
Action parseLine(std::string &statement)
{
    const std::regex cmdRegex{"^([A-Z])(?:\\s+(\\d+))?\\s*"};
    std::smatch matches {};
    if (std::regex_match(statement, matches, cmdRegex)) {
	char code = matches[1].str()[0];
	Command cmd{lookupCmd(code)};
	Action action{cmd.action};
	if (cmd.takesArgs && matches.size() == 3) {
	    action.arg = std::stoi(matches[2].str());
	}
	return action;
    }
    std::cout << "Error reading statement\n";
    exit(1);
}
