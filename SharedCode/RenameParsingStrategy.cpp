#include "RenameParsingStrategy.h"


using namespace std;

std::vector<std::string> RenameParsingStrategy::parse(std::string input) {
	istringstream iss (input);
	vector<string> output;

	string copy_input;
	string remove_input;

	copy_input = input;
	iss >> remove_input;

	output.push_back(copy_input);
	output.push_back(remove_input);
	
	return output;
}