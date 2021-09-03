#include "parser.h"

#include <iostream>
#include <fstream>


int main(int argc, char *argv[])
{
    if (argc == 1) {
	std::cerr << "No inputfile given\n";
	exit(1);
    }
    std::ifstream myfile {argv[1]};
    if (!myfile.is_open()) {
	std::cerr << "File " << argv[1] << " not found\n";
	exit(1);
    }
    std::string line{};
    while (getline(myfile, line)) {
	Action action {parseLine(line)};
	(*action.action)(action.arg);
    }
    
    myfile.close();
    return 0;
}
