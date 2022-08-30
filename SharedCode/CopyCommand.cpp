
#include "CopyCommand.h"
#include "PasswordProxy.h"


using namespace std;


CopyCommand::CopyCommand(AbstractFileSystem* pfs) {
	pfileSystem = pfs;
}

void CopyCommand::displayInfo() {
	cout << "cp copys a file, cp can be invoked with the command : cp <file_to_copy> <new_name_with_no_extension>" << endl;
}

int CopyCommand::execute(std::string nfile) {
	string originalFile;
	string newfilename;
	istringstream iss(nfile);
	iss >> originalFile >> newfilename;
	auto ptr = pfileSystem->openFile(originalFile);
	if (ptr == nullptr) {
		return error::fileNotExists;
	}
	AbstractFile* file_copy = ptr->clone(newfilename);
	int message = pfileSystem->addFile(file_copy->getName(), file_copy);
	pfileSystem->closeFile(ptr);
	return message;
}
