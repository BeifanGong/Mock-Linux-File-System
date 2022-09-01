#pragma once
//declaration of Cat Command
//Author: Jeffrey Gong
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CatCommand : public AbstractCommand{
private:
	AbstractFileSystem* system;
public:
	CatCommand(AbstractFileSystem*);
	virtual int execute(std::string) override;
	virtual void displayInfo() override;
};
