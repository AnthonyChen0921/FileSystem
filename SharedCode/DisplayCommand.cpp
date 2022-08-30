
#include "DisplayCommand.h"
#include "BasicDisplayVisitor.h"

using namespace std;


DisplayCommand::DisplayCommand(AbstractFileSystem* pfs) {
	pfileSystem = pfs;
}

void DisplayCommand::displayInfo() {
	cout << "ds displays a file, ds can be invoked with the command : ds <filename> [-d], -d option for data only" << endl;
}

int DisplayCommand::execute(std::string nfile) {
	string option;
	string filename;
	istringstream iss(nfile);
	iss >> filename >> option;
	if (option == "-d") {
		auto ptr = pfileSystem->openFile(filename);
		if (ptr != nullptr) {
			vector<char> data = ptr->read();
			for (char c : data) {
				cout << c;
			}
			cout << endl;
			return pfileSystem->closeFile(ptr);
		}
		return error::fileNotExists;
	}
	else {
		auto ptr = pfileSystem->openFile(nfile);
		if (ptr != nullptr) {
			AbstractFileVisitor* mdv = new BasicDisplayVisitor;
			ptr->accept(mdv);
			return pfileSystem->closeFile(ptr);
		}
		return error::fileNotExists;
	}
	return error::fileNotExists;
}
