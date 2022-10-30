#include <iostream>
using namespace std;

typedef string Elem;
class SNode {
private:
    Elem elem;
    SNode* next;

    friend class SLinkedList;
};

class SLinkedList {
public:
    SLinkedList();
    ~SLinkedList();
    bool empty() const;
    const string& front() const;
    void addFront(const string& e);
    void removeFront();
    void print();
private:
    SNode* head;   
};

SLinkedList::SLinkedList() : head(NULL) { }

SLinkedList::~SLinkedList() { while (!empty()) removeFront(); }

bool SLinkedList::empty() const { return head == NULL; }

const string& SLinkedList::front() const { return head->elem; }

void SLinkedList::addFront(const string& e) {
    SNode* v = new SNode;
    v->elem = e;
    v->next = head;
    head = v;
}

void SLinkedList::removeFront() {
    SNode* old = head;
    head = old->next;
    delete old;
}

void SLinkedList::print() {
    SNode* current = head;
    while (current != NULL) {
        cout << current->elem << endl;
        current = current->next;
    }
    cout << "NULL" << endl;
}

typedef string Elem;
class LinkedStack {
public:
    LinkedStack();
    int size() const;
    bool empty() const;
    const Elem& top() const;
    void push(const Elem& e);
    void pop();
private:
    SLinkedList S;
    int n;
};

LinkedStack::LinkedStack() : S(), n(0) { }

int LinkedStack::size() const { return n; }

bool LinkedStack::empty() const { return n == 0; }

const Elem& LinkedStack::top() const { return S.front(); }

void LinkedStack::push(const Elem& e) {
    ++n;
    S.addFront(e);
}

void LinkedStack::pop() {
    --n;
    S.removeFront();
}

int main() {
    LinkedStack GoldenHour;

    cout << GoldenHour.empty() << endl;

    GoldenHour.push("eight");
    GoldenHour.push("celebrity");
    cout << GoldenHour.size() << endl;
    cout << GoldenHour.top() << endl;

    GoldenHour.pop();
    cout << GoldenHour.size() << endl;
    cout << GoldenHour.top() << endl;
}