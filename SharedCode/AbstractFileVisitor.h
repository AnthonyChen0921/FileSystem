#pragma once
// declaration of the file visitor interface here
class AbstractFile;
class ImageFile;
class TextFile;

class AbstractFileVisitor {
public:
	virtual void visit_ImageFile(ImageFile* ptr) = 0;
	virtual void visit_TextFile(TextFile* ptr) = 0;
};