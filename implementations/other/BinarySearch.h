// Time: O(log n)

// long long lowerBound(int x) {
long long l = 0;
long long r = n;
while (l < r) {
    long long m = (r - l) / 2 + l;

    if (arr[m] < x) {
        l = m + 1;
    } else {
        r = m;
    }
}
return l;

// int upperBound(int x) {
long long l = 0;
long long r = n;
while (l < r) {
    long long m = (r - l) / 2 + l;

    if (arr[m] > x) {
        r = m;
    } else {
        l = m + 1;
    }
}
return l - 1;
