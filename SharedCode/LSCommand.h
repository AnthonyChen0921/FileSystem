#pragma once
#include "AbstractCommand.h"
#include "AbstractFile.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class LSCommand : public AbstractCommand {
private:
	AbstractFileSystem* pfileSystem;
public:
	LSCommand(AbstractFileSystem* pfs);
	void displayInfo();
	int execute(std::string nfile);
};