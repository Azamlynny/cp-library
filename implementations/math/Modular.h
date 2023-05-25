// Description: Common operations for modular arithmetic. Mod inverse exists only when a is coprime with m.
// Source: https://github.com/mzhang2021/cp-library/blob/master/implementations/math/ModularPrimitive.h
// Verification: 
// Time: O(log n)
// Pasteable: Segment 

const long long MOD = 1e9+7;

long long power (long long a, long long b) {
    long long ret = 1;
    while (b > 0) {
        if (b & 1)
            ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

// uses Fermat's little theorem, works when modulus is prime
long long inverse(long long a) {
    long long ret = 1, b = MOD - 2;
    while (b > 0) {
        if (b & 1)
            ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

// uses extended Euclidean algorithm
long long inverseEuclidean(long long a) {
    long long m = MOD, x = 1, y = 0;
    while (a > 1) {
        long long q = a / m, t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += MOD;
    return x;
}