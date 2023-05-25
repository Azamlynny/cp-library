// Description: For each position in a string, computes:
//                pal[0][i] = half length of longest even palindrome around pos i 
//                pal[1][i] = longest odd (half rounded down)
// Source: https://github.com/kth-competitive-programming/kactl/blob/main/content/strings/Manacher.h
// Verification: https://cses.fi/problemset/task/1111
// Time: O(n)
// Pasteable: Full 

vector<vector<int>> manacher(const string& s) {
    int n = s.size();
    vector<vector<int>> pal {vector<int>(n+1), vector<int>(n)};
    for (int z = 0; z < 2; z++) {
        for (int i = 0, l = 0, r = 0; i < n; i++) {
            int t = r - i + !z;
            if (i < r) pal[z][i] = min(t, pal[z][l+t]);
            int L = i - pal[z][i];
            int R = i + pal[z][i] - !z;
            while (L >= 1 && R + 1 < n && s[L-1] == s[R+1])
                pal[z][i]++, L--, R++;
            if (R > r) l=L, r=R;
        }
    }
    return pal;
}
