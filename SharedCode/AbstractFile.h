// AbstractFile.h
// Authur: Anthony Chen, Jeffery Chai
// Email: chenerdong@wustl.edu c.jeffery@wustl.edu
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>

class AbstractFileVisitor;

// declare enums of various errors
enum error {
	succeed,
	sizeMismatch,
	appendNotSupported,
	ImageWrong,
	nullptrException,
	fileAlreadyExists,
	fileNotExists,
	fileNotOpen,
	noFileExtention,
	fileTypeNotSupport,
	fileAlreadyOpen,
	incorrectPassword,
	insertFailed,
	userQuit,
	commandNotFound,
	fileNotCreated,
	additionOptionNotSupport,
	fileNameTooLong,
	noArgument,
	commandArgumentUnmatched
};

// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
class AbstractFile {
public:
	virtual std::vector<char> read()=0;
	virtual int write(std::vector<char> v)=0;
	virtual int append(std::vector<char> v)=0;
	virtual unsigned int getSize()=0;
	virtual std::string getName()=0;
	virtual void accept(AbstractFileVisitor* ptr) = 0;
	virtual AbstractFile* clone(std::string newfilename) = 0;
};
