#include <iostream>
using namespace std;

typedef int Elem;
class ArrayVector {
public:
    ArrayVector();
    int size() const;
    bool empty() const;
    Elem& operator[](int i);
    Elem& at(int i);
    void erase(int i);
    void insert(int i, const Elem& e);
    void reserve(int N);
private:
    int capacity;
    int n;
    Elem* A;
};

ArrayVector::ArrayVector() : capacity(0), n(0), A(NULL) { }

int ArrayVector::size() const { return n; }

bool ArrayVector::empty() const { return size() == 0; }

Elem& ArrayVector::operator[](int i) { return A[i]; }

Elem& ArrayVector::at(int i) {return A[i]; }

void ArrayVector::erase(int i) {
    for (int j = i+1; j < n; j++) {
        A[j-1] = A[j];
    }
    n--;
}

void ArrayVector::reserve(int N) {
    if (capacity >= N) {
        return;
    }
    Elem* B = new Elem[N];
    for (int j = 0; j < n; j++) {
        B[j] = A[j];
    }
    if (A != NULL) {
        delete [] A;
    }
    A = B;
    capacity = N;
}

void ArrayVector::insert(int i, const Elem& e) {
    if (n >= capacity) {
        reserve(max(1, 2 * capacity));
    }
    for (int j = n-1; j >=i; j--) {
        A[j+1] = A[j];
    }
    A[i] = e;
    n++;
}

int main() {
    ArrayVector GoldenHour;

    cout << GoldenHour.empty() << endl;

    GoldenHour.insert(1, 1);
    GoldenHour.insert(2, 2);
    cout << GoldenHour.size() << endl;
    cout << GoldenHour.at(1) << endl;
    cout << GoldenHour.at(2) << endl;

    GoldenHour.reserve(5);
    cout << GoldenHour.size() << endl;

    GoldenHour.erase(1);
    cout << GoldenHour.at(1) << endl;
}