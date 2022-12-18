#include "NodeList.h"
#include <iostream>
using namespace std;

NodeList::NodeList() {
    n = 0;
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

NodeList::~NodeList(){}

int NodeList::size() const { return n;}

bool NodeList::empty() const { return (n==0); }

Iterator NodeList::begin() const { return Iterator(header->next); }

Iterator NodeList::end() const { return Iterator(trailer); }

void NodeList::insert(const Iterator& p, const Elem& e) {
    Node* w = p.v;
    Node* u = w->prev;
    Node* v = new Node;
    v->elem = e;
    v->next = w;
    w->prev = v;
    v->prev = u;
    u->next = v;
    n++;
}

void NodeList::insertFront(const Elem& e) { insert(begin(), e); }

void NodeList::insertBack(const Elem& e) { insert(end(), e); }

void NodeList::erase(const Iterator& p) {
    Node* v = p.v;
    Node* w = v->next;
    Node* u = v->prev;
    u->next = w;
    w->prev = u;
    delete v;
    n--;
}

void NodeList::eraseFront() { erase(begin()); }

void NodeList::eraseBack() {erase(--end()); }

void NodeList::print() {
    Node* current = header;
    while (current != NULL) {
        cout<< current->elem << endl;
        current = current->next;
    }
    cout << "NULL" << endl;
}