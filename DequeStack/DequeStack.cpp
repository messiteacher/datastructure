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

typedef string Elem;
class LinkedDeque {
public:
    LinkedDeque();
    int size() const;
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void removeFront();
    void removeBack();
private:
    DLinkedList D;
    int n;
};

LinkedDeque::LinkedDeque() : D(), n(0) { }

int LinkedDeque::size() const { return n; }

bool LinkedDeque::empty() const { return n == 0; }

const Elem& LinkedDeque::front() const { return D.front(); }

const Elem& LinkedDeque::back() const { return D.back(); }

void LinkedDeque::insertFront(const Elem& e) {
    D.addFront(e);
    n++;
}

void LinkedDeque::insertBack(const Elem& e) {
    D.addBack(e);
    n++;
}

void LinkedDeque::removeFront() {
    D.removeFront();
    n--;
}

void LinkedDeque::removeBack() {
    D.removeBack();
    n--;
}

typedef string Elem;
class DequeStack {
public:
    DequeStack();
    int size() const;
    bool empty() const;
    const Elem& top() const;
    void push(const Elem& e);
    void pop();
private:
    LinkedDeque D;
};

DequeStack::DequeStack() : D() { }

int DequeStack::size() const { return D.size(); }

bool DequeStack::empty() const { return D.empty(); }

const Elem& DequeStack::top() const { return D.front(); }

void DequeStack::push(const Elem& e) { D.insertFront(e); }

void DequeStack::pop() { D.removeFront(); }

int main() {
    DequeStack GoldenHour;
    cout << GoldenHour.empty() << endl;

    GoldenHour.push("eight");
    GoldenHour.push("celebrity");
    GoldenHour.push("dlwlrma");
    cout << GoldenHour.size() << endl;
    cout << GoldenHour.top() << endl;

    GoldenHour.pop();
    cout << GoldenHour.size() << endl;
    cout << GoldenHour.top() << endl;
}