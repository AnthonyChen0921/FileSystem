// USED by unit tests, this file should not be modified

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <iostream>
#include <string>
#include <algorithm>

enum commandTestResults {success=0};

class CommandTest : public AbstractCommand {
	AbstractFileSystem* afs;
	
public:
	CommandTest(AbstractFileSystem*);
	virtual ~CommandTest() = default;
	virtual int execute(std::string);
	virtual void displayInfo();
};