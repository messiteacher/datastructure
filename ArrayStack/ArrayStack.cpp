#include <iostream>
using namespace std;

template <typename E>
class ArrayStack {
    enum { DEF_CAPACITY = 100 };
public:
    ArrayStack(int cap = DEF_CAPACITY);
    int size() const;
    bool empty() const;
    const E& top() const;
    void push(const E& e);
    void pop();
private:
    E* S;
    int capacity;
    int t;
};

template <typename E> ArrayStack<E>::ArrayStack(int cap) : S(new E[cap]), capacity(cap), t(-1) { }

template <typename E> int ArrayStack<E>::size() const { return (t+1); }

template <typename E> bool ArrayStack<E>::empty() const { return (t<0); }

template <typename E>
const E& ArrayStack<E>::top() const {
    return S[t];
}

template <typename E>
void ArrayStack<E>::push(const E& e) {
    S[++t] = e;
}

template <typename E>
void ArrayStack<E>::pop() {  
    --t;
}

int main() {
    ArrayStack<int> A;
    A.push(7);
    A.push(13);
    cout << A.top() << endl; A.pop();
    A.push(9);
    cout << A.top() << endl;
    cout << A.top() << endl; A.pop();
    ArrayStack<string> B(10);
    B.push("Bob");
    B.push("Alice");
    cout << B.top() << endl; B.pop();
    B.push("Eve");
}