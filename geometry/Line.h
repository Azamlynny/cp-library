// Source: Adapted from https://github.com/mzhang2021/cp-library/blob/master/implementations/geometry/Line.h

template<typename T>
struct Line {
    Point<T> a, b, ab;

    Line() {}

    Line(const Point<T> &_a, const Point<T> &_b) : a(_a), b(_b), ab(b - a) {}

    // ax + by = c
    Line(T _a, T _b, T _c) : ab(_b, -_a) {
        if (_a != 0) a = b = Point<T>(_c / _a, 0);
        else if (_b != 0) a = b = Point<T>(0, _c / _b);
        else if (_c == 0) a = b = Point<T>();
        else a = b = Point<T>(numeric_limits<T>::max(), numeric_limits<T>::max());
    }

    friend bool onLine(const Point<T> &p, const Line &l) {
        if (l.a == l.b) return p == l.a;
        return cross((p - l.a), l.ab) == 0;
    }

    friend bool onSegment(const Point<T> &p, const Line &s) {
        if (s.a == s.b) return p == s.a;
        Point<T> va = s.a - p, vb = s.b - p;
        return cross(va, vb) == 0 && dot(va, vb) <= 0;
    }
  
    friend ostream& operator << (ostream &os, const Line &l) {
        return os << "<" << l.a.x << ", " << l.a.y << "> + <" << l.ab.x << ", " << l.ab.y << ">";
    }
};