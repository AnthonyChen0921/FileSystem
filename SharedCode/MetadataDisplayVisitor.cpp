// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"

using namespace std;

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* ptr) {
    cout << ptr->getName()  << " image " << ptr->getSize() << endl;
}
void MetadataDisplayVisitor::visit_TextFile(TextFile* ptr) {
    cout << ptr->getName()  << " text " << ptr->getSize() << endl;
}