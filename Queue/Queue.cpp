#include <iostream>
#include <queue>
using std::queue;
using namespace std;

int main() {
    queue<float> myQueue;
    
    myQueue.push(5);
    myQueue.push(3);
    cout << myQueue.front() << endl;
    myQueue.pop();
    cout << myQueue.front() << endl;
}