#pragma once

#include "AbstractCommand.h"
#include "AbstractFile.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* pfileSystem;
public:
	DisplayCommand(AbstractFileSystem* pfs);
	void displayInfo();
	int execute(std::string nfile);
};