#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
//Author: Jeffrey Gong

#include <vector>
#include <string>
#include "AbstractFileVisitor.h"

class AbstractFile {
public:
	virtual std::vector<char> read() = 0;
	virtual int write(std::vector<char>) = 0;
	virtual int append(std::vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
	virtual ~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor*) = 0;

	virtual AbstractFile* clone(std::string name) = 0;
};
