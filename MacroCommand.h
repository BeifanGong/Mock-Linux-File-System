#pragma once
//declaration of macroCommand
//Author: Jeffrey Gong
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>

class MacroCommand : public AbstractCommand {
private:
	std::vector<AbstractCommand*> commands;
	AbstractParsingStrategy* strategy;
	AbstractFileSystem* system;
public:
	MacroCommand(AbstractFileSystem*);
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
	virtual int execute(std::string) override;
	virtual void displayInfo() override;
};