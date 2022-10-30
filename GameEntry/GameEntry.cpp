#include <iostream>
using namespace std;

class GameEntry {
public:
    GameEntry(const string& n = "", int s = 0);
    string getName() const;
    int getScore() const;
private:
    string name;
    int score;
};

GameEntry::GameEntry(const string& n, int s) : name(n), score(s) { }

string GameEntry::getName() const { return name; }

int GameEntry::getScore() const { return score; }

class Scores {
public:
    Scores(int maxEnt = 10);
    ~Scores();
    void add(const GameEntry& e);
    GameEntry remove(int i);
    void print();
private:
    int maxEntries;
    int numEntries;
    GameEntry* entries;
};

Scores::Scores(int maxEnt) {
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

Scores::~Scores() {
    delete[] entries;
}

void Scores::add(const GameEntry& e) {
    int newScore = e.getScore();
    if (numEntries == maxEntries) {
        if (newScore <= entries[maxEntries-1].getScore()) {
            return;
        }
    }
    else {
        numEntries++;
    }

    int i = numEntries-2;
    while ( i >= 0 && newScore > entries[i].getScore() ) {
        entries[i+1] = entries[i];
        i--;
    }
    entries[i+1] = e;
}

GameEntry Scores::remove(int i) {
    if ( (i < 0) || (i >= numEntries) ) {
        cout << "Invalid index" << endl;
    }
    GameEntry e = entries[i];
    for (int j = i+1; j < numEntries; j++) {
        entries[j-1] = entries[j];
    }
    numEntries--;
    return e;
}

void Scores::print() {
    for (int i=0; i<numEntries; i++)
		cout << i << ": name=" << entries[i].getName() << ", score=" << entries[i].getScore() << endl;
    cout << endl;
}

int main() {
    Scores s(3);
    s.add(GameEntry("messi", 100));
    s.add(GameEntry("ronaldo", 0));
    s.add(GameEntry("haaland", 70));
    s.print();

    s.remove(2);
    s.print();
}