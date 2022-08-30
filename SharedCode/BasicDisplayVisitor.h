#pragma once
// declaration of BasicDisplayVisitor here

#include "AbstractFileVisitor.h"
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"

class BasicDisplayVisitor : public AbstractFileVisitor{
public:
	void visit_ImageFile(ImageFile* ptr);
	void visit_TextFile(TextFile* ptr);
};