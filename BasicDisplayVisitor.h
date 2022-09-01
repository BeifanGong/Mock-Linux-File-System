#pragma once
// declaration of BasicDisplayVisitor here
//Author: Jeffrey Gong
#include "AbstractFileVisitor.h"

class BasicDisplayVisitor : public AbstractFileVisitor{
public:
	bool result = false;
public:
	virtual void visit_TextFile(TextFile*) override;
	virtual void visit_ImageFile(ImageFile*) override;
};
