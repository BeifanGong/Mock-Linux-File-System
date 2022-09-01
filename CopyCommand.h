//declaration of Copy Command
//Author: Jeffrey Gong
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class CopyCommand : public AbstractCommand{
private:
	AbstractFileSystem* system;
public:
	CopyCommand(AbstractFileSystem*);
	virtual int execute(std::string) override;
	virtual void displayInfo() override;
};