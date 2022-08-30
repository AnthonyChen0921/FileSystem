
#include "TouchCommand.h"
#include "PasswordProxy.h"

using namespace std;


TouchCommand::TouchCommand(AbstractFileSystem* pfs, AbstractFileFactory* pff) {
	pfileSystem = pfs;
	pfileFactory = pff;
}

void TouchCommand::displayInfo(){
	cout << "touch creates a file, touch can be invoked with the command : touch <filename> [-p], -p for create file with password" << endl;
}

int TouchCommand::execute(std::string nfile) {
	string option;
	string filename;
	istringstream iss(nfile);
	iss >> filename >> option;
	
	if (nfile.size() > 20) {
		return error::fileNameTooLong;
	}

	if (option == "-p") {
		auto res = pfileFactory->createFile(filename);
		if (res != nullptr) {
			// setup password
			cout << "What is the password?" << endl;
			string password;
			cin >> password;
			PasswordProxy* pp = new PasswordProxy(res, password);
			int message = pfileSystem->addFile(filename, pp);
			if (message != error::succeed) {
				return message;
			}
			return error::succeed;
		}
		return error::fileNotCreated;
	}
	else {
		auto res = pfileFactory->createFile(nfile);
		if (res != nullptr) {
			int message = pfileSystem->addFile(nfile, res);
			if (message != error::succeed) {
				//pfileSystem->deleteFile(nfile);
				return message;
			}
			return error::succeed;
		}
		return error::fileNotCreated;
	}
	return error::fileTypeNotSupport;
}