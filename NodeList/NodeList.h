#ifndef NodeList_h
#define NodeList_h
#include <iostream>
#include "Node.h"
#include "Iterator.h"
using namespace std;

typedef string Elem;
class NodeList {
public:
    NodeList();
    ~NodeList();
    int size() const;
    bool empty() const;
    Iterator begin() const;
    Iterator end() const;
    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void insert(const Iterator& p, const Elem& e);
    void eraseFront();
    void eraseBack();
    void erase(const Iterator& p);
    void print();
private:
    int n;
    Node* header;
    Node* trailer;
};

#endif