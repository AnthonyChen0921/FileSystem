// TextFile.cpp
// Authur: Anthony Chen, Jeffery Chai
// Email: chenerdong@wustl.edu c.jeffery@wustl.edu
//  Define the TextFile class here
#include "TextFile.h"
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

// Constructor of Textfile, store string name
TextFile::TextFile(std::string n) 
    :name(n){}

// Print out the contents of vector
vector<char> TextFile::read() {
    return contents;
}

// Write to member variable given input vector
int TextFile::write(std::vector<char> v) {
    contents = v;
    return succeed;
}

// Add every element to member variable vector
int TextFile::append(std::vector<char> v) {
    for (unsigned int i = 0; i < v.size(); i++) {
        contents.push_back(v[i]);
    }
    return succeed;
}

// return size of member variable vector
unsigned int TextFile::getSize() {
    return static_cast<unsigned int>(contents.size());
}

// return file name
std::string TextFile::getName() {
    return name;
}

void TextFile::accept(AbstractFileVisitor* ptr) {
    if (ptr) {
        ptr->visit_TextFile(this);
    }
}

AbstractFile* TextFile::clone(std::string newfilename) {
    newfilename = newfilename + ".txt";
    TextFile* text_copy = new TextFile(newfilename);
    text_copy->write(contents);
    return text_copy;
}