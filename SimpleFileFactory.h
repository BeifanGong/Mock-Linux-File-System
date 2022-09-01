#pragma once
//simplefilefactory class declaration goes here
//Author: Jeffrey Gong
#include "AbstractFileFactory.h"

class SimpleFileFactory :public AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string) override;
};