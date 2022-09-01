#pragma once
//declaration of Command Prompt
//Author: Jeffrey Gong
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include <map>

class CommandPrompt {
private:
	std::map<std::string, AbstractCommand*> commands;
	AbstractFileSystem* system;
	AbstractFileFactory* fact;

public:
	CommandPrompt();
	~CommandPrompt() = default;
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	int run();

protected:
	void listCommands();
	std::string prompt();
};
