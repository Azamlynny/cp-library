// Description: Sorts vectors radially based on angles [0, 2pi). For parallel vectors, order is arbitrary. Inclusion of (0, 0) is undefined.
// Source: https://github.com/mzhang2021/cp-library/blob/master/implementations/geometry/PolarSort.h
// Time: O(1)

#include "Point.h"

template<typename T>
bool half(const Point<T> &p) {
    return p.y < 0 || (p.y == 0 && p.x < 0);
}

template<typename T>
bool cmp(const Point<T> &p, const Point<T> &q) {
    return half(p) == half(q) ? cross(p, q) > 0 : half(p) < half(q);
}

// sort(arr.begin(), arr.end(), cmp());