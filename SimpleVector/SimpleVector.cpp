#include <iostream>
#include <vector>
#include <string>
#include <list>
using std::vector;
using namespace std;

class GoldenHour {
public:
    GoldenHour() {};
    GoldenHour(string name) : s_name(name) {};
    string getName() { return s_name; };
public:
    string s_name;
};

int main() {
    vector<GoldenHour> dlwlrma(1);

    cout << dlwlrma.empty() << endl;
    cout << dlwlrma.size() << endl;

    dlwlrma.push_back(GoldenHour("Eight"));
    dlwlrma.push_back(GoldenHour("Celebrity"));

    cout << dlwlrma.size() << endl;
    cout << dlwlrma[1].getName() << endl;

    vector<GoldenHour> iu(1);

    iu.push_back(GoldenHour("Blueming"));
    iu.push_back(GoldenHour("Above the time"));

    cout << iu.size() << endl;
    cout << iu[1].getName() << endl;
    cout << iu[2].getName() << endl;
    
}