#pragma once
#include "AbstractCommand.h"
#include "AbstractFile.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractParsingStrategy.h"
#include "RenameParsingStrategy.h"

class MacroCommand : public AbstractCommand {
private:
	AbstractFileSystem* pfileSystem;
	std::vector<AbstractCommand*> commandlist;
	AbstractParsingStrategy* pts;
public:
	MacroCommand(AbstractFileSystem* pfs);
	void displayInfo();
	void addCommand(AbstractCommand* pc);
	void setParseStrategy(AbstractParsingStrategy* ps);
	int execute(std::string nfile);
};