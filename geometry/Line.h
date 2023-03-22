// Source: Adapted from https://github.com/mzhang2021/cp-library/blob/master/implementations/geometry/Line.h

#include "Point.h"

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

    friend bool pointOnLine(const Point<T> &p, const Line &l) {
        if (l.a == l.b) return p == l.a;
        return cross((p - l.a), l.ab) == 0;
    }

    friend bool pointOnSegment(const Point<T> &p, const Line &s) {
        if (s.a == s.b) return p == s.a;
        Point<T> va = s.a - p, vb = s.b - p;
        return cross(va, vb) == 0 && dot(va, vb) <= 0;
    }

    friend bool findLineIntersect(const Line &s, const Line &t, Point<double> &p) {
        T w = cross(s.ab, t.ab);
        if (w == 0) {
            p = Point<double>(numeric_limits<double>::max(), numeric_limits<double>::max());
            return pointOnLine(s.a, t);
        }
        p = Point<double>(s.ab * (cross(t.a, t.ab) + cross(t.ab, s.a))) / (double) w + s.a;
        return true;
    }

    friend bool findSegmentIntersect(const Line &s, const Line &t, Point<double> &p) {
        T w = cross(s.a - s.b, t.a - s.b), x = cross(s.a - s.b, t.b - s.b), y = cross(t.a - t.b, s.a - t.b), z = cross(t.a - t.b, s.b - t.b);
        if ((w > 0) != (x > 0) && (y > 0) != (z > 0))
            return findLineIntersect(s, t, p);
        if (w == 0 && pointOnSegment(t.a, s)) {
            p = t.a;
            return true;
        }
        if (x == 0 && pointOnSegment(t.b, s)) {
            p = t.b;
            return true;
        }
        if (y == 0 && pointOnSegment(s.a, t)) {
            p = s.a;
            return true;
        }
        if (z == 0 && pointOnSegment(s.b, t)) {
            p = s.b;
            return true;
        }
        return false;
    }

    friend bool lineIntersect(const Line &s, const Line &t) {
        T w = cross(s.ab, t.ab);
        if (w == 0)
            return pointOnLine(s.a, t);
        return true;
    }

    friend bool segmentIntersect(const Line &s, const Line &t) {
        T w = cross(s.a - s.b, t.a - s.b), x = cross(s.a - s.b, t.b - s.b), y = cross(t.a - t.b, s.a - t.b), z = cross(t.a - t.b, s.b - t.b);
        if ((w > 0) != (x > 0) && (y > 0) != (z > 0))
            return linelineIntersect(s, t, p);
        return ((w == 0 && pointOnSegment(t.a, s)) || (x == 0 && pointOnSegment(t.b, s)) || (y == 0 && pointOnSegment(s.a, t)) || (z == 0 && pointOnSegment(s.b, t)));
    }

    friend double distPointLine(const Point<T> &p, const Line &l) {
        if (l.a == l.b) return dist(p, l.a);
        return abs(cross(p - l.a, l.ab)) / l.ab.mag();
    }

    friend double distPointSegment(const Point<T> &p, const Line &s) {
        if (dot(p - s.a, s.ab) <= 0) return dist(p, s.a);
        if (dot(p - s.b, s.ab) >= 0) return dist(p, s.b);
        return distPointLine(p, s);
    }

    friend double distSegmentSegment(const Line& s, const Line& t) {
        return min({distPointSegment(s.a, t), distPointSegment(s.b, t), distPointSegment(t.a, s), distPointSegment(t.b, s)});
    }

    friend Point<T> proj(const Point<T> &p, const Line &l) {
        Point<T> ret = l.a;
        if (l.a != l.b) ret += l.ab * dot(p - l.a, l.ab) / l.ab.mag2();
        return ret;
    }

    friend Point<T> reflect(const Point<T> &p, const Line &l) {
        return proj(p, l) * 2 - p;
    }

    friend ostream& operator << (ostream &os, const Line &l) {
        return os << "{(" << l.a.x << ", " << l.a.y << ") + (" << l.ab.x << ", " << l.ab.y << ")}";
    }
};