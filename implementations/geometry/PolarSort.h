// Description: Sorts vectors radially based on angles [0, 2pi). For parallel vectors, order is arbitrary. Inclusion of (0, 0) is undefined.
// Source: https://github.com/mzhang2021/cp-library/blob/master/implementations/geometry/PolarSort.h
// Time: O(1)

#include "Point.h"

template<typename T>
bool half(const Point<T> &p) {
    return p.y < 0 || (p.y == 0 && p.x < 0);
}

template<typename T>
bool polar_cmp(const Point<T> &p, const Point<T> &q) {
    return half(p) == half(q) ? cross(p, q) > 0 : half(p) < half(q);
}

// Polar sort by counterclockwise, then by distance from origin.
template<typename T>
bool polarDist_cmp(const Point<T> &p, const Point<T> &q) {
    return half(p) == half(q) ? (cross(p, q) == 0 ? p.mag2() < q.mag2() : cross(p, q) > 0) : half(p) < half(q);
}

// sort(pts.begin(), pts.end(), polar_cmp<T>);