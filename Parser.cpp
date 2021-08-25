#include <iostream>
#include <ifstream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc < 2) {
	std::cout << "No inputfile given\n";
	return 1;
    }
    parse(argv[1]);
}

void parse(char *path)
{
    std::ifsteam mysfile ("input.txt");
    if (myfile.is_open()) {
	string line;
	while (getline(myfile, line)) {
	    std::cout << line << '\n';
	}
    }
}
