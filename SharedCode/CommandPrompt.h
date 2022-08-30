#pragma once

#include "AbstractCommand.h"
#include "AbstractFile.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>



class CommandPrompt{
private:
	std::map<std::string, AbstractCommand*> command;
	AbstractFileSystem* pfileSystem;
	AbstractFileFactory* pfileFactory;
protected:
	void listCommands();
	std::string prompt();
public:
	CommandPrompt();
	~CommandPrompt() = default;
	void setFileSystem(AbstractFileSystem* fs);
	void setFileFactory(AbstractFileFactory* ff);
	int addCommand(std::string commandstr, AbstractCommand* ac);
	int run();
};