#include "Linked_Binary_Tree.h"

int main() {
    LinkedBinaryTree T;
    Position p;
    Position p2;
    Position p3;
    Position p4;
    Position p_left;
    Position p_right;

    cout << "Tree Size: " << T.size() << endl;

    T.addRoot();
    cout << "Tree Size: " << T.size() << endl;

    p = T.root();
    p.setElem(100);

    T.expandExternal(p);
    p_left = p.left();
    p_left.setElem(200);
    p_right = p.right();
    p_right.setElem(300);
    cout << "Tree Size: " << T.size() << endl;

    p2 = p.left();
    T.expandExternal(p2);
    p_left = p2.left();
    p_left.setElem(400);
    p_right = p2.right();
    p_right.setElem(500);

    p3 = p.left();
    T.expandExternal(p3);
    p_left = p3.left();
    p_left.setElem(600);
    p_right = p3.right();
    p_right.setElem(700);

    p4 = p.left();
    T.expandExternal(p4);
    p_left = p4.left();
    p_left.setElem(800);
    p_right = p4.right();
    p_right.setElem(900);

    T.printPreorder();

    cout << "Height of Root : " << T.height(p) << endl;
    cout << "Depth of p2 : " << T.depth(p2) << endl;
}