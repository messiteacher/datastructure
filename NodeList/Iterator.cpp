#include "NodeList.h"
#include "Iterator.h"
#include <iostream>
using namespace std;

Iterator::Iterator(){};

Iterator::Iterator(Node *u) : v(u){};

Iterator::~Iterator(){};

Elem& Iterator::operator*() { return v->elem; }

bool Iterator::operator==(const Iterator& p) const { return v == p.v; }

bool Iterator::operator!=(const Iterator& p) const { return v != p.v; }

Iterator& Iterator::operator++() { 
    v = v->next;
    return *this;
}

Iterator& Iterator::operator--() {
    v = v->prev; return *this;
}