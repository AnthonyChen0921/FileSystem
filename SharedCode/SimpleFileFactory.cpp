// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

/// <summary>
/// Construct new file given name
/// </summary>
/// <param name="name"> string name </param>
/// <returns> pointer to AbstractFile </returns>
AbstractFile* SimpleFileFactory::createFile(string name) {
	// Find filename extension breakpoint
	int place = static_cast<int> (name.find_first_of("."));
	int extented_place = place + 1;
	if (place == string::npos) {
		cout << "NoFileExtention" << endl;
		return nullptr;
	}

	// obtain extension string
	string extention = name.substr(extented_place);
	string name_without = name.substr(0, place);

	// Given different extension name, 
	// construct different file class and add to existing file list
	// --------------------------------------------
	// txt case
	if (extention == "txt") {
		TextFile* t = new TextFile(name);
		return t;
	}
	// img case
	else if (extention == "img") {
		ImageFile* i = new ImageFile(name);
		return i;
	}
	else {
		cout << "FileTypeNotSupported" << endl;
		return nullptr;
	}
}