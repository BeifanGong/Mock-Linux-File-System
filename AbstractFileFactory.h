#pragma once
//file factory interface declared here
//Author: Jeffrey Gong
#include "AbstractFile.h"

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string) = 0;

    virtual ~AbstractFileFactory() = default;
};
