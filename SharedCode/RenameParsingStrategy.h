#pragma once
#include "AbstractParsingStrategy.h"
#include "AbstractFile.h"

class RenameParsingStrategy : public AbstractParsingStrategy{
public:
	std::vector<std::string> parse(std::string input);
};