// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"

using namespace std;

void BasicDisplayVisitor::visit_ImageFile(ImageFile* ptr) {
    vector<char> contents = ptr->read();
    for (int x = static_cast<int>(ptr->getLength())-1; x >= 0; --x) {
        for (int y = 0; y < static_cast<int>(ptr->getLength()); ++y) {
            int index = x * static_cast<int>(ptr->getLength()) + y;
            cout << contents[index];
        }
        cout << endl;
    }
}
void BasicDisplayVisitor::visit_TextFile(TextFile* ptr) {
    vector<char> contents = ptr->read();
    for (unsigned int i = 0; i < contents.size(); i++) {
        cout << contents[i];
    }
    cout << std::endl;
}