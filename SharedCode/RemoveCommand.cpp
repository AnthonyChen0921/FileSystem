
#include "RemoveCommand.h"

using namespace std;


RemoveCommand::RemoveCommand(AbstractFileSystem* pfs) {
	pfileSystem = pfs;
}

void RemoveCommand::displayInfo() {
	cout << "rm removes a file, removeCommand can be invoked with the command : rm <filename>" << endl;
}

int RemoveCommand::execute(std::string nfile) {
	if (nfile != "") {
		return pfileSystem->deleteFile(nfile);
	}
	return error::noArgument;
}