//Declaration of LSCommand
//Author: Sherry Zhang, Jeffrey Gong
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

class LSCommand :public AbstractCommand {
	AbstractFileSystem* AFS;
	const int width = 21;
	const int namePerLine = 2;
	const int changeLine = 0;

public:
	LSCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
};