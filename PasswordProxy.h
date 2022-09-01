#pragma once
//declaration of PasswordProxy
//Author: Jeffrey Gong
#include "AbstractFile.h"
#include "AbstractFileVisitor.h"
#include <string>

class PasswordProxy : public AbstractFile {
private:
	AbstractFile* realFile;
	std::string password;
	bool checkPassword(std::string);
public:
	PasswordProxy(AbstractFile*, std::string);
	~PasswordProxy();
	std::string passwordPrompt();
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string name) override;
};