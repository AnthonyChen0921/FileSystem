// ImageFile.h
// Authur: Anthony Chen, Jeffery Chai
// Email: chenerdong@wustl.edu c.jeffery@wustl.edu
// Image file class declaration here

#pragma once
#include "AbstractFile.h"
#include "AbstractFileVisitor.h"

class ImageFile : public AbstractFile {
public:
	ImageFile(std::string name);
	std::vector<char> read();
	int write(std::vector<char> v);
	int append(std::vector<char> v);
	unsigned int getSize();
	unsigned int getLength();
	std::string getName();
	void accept(AbstractFileVisitor* ptr);
	AbstractFile* clone(std::string newfilename);
protected:
	int coordinatesToIndex(int x, int y);
private:
	std::vector<char> contents;
	std::string name;
	char size;
};