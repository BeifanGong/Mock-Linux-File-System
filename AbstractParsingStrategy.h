//declaration of AbstractParsingStrategy interface
//Author: Jeffrey Gong
#pragma once
#include <vector>
#include <string>

class AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string) = 0;
};
