#ifndef Iterator_h
#define Iterator_h
#include <iostream>
#include "Node.h"
#include "NodeList.h"
using namespace std;

typedef string Elem;
class Iterator {
public:
    Iterator();
    ~Iterator();
    Elem& operator*();
    bool operator==(const Iterator& p) const;
    bool operator!=(const Iterator& p) const;
    Iterator& operator++();
    Iterator& operator--();
    friend class NodeList;
private:
    Node* v;
    Iterator(Node* u);
};
#endif