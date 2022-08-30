#pragma once


#include "AbstractCommand.h"
#include "AbstractFile.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class TouchCommand : public AbstractCommand {
private:
	AbstractFileSystem* pfileSystem;
	AbstractFileFactory* pfileFactory;
public:
	TouchCommand(AbstractFileSystem* pfs, AbstractFileFactory* pff);
	void displayInfo();
	int execute(std::string nfile);
};