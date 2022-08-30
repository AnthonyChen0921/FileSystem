#pragma once
// declaration of MetadataDisplayVisitor here

#include "BasicDisplayVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	void visit_ImageFile(ImageFile* ptr);
	void visit_TextFile(TextFile* ptr);
};
