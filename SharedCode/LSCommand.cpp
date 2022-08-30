
#include "LSCommand.h"
#include "MetadataDisplayVisitor.h"

using namespace std;

LSCommand::LSCommand(AbstractFileSystem* pfs) {
	pfileSystem = pfs;
}
void LSCommand::displayInfo() {
	cout << "ls list all file in the dirctory, usage: ls" << endl;
}

int LSCommand::execute(std::string nfile) {
	if (nfile == "") {
		set<string> s = pfileSystem->getFileNames();
		int newline = 0;
		for (auto p = s.begin(); p != s.end(); ++p) {
			cout.width(20); 
			cout << left << (*p);
			++newline;
			if (newline % 2 == 0) {
				cout << endl;
			}
		}
		cout << endl;
		return error::succeed;
	}
	else if (nfile == "-m") {
		set<string> s = pfileSystem->getFileNames();
		for (auto p = s.begin(); p != s.end(); ++p) {
			cout.width(20);
			// metadata
			auto ptr = pfileSystem->openFile(*p);
			AbstractFileVisitor* mdv = new MetadataDisplayVisitor;
			ptr->accept(mdv);
			pfileSystem->closeFile(ptr);
		}
		return error::succeed;
	}

	return error::additionOptionNotSupport;
}