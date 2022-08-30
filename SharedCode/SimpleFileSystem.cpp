// SimpleFileSystem.cpp
// Authur: Anthony Chen, Jeffery Chai
// Email: chenerdong@wustl.edu c.jeffery@wustl.edu
// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

/// <summary>
/// Add file to existing file list (files)
/// </summary>
/// <param name="filename"> string of filename </param>
/// <param name="f"> pointer to added file </param>
/// <returns> error message </returns>
int SimpleFileSystem::addFile(string filename, AbstractFile* f) {
	if (files.find(filename) != files.end()) {
		return error::fileAlreadyExists;
	}
	if (f == nullptr) {
		return error::nullptrException;
	}
	// if none of above situation, add to existing file list
	files.insert(pair<string, AbstractFile*>(filename, f));
	return succeed;
}


/// <summary>
/// Delete File from existing file list
/// </summary>
/// <param name="name"> string file name </param>
/// <returns> error message enum </returns>
int SimpleFileSystem::deleteFile(std::string name) {
	// obtain file position in the list, return files.end() if not found
	auto p = files.find(name);
	if (p == files.end()) {
		return error::fileNotExists;
	}
	if (openFiles.find(p->second) != openFiles.end()) {
		return error::fileAlreadyOpen;
	}
	// Deletefile by destruction and remove from the list
	delete p->second;
	files.erase(files.find(name));
	return error::succeed;
}

/// <summary>
/// Open file: add the file to openFile list
/// </summary>
/// <param name="name"> string file name</param>
/// <returns> pointer to openfile </returns>
AbstractFile* SimpleFileSystem::openFile(string name) {
	// obtain file position in the list, return files.end() if not found
	auto p = files.find(name);
	if (p != files.end()) {
		// File found, but not open, open it now
		if (openFiles.find(p->second) == openFiles.end()) {
			openFiles.insert(p->second);
			return p->second;
		}
		// File found, but already opened
		else {
			return nullptr;
		}
	}
	return nullptr;
}

/// <summary>
/// Close the file give file pointer
/// </summary>
/// <param name="f"> pointer to file</param>
/// <returns> error message enum </returns>
int SimpleFileSystem::closeFile(AbstractFile* f) {
	// obtain file position in the list, return files.end() if not found
	auto p = openFiles.find(f);
	if ( p == openFiles.end()) {
		return error::fileNotOpen;
	}
	// Close the file: remove it from the openfile list
	openFiles.erase(p);
	return succeed;
}

// return a set of string consists of file names
set<string> SimpleFileSystem::getFileNames() {
	set<string> fileName;
	for (auto& pair : files) {
		fileName.insert(pair.first);
	}
	return fileName;
}