#include <iostream>
using namespace std;

template <typename E>
class Stack {
public:
    int size() const;
    bool empty() const;
    const E& top() const throw(StackEmpty);
    void push(const E& e);
    void pop() throw(StackEmpty);
};

class RuntimeException {
private:
    string errorMsg;
public:
    RuntimeException(const string& err) { errorMsg = err; }
    string getMessage() const { return errorMsg; }
};

class StackEmpty : public RuntimeException {
public:
    StackEmpty(const string& err) : RuntimeException(err) {}
};

int main() {
    Stack<int> s;
    s.push(8);
    s.push(10);
    cout << s.top() << endl;

    return 0;
}