#pragma once
#include "AbstractCommand.h"
#include "AbstractFile.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class RemoveCommand : public AbstractCommand {
private:
	AbstractFileSystem* pfileSystem;
public:
	RemoveCommand(AbstractFileSystem* pfs);
	void displayInfo();
	int execute(std::string nfile);
};