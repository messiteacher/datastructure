#include <iostream>
#include <queue>
#include "priority_queue.h"

int main() {
    priority_queue<int>  pl;

    priority_queue<Point2D, vector<Point2D>, LeftRight> p2;
    p2.push(Point2D(8.5, 4.6));
    p2.push(Point2D(1.3, 5.7));
    p2.push(Point2D(2.5, 0.6));

    cout << p2.top() << endl; p2.pop();
    cout << p2.top() << endl; p2.pop();
    cout << p2.top() << endl; p2.pop();

    return EXIT_SUCCESS;
}