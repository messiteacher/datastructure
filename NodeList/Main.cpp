#include "NodeList.h"
#include "Iterator.h"
#include "NodeList.h"
#include <iostream>
using namespace std;

int main() {
    NodeList l;
    l.insertFront("a");
    l.insertFront("b");
    l.insertFront("c");
    l.insertFront("d");
    Iterator it;
    it = l.begin();
    ++it;
    ++it;
    l.insert(it, "dlwlrma");

    cout << "-------- insert 5 elements --------" << endl;
    cout << "size : " << l.size() << endl;
    for (it = l.begin(); it != l.end(); ++it) {
            cout << *(it) << endl;
    }

    l.eraseBack();
    l.eraseFront();
    it = l.begin();
    ++it;
    l.erase(it);

    cout << "-------- erase 3 elements --------" << endl;
    cout << "size : " << l.size() << endl;
    for (Iterator it = l.begin(); it != l.end(); ++it) {
        cout << *(it) << endl;
    }

    cout << "empty : " << l.empty() << endl;
}