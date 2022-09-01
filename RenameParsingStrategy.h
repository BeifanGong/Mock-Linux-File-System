#pragma once
//declaration of RenameParsingStrategy
//Author: Jeffrey Gong
#include "AbstractParsingStrategy.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string) override;
};