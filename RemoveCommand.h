//Declaration of RemoveCommand
//Author: Sherry Zhang, Jeffrey Gong
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

class RemoveCommand :public AbstractCommand {
	AbstractFileSystem* AFS;


public:
	RemoveCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
};

