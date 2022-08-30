// AbstractFileSystem.h
// Authur: Anthony Chen, Jeffery Chai
// Email: chenerdong@wustl.edu c.jeffery@wustl.edu
// declaration of the interface all file systems provide goes here

#pragma once
#include "AbstractFile.h"

class AbstractFileSystem {
public:
	virtual int addFile(std::string filename, AbstractFile* f) = 0;
	virtual int deleteFile(std::string name) = 0;
	virtual AbstractFile* openFile(std::string name) = 0;
	virtual int closeFile(AbstractFile* f) = 0;
	virtual std::set<std::string> getFileNames() = 0;
};