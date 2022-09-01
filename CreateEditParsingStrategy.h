#pragma once
//declaration of our own macro command's parsing strategy: createEditParsingStrategy
//Author: Jeffrey Gong
#include "AbstractParsingStrategy.h"

class CreateEditParsingStrategy : public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string);
};
