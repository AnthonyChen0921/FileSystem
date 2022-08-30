
#include "MacroCommand.h"



using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* pfs) {
	pfileSystem = pfs;
	pts = nullptr;
}

void MacroCommand::displayInfo() {
	cout << "rn renames a file, rn can be invoked with the command : rn <existing_file> <new_name_with_no_extension>" << endl;
}

void MacroCommand::addCommand(AbstractCommand* pc) {
	commandlist.push_back(pc);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* ps) {
	pts = ps;
}

int MacroCommand::execute(std::string nfile) {
	vector<string> inputstr = pts->parse(nfile);
	if (inputstr.size() != commandlist.size()) {
		return error::commandArgumentUnmatched;
	}
	size_t index = 0;
	int message;
	for (size_t i = 0; i < commandlist.size(); ++i) {
		message = (commandlist[i])->execute(inputstr[index]);
		++index;
		if (message != succeed) {
			return message;
		}
	}
	return succeed;
}