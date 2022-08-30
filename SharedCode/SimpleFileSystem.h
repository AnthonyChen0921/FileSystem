// SimpleFileSystem.h
// Authur: Anthony Chen, Jeffery Chai
// Email: chenerdong@wustl.edu c.jeffery@wustl.edu
// declaration of SimpleFileSystem class goes here
#pragma once
#include "AbstractFileSystem.h"
#include<map>
#include<set>

class SimpleFileSystem : public AbstractFileSystem {
public:
	int addFile(std::string filename, AbstractFile* f);
	int deleteFile(std::string name);
	AbstractFile* openFile(std::string name);
	int closeFile(AbstractFile* f);
	std::set<std::string> getFileNames();
private:
	std::map<std::string, AbstractFile*> files;
	std::set<AbstractFile*> openFiles;
};