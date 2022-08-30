
#include "CommandPrompt.h"
#include <iostream>

using namespace std;

CommandPrompt::CommandPrompt() {
	pfileSystem = nullptr;
	pfileFactory = nullptr;
}

void CommandPrompt::setFileSystem(AbstractFileSystem* fs) {
	pfileSystem = fs;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* ff) {
	pfileFactory = ff;
}

int CommandPrompt::addCommand(std::string commandstr, AbstractCommand* ac) {
	// get original size
	auto size = command.size();
	command.insert(pair<string, AbstractCommand*>(commandstr, ac));
	// compare original size and size after insertion
	if (size == command.size()) {
		return error::insertFailed;
	}
	return error::succeed;
}

void CommandPrompt::listCommands() {
	for (auto it = command.begin(); it != command.end(); ++it) {
		cout << it->first << endl;
	}
	cout << endl;
}

std::string CommandPrompt::prompt() {
	string input;
	cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << endl;
	cout << "$ ";
	getline(cin, input);
	return input;
}

int CommandPrompt::run() {
	string result;
	string space = " ";
	while (1) {
		// Get user input string
		result = prompt();

		// Check userquit
		if (result == "q") {
			return error::userQuit;
		}
		// Check help
		else if (result == "help") {
			listCommands();
		}
		// Check one word
		else if (result.find(space) == string::npos) {
			// search one word, if found
			auto res = command.find(result);
			if (res != command.end()) {
				int message = (res->second)->execute("");
				if (message != error::succeed) {
					cout << "Command failed. Error code: " << message <<endl;
				}
			}
			// Otherwise
			else {
				cout << "Command does not exist." << endl;
			}
		}
		// Check more than one word
		else if (result.find(space) != string::npos) {
			std::istringstream str(result);
			string first,second;
			str >> first;
			// first word is help
			if (first == "help") {
				str >> second;
				auto res = command.find(second);
				// found second word
				if (res != command.end()) {
					(res->second)->displayInfo();
				}
				else {
					cout << "Command does not exist." << endl;
				}
			}
			// first word isn't help
			else {
				// search in maps the command
				auto res = command.find(first);
				if (res != command.end()) {
					// pass remaining string as input
					int place = static_cast<int> (result.find_first_of(" "));
					place++;
					
					int message = (res->second)->execute(result.substr(place));
					if (message != error::succeed) {
						cout << "Command failed. Error code: " << message << endl;
					}
				}
				// Otherwise
				else {
					cout << "Command does not exist." << endl;
				}
			}
		}
	}
}