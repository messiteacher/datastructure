#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    stack<int> myStack;
    myStack.push(5);
    myStack.push(3);
    myStack.push(2);
    myStack.pop();

    int a = myStack.top();
    cout << a << endl;
    
    cout << myStack.top() << endl;
} 