#include <iostream>
using namespace std;

typedef string Elem;
class DNode {
private:    
    Elem elem;
    DNode* prev;
    DNode* next;
    friend class DLinkedList;
};

class DLinkedList {
public:    
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void addFront(const Elem& e);
    void addBack(const Elem& e);
    void removeFront();
    void removeBack();
    void print();
private:
    DNode* header;
    DNode* trailer;
protected:
    void add(DNode* v, const Elem& e);
    void remove(DNode* v);
};

DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList() {
    while (!empty()) removeFront();
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const { return (header->next == trailer); }

const Elem& DLinkedList::front() const { return header->next->elem; }

const Elem& DLinkedList::back() const { return trailer->prev->elem; }

void DLinkedList::add(DNode* v, const Elem& e) {
    DNode* u = new DNode;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

void DLinkedList::addFront(const Elem& e) { add(header->next, e); }

void DLinkedList::addBack(const Elem& e) { add(trailer, e); }

void DLinkedList::remove(DNode* v) {
    DNode* u = v->prev;
    DNode* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

void DLinkedList::print() {
    DNode* current = header;
    while (current != NULL) {
        cout<< current->elem << endl;;
        current = current->next;
    }
    cout << "NULL" << endl;
}

void DLinkedList::removeFront() { remove(header->next); }

void DLinkedList::removeBack() { remove(trailer->prev); }

int main() {
    DLinkedList name;
    cout << name.empty() << endl;

    name.addFront("dlwlrma");
    name.addFront("iu");
    name.addBack("younha");
    cout << name.empty() << endl;

    name.print();

    name.addBack("taeyoun");
    name.print();

    cout << name.front() << endl;
    cout << name.back() << endl;
    
    name.removeBack();
    name.print();
    
}