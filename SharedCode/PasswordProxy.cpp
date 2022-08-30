
#include "PasswordProxy.h"

using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* p, string pw) {
	ptr = p;
	password = pw;
}

PasswordProxy::~PasswordProxy() {
	ptr = nullptr;
}

string PasswordProxy::passwordPrompt() {
	string pw;
	cout << "Password:" << endl;
	cin >> pw;
	return pw;
}

bool PasswordProxy::correctPW(string pw) {
	return (pw == password);
}

vector<char> PasswordProxy::read() {
	if (correctPW(passwordPrompt())) {
		return ptr->read();
	}
	vector<char> empty;
	return empty;
}

int PasswordProxy::write(std::vector<char> v) {
	if (correctPW(passwordPrompt())) {
		return ptr->write(v);
	}
	return error::incorrectPassword;
}

int PasswordProxy::append(std::vector<char> v) {
	if (correctPW(passwordPrompt())) {
		return ptr->append(v);
	}
	return error::incorrectPassword;
}

unsigned int PasswordProxy::getSize() {
	return ptr->getSize();
}

std::string PasswordProxy::getName() {
	return ptr->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* p) {
	if (correctPW(passwordPrompt())) {
		return ptr->accept(p);
	}
}

AbstractFile* PasswordProxy::clone(std::string newfilename) {
	auto pfile_copy = ptr->clone(newfilename);
	AbstractFile* ptr_copy = new PasswordProxy(pfile_copy, password);
	return ptr_copy;
}