#ifndef Linked_Binary_Tree_h
#define Linked_Binary_Tree_h
#include "Node.h"
#include "Position.h"

class LinkedBinaryTree {
public:
    LinkedBinaryTree();
    int size() const;
    bool empty() const;
    Position root() const;
    PositionList positions() const;
    void addRoot();
    void expandExternal(const Position& p);
    Position removeAboveExternal(const Position& p);
    void printPreorder();
    int height(const Position& p);
    int depth(const Position& p);
protected:
    void preorder(Node* v, PositionList& pl) const;
private:
    Node* _root; 
    int n;
};  

#endif