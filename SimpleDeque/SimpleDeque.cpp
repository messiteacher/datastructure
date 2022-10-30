#include <iostream>
#include <deque>
using std::deque;
using namespace std;

int main() {
    deque<string> myDeque;

    cout << myDeque.empty() << endl;;

    myDeque.push_front("4");
    myDeque.push_front("5");
    cout << myDeque.front() << endl;

    myDeque.push_back("1");
    myDeque.push_back("3");
    cout << myDeque.back() << endl;

    myDeque.pop_front();
    cout << myDeque.front() << endl;

    myDeque.pop_back();
    cout << myDeque.back() << endl;

    cout << myDeque.size() << endl;;
    
}