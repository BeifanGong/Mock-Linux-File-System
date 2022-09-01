//Declaration of TouchCommand
//Author: Sherry Zhang, Jeffrey Gong
#pragma once
#include "TouchCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractCommand.h"
#include <iostream>
#include <sstream>
#include "PasswordProxy.h"

class TouchCommand : public AbstractCommand {
private:
	AbstractFileFactory* fact;
	AbstractFileSystem* system;

public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	virtual void displayInfo() override;
	virtual int execute(std::string) override;
};