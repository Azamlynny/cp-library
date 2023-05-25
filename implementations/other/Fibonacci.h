// Description: Finds n-th Fibonnaci number using matrix exponentiation
// Source: https://cp-algorithms.com/algebra/fibonacci-numbers.html#closed-form-expression
// Verification https://cses.fi/problemset/task/1722
// Time: O(log n)
// Pasteable: Full 

const long long MOD = 1e9+7;

struct matrix {
    long long mat[2][2];
    matrix friend operator *(const matrix &a, const matrix &b){
        matrix c;
        c.mat[0][0] = (a.mat[0][0] * b.mat[0][0] + a.mat[0][1] * b.mat[1][0]) % MOD;
        c.mat[1][0] = (a.mat[1][0] * b.mat[0][0] + a.mat[1][1] * b.mat[1][0]) % MOD;
        c.mat[0][1] = (a.mat[0][0] * b.mat[0][1] + a.mat[0][1] * b.mat[1][1]) % MOD;
        c.mat[1][1] = (a.mat[1][0] * b.mat[0][1] + a.mat[1][1] * b.mat[1][1]) % MOD;
        return c;
    }
};

matrix matpow(matrix base, long long n) {
    matrix ans{ {
      {1, 0},
      {0, 1}
    } };
    while (n) {
        if(n & 1)
            ans = ans * base;
        base = base * base;
        n >>= 1;
    }
    return ans;
}

long long fib(long long n) {
    matrix base{ {
      {1, 1},
      {1, 0}
    } };
    return matpow(base, n).mat[0][1];
}
