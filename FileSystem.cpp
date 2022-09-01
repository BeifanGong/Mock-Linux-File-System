// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author: Jeffrey Gong

#include "MacroCommand.h"
#include "CommandPrompt.h"
#include "TouchCommand.h"
#include "CopyCommand.h"
#include "LSCommand.h"
#include "RemoveCommand.h"
#include "DisplayCommand.h"
#include "CatCommand.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"
#include "AbstractFileVisitor.h"
#include "MetadataDisplayVisitor.h"
#include "RenameParsingStrategy.h"
#include "CreateEditParsingStrategy.h"

int main()
{
	CommandPrompt prompt;
	AbstractFileFactory* fact = new SimpleFileFactory();
	AbstractFileSystem* system = new SimpleFileSystem();

	//Rename Command
	MacroCommand* rename = new MacroCommand(system);
	AbstractCommand* copy = new CopyCommand(system);
	AbstractCommand* remove = new RemoveCommand(system);
	rename->addCommand(copy);
	rename->addCommand(remove);
	AbstractParsingStrategy* rename_stategy = new RenameParsingStrategy();
	rename->setParseStrategy(rename_stategy);

	//Create and Edit Command
	MacroCommand* createEdit = new MacroCommand(system);
	AbstractCommand* touch = new TouchCommand(system, fact);
	AbstractCommand* cat = new CatCommand(system);
	createEdit->addCommand(touch);
	createEdit->addCommand(cat);
	AbstractParsingStrategy* ce_strategy = new CreateEditParsingStrategy();
	createEdit->setParseStrategy(ce_strategy);

	AbstractCommand* ls = new LSCommand(system);
	AbstractCommand* display = new DisplayCommand(system);

	prompt.setFileFactory(fact);
	prompt.setFileSystem(system);
	prompt.addCommand("touch", touch);
	prompt.addCommand("cp", copy);
	prompt.addCommand("ds", display);
	prompt.addCommand("ls", ls);
	prompt.addCommand("rm", remove);
	prompt.addCommand("rn", rename);
	prompt.addCommand("cat", cat);
	prompt.addCommand("ce", createEdit);

	prompt.run();	

	delete fact;
	delete system;
	delete rename;
	delete copy;
	delete touch;
	delete display;
	delete ls;
	delete cat;
	delete createEdit;
	delete remove;
	return 0;
}


