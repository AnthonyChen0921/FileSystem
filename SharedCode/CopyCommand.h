#pragma once

#include "AbstractCommand.h"
#include "AbstractFile.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* pfileSystem;
public:
	CopyCommand(AbstractFileSystem* pfs);
	void displayInfo();
	int execute(std::string nfile);
};