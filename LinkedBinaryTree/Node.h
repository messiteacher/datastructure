#ifndef Node_h
#define Node_h
#include <iostream>

using namespace std;
typedef int Elem;

class Node {
public:
    Node() : elt(), par(NULL), left(NULL), right(NULL) { }
private:
    Elem elt;
    Node* par;
    Node* left;
    Node* right;
    
    friend class Position;
    friend class LinkedBinaryTree;
};

#endif