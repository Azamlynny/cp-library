// Time: O(log n)

long long lowerBound(int x) {
    long long l = 0
    long long r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] < x) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

int upperBound(int x) {
    int l = 0
    int r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] > x) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l - 1;
}