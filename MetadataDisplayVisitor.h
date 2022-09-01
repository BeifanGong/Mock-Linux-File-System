#pragma once
// declaration of MetadataDisplayVisitor here
//Author: Jeffrey Gong
#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
private:
	const int width = 21;
public:
	virtual void visit_TextFile(TextFile*) override;
	virtual void visit_ImageFile(ImageFile*) override;
};