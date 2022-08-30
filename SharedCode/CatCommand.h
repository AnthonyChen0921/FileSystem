#pragma once

#include "AbstractCommand.h"
#include "AbstractFile.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* pfileSystem;
public:
	CatCommand(AbstractFileSystem* pfs);
	void displayInfo();
	int execute(std::string nfile);
};