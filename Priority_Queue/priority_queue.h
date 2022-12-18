#ifndef p_queue_h
#define p_queue_h
#include <iostream>
using namespace std;
typedef double elem;

class Point2D {
private:
    elem _x;
    elem _y;
public:
    Point2D(elem x, elem y) : _x(x), _y(y) {}
    elem getX() const { return _x; }
    elem getY() const { return _y; }
    friend ostream& operator<<(ostream& os, const Point2D& obj); 
};

ostream& operator<<(ostream& os, const Point2D& obj) {
    os << obj.getX() << " , " << obj.getY();
    return os;
}

class LeftRight {
public:
    bool operator()(const Point2D& p, const Point2D& q) const {
        return p.getX() < q.getX();
    }
};

class RightLeft {
public:
    bool operator()(const Point2D& p, const Point2D& q) const {
        return !(p.getX() < q.getX());
    }
};

class BottomTop {
public:
    bool operator()(const Point2D& p, const Point2D& q) const {
        return p.getY() < q.getY();
    }
};

#endif