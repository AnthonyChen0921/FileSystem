// ImageFile.cpp
// Authur: Anthony Chen, Jeffery Chai
// Email: chenerdong@wustl.edu c.jeffery@wustl.edu
// definition of ImageFile class here
#pragma once
#include "ImageFile.h"
#include <iostream>
#include <iterator>

using namespace std;

// ImageFile constructor, take in string of name and initialize size to be 0
ImageFile::ImageFile(string n) {
	name = n;
	size = '0';
}

/// <summary>
/// Helper: Return vector index given 2 coordinates
/// </summary>
/// <param name="x"> x-coordinate </param>
/// <param name="y"> y-coordinate </param>
/// <returns></returns>
int ImageFile::coordinatesToIndex(int x, int y) {
    return y * (size-'0') + x;
}

/// <summary>
/// Print out the member variable vector
/// </summary>
vector<char> ImageFile::read() {
    return contents;
}

/// <summary>
/// Write the given vector into member variable
/// </summary>
/// <param name="v"> Incoming vector </param>
/// <returns> error messages enum </returns>
int ImageFile::write(std::vector<char> v) {
    char temp = v.back();
    if (temp < '0' || temp > '9') {
        return error::sizeMismatch;
    }
    else {
        size = temp;
    }
    
    int intsize = size - '0';
    if ((intsize * intsize) != static_cast<int>(v.size()) - 1) {
        return error::sizeMismatch;
    }

    for (unsigned int i = 0; i < v.size()-1; ++i) {
        if (v[i] != 'X' && v[i] != ' ') {
            contents.clear();
            size = '0';
            return error::ImageWrong;
        }
        contents.push_back(v[i]);
    }
    return error::succeed;
}

// Not supported in ImageFile Class
int ImageFile::append(std::vector<char> v) {
    return error::appendNotSupported;
}

// return the member variable vector size
unsigned int ImageFile::getSize() {
    return (size - '0') * (size - '0');
}

// return length
unsigned int ImageFile::getLength() {
    return size - '0';
}

// return the member varaible name of the file
std::string ImageFile::getName() {
    return name;
}

void ImageFile::accept(AbstractFileVisitor* ptr) {
    if (ptr) {
        ptr->visit_ImageFile(this);
    }
}

AbstractFile* ImageFile::clone(std::string newfilename) {
    newfilename = newfilename + ".img";
    ImageFile* image_copy = new ImageFile(newfilename);
    vector<char> content_copy = contents;
    content_copy.push_back(size);
    image_copy->write(content_copy);
    return image_copy;
}