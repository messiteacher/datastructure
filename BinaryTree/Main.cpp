#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {
    LinkedBinaryTree tree;

    cout << tree.empty() << endl;
    tree.addRoot();

    cout << tree.size() << endl;
}