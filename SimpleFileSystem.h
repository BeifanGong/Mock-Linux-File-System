#pragma once
// declaration of SimpleFileSystem class goes here
//Author: Jeffrey Gong
#include "AbstractFileSystem.h"
#include <map>
#include <set>

class SimpleFileSystem : public AbstractFileSystem{
private:
	std::map<std::string, AbstractFile*> all;
	std::set<AbstractFile*> open;

public:
	virtual int addFile(std::string, AbstractFile*) override;
	virtual AbstractFile* openFile(std::string) override;
	virtual int closeFile(AbstractFile*) override;
	virtual int deleteFile(std::string) override;
	virtual std::set<std::string> getFileNames() override;
	virtual ~SimpleFileSystem();
};