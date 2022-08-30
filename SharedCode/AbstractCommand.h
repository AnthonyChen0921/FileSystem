#pragma once
#include <string>
class AbstractCommand {
public:
	virtual ~AbstractCommand() = default;
	virtual int execute(std::string) = 0;
	virtual void displayInfo() = 0;
};