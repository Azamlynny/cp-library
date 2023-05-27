// Description: Computes Z-array: longest substring of s that begins at position i and ia a prefix of s
// Source: https://cses.fi/book/book.pdf
// Verification: https://cses.fi/problemset/task/2107/
// Time: O(n)
// Pasteable: Full 

vector<int> zfunc(string& s) {
	int n = s.size();
	vector<int> z(n);
	int x = 0, y = 0;
	for (int i = 1; i < n; i++) {
		z[i] = max(0, min(z[i-x],y-i+1));
		while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
			x = i; y = i+z[i]; z[i]++;
		}
	}
	return z;
}