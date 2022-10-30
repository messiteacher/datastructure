#include <iostream>
using namespace std;

int recursiveFactorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * recursiveFactorial(n-1);
    }
}

int main() {
    int n = 0;
    cout << "Input number" << endl;
    cin >> n;

    int result = recursiveFactorial(n);
    cout << result << endl;
}