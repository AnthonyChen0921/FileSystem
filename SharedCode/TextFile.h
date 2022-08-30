// TextFile.h
// Authur: Anthony Chen, Jeffery Chai
// Email: chenerdong@wustl.edu c.jeffery@wustl.edu
// TextFile declaration goes here
#pragma once
#include "AbstractFile.h"
#include "AbstractFileVisitor.h"

class TextFile : public AbstractFile {
public:
    TextFile(std::string name);
	std::vector<char> read();
	int write(std::vector<char> v);
	int append(std::vector<char> v);
	unsigned int getSize();
	std::string getName();
	void accept(AbstractFileVisitor* ptr);
	AbstractFile* clone(std::string newfilename);
private:
	std::vector<char> contents;
	std::string name;
};