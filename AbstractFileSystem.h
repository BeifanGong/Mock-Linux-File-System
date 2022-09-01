#pragma once
// declaration of the interface all file systems provide goes here
//Author: Jeffrey Gong
#include <string>
#include "AbstractFile.h"
#include <set>

class AbstractFileSystem {
public:
	virtual int addFile(std::string, AbstractFile*) = 0;
	virtual int deleteFile(std::string) = 0;
	virtual AbstractFile* openFile(std::string) = 0;
	virtual int closeFile(AbstractFile*) = 0;
	virtual ~AbstractFileSystem() = default;
	virtual std::set<std::string> getFileNames() = 0;
};