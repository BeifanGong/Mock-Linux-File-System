#pragma once
//declaration of DisplayCommand
//Author: Jeffrey Gong
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand{
private:
	AbstractFileSystem* system;

public:
	DisplayCommand(AbstractFileSystem*);
	virtual int execute(std::string) override;
	virtual void displayInfo() override;
};