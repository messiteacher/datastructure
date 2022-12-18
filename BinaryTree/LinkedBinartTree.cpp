#include "BinaryTree.h"
#include <iostream>
#include <list>
using namespace std;

LinkedBinaryTree::LinkedBinaryTree() : _root(NULL), n(0) { }

int LinkedBinaryTree::size() const { return n; }

bool LinkedBinaryTree::empty() const { return size() == 0; }

LinkedBinaryTree::Position LinkedBinaryTree::root() const { return Position(_root); }

void LinkedBinaryTree::addRoot() { _root = new Node; n = 1; }

void LinkedBinaryTree::expandExternal(const Position& p) {
    Node* v = p.v;
    v->left = new Node;
    v->left->par = v;
    v->right = new Node;
    v->right->par = v;
    n += 2;
}

LinkedBinaryTree::Position

LinkedBinaryTree::removeAboveExternal(const Position& p) {
    Node* w = p.v;
    Node* v = w->par;
    Node* sib = (w == v->left ? v->right : v->left);
    if (v == _root) {
        _root = sib;
        sib->par = NULL;
    }
    else {
        Node* gpar = v->par;
        if (v == gpar->left) gpar->left = sib;
        else gpar->right = sib;
        sib->par = gpar;
    }
    delete w;
    delete v;
    n -= 2;
    return Position(sib);
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const {
    PositionList pl;
    preorder(_root, pl);
    return PositionList(pl);
}

void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const {
    pl.push_back(Position(v));
    if (v->left != NULL) {
        preorder(v->left, pl);
    }
    if (v->right != NULL){
        preorder(v->right, pl);
    }
}