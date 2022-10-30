#include <iostream>
using namespace std;

class StringNode {
private:
    string elem;
    StringNode* next;

    friend class StringLinkedList;
};

class StringLinkedList {
public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty() const;
    const string& front() const;
    void addFront(const string& e);
    void removeFront();
    int listLength();
    void print();
private:
    StringNode* head;   
};

StringLinkedList::StringLinkedList() : head(NULL) { }

StringLinkedList::~StringLinkedList() { while (!empty()) removeFront(); }

bool StringLinkedList::empty() const { return head == NULL; }

const string& StringLinkedList::front() const { return head->elem; }

void StringLinkedList::addFront(const string& e) {
    StringNode* v = new StringNode;
    v->elem = e;
    v->next = head;
    head = v;
}

void StringLinkedList::removeFront() {
    StringNode* old = head;
    head = old->next;
    delete old;
}

int StringLinkedList::listLength() {
    int length = 0;
    StringNode* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

void StringLinkedList::print() {
    StringNode* current = head;
    while (current != NULL) {
        cout << current->elem << endl;
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    StringLinkedList name;
    cout << name.empty() << endl;

    name.addFront("dlwlrma");
    cout << name.listLength() << endl;

    name.addFront("iu");
    name.addFront("younha");
    cout << name.empty() << endl;;

    name.print();

    name.removeFront();
    name.print();
}