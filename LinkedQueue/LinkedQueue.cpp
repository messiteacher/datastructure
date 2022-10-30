#include <iostream>
using namespace std;

typedef string Elem;
class CNode {
private:
    Elem elem;
    CNode* next;

    friend class CircleList;
};

class CircleList {
public:
    CircleList();
    ~CircleList();
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void advance();
    void add(const Elem& e);
    void remove();
    void print();
private:
    CNode* cursor;
};

CircleList::CircleList() : cursor(NULL) { }

CircleList::~CircleList() { while (!empty()) remove(); }

bool CircleList::empty() const { return cursor == NULL; }

const Elem& CircleList::back() const { return cursor->elem; }

const Elem& CircleList::front() const { return cursor->next->elem; }

void CircleList::advance() { cursor = cursor->next; }

void CircleList::add(const Elem& e) {
    CNode* v = new CNode;
    v->elem = e;
    if (cursor == NULL) {
        v->next = v;
        cursor = v;
    }
    else {
        v->next = cursor->next;
        cursor->next = v;
    }
}

void CircleList::remove() {
    CNode* old = cursor->next;
    if (old == cursor) {
        cursor = NULL;
    }
    else {
        cursor->next = old->next;
    }
    delete old;
}

void CircleList::print() {
    CNode* current = cursor;
    do {
        cout << current->elem << endl;
        current = current->next;
    }
    while (current != cursor);
    cout << "NULL" << endl;
}

typedef string Elem;
class LinkedQueue {
public:    
    LinkedQueue();
    int size() const;
    bool empty() const;
    const Elem& front() const;
    void enqueue(const Elem& e);
    void dequeue();
private:
    CircleList C;
    int n;
};


LinkedQueue::LinkedQueue() : C(), n(0) { }

int LinkedQueue::size() const { return n; }

bool LinkedQueue::empty() const { return n == 0; }

const Elem& LinkedQueue::front() const {
    return C.front();
}

void LinkedQueue::enqueue(const Elem& e) {
    C.add(e);
    C.advance();
    n++;
}

void LinkedQueue::dequeue() {
    C.remove();
    n--;
}



int main() {
    LinkedQueue playList;

    cout << playList.empty() << endl;

    playList.enqueue("eigth");
    playList.enqueue("celebrity");
    cout << playList.size() << endl;
    cout << playList.front() << endl;
}