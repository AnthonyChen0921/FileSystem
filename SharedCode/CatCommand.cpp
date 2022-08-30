
#include "CatCommand.h"

using namespace std;


CatCommand::CatCommand(AbstractFileSystem* pfs) {
	pfileSystem = pfs;
}

void CatCommand::displayInfo() {
	cout << "cat concatenating a file, cat can be invoked with the command : cat <filename> [-a], -a option stand for append" << endl;
}

int CatCommand::execute(std::string nfile) {
	string option;
	string filename;
	istringstream iss(nfile);
	iss >> filename >> option;
	if (option == "-a") {
		// open file
		auto ptr = pfileSystem->openFile(filename);
		if (ptr == nullptr) {
			return error::fileNotExists;
		}
		// current content
		vector<char> data = ptr->read();
		for (char c : data) {
			cout << c;
		}
		cout << endl;
		// concatinate
		vector<char> temp;
		string line;
		getline(cin, line);
		while (line != ":q" && line != ":wq") {
			for (char c : line) {
				temp.push_back(c);
			}
			temp.push_back('\n');
			getline(cin, line);
		}
		
		if (line == ":q") {
		}
		else if (line == ":wq") {
			pfileSystem->closeFile(ptr);
			temp.pop_back();
			return ptr->append(temp);
		}
		return pfileSystem->closeFile(ptr);
	}
	else {
		// open file
		auto ptr = pfileSystem->openFile(filename);
		if (ptr == nullptr) {
			return error::fileNotExists;
		}
		vector<char> temp;
		string line;
		getline(cin, line);
		while (line != ":q" && line != ":wq") {
			for (char c : line) {
				temp.push_back(c);
			}
			temp.push_back('\n');
			getline(cin, line);
		}
		if (line == ":q") {
		}
		else if (line == ":wq") {
			temp.pop_back();
			ptr->write(temp);
		}

		return pfileSystem->closeFile(ptr);
	}
	return error::fileTypeNotSupport;
}
