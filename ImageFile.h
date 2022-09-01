#pragma once
// Image file class declaration here
//Author: Jeffrey Gong
#include "AbstractFile.h"
#include <string>
#include <vector>

class ImageFile :public AbstractFile {
private:
	std::string name;
	std::vector<char> contents;
	char size;

public:
	ImageFile(std::string );
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual std::vector<char> read() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string) override;
};