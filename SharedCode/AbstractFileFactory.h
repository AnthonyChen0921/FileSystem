// AbstractFileFactory.h
// Authur: Anthony Chen, Jeffery Chai
// Email: chenerdong@wustl.edu c.jeffery@wustl.edu

#pragma once
// studio 18 - file factory interface declared here
#include "AbstractFile.h"

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string name)=0;
};