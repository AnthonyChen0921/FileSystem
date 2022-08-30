#pragma once


#include "AbstractFile.h"

class PasswordProxy : public AbstractFile {
private:
	AbstractFile* ptr;
	std::string password;
protected:
	std::string passwordPrompt();
	bool correctPW(std::string pw);
public:
	PasswordProxy(AbstractFile* p, std::string pw);
	~PasswordProxy();
	std::vector<char> read();
	int write(std::vector<char> v);
	int append(std::vector<char> v);
	unsigned int getSize();
	std::string getName();
	void accept(AbstractFileVisitor* p);
	AbstractFile* clone(std::string newfilename);
};