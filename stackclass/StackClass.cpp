#include <iostream>
#include <stack>
using namespace std;

class intStack {
    enum { size = 10; }
    int top;
    int buf[size];
public:
    intStack() : top{ size } {} 
    bool chkEmpty() const {  
        return top == size;
    }
    bool chkFull() const {   
        return !top;
    }
    bool push(string ch);  
    int pop();  

};

class stringStack {
    enum { size = 10; }
    int top;
    string buf[size];
public:
    stringStack() : top{ size } {} 
    bool chkEmpty() const {  
        return top == size;
    }
    bool chkFull() const {   
        return !top;
    }
    bool push(string ch);  
    string pop();   
};

int main() {

}