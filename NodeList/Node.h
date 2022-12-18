#ifndef Node_h
#define Node_h
#include <iostream>
using namespace std;

typedef string Elem;
struct Node {
    Elem elem;
    Node *prev;
    Node *next;
};
#endif