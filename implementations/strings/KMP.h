// Description: Computes kmp pi array: longest prefix of s that ends at i
// Source: https://github.com/kth-competitive-programming/kactl/blob/main/content/strings/KMP.h
// Verification: https://cses.fi/problemset/task/2107/
// Time: O(n)
// Pasteable: Full 

vector<int> kmpfunc(string& s) {
	int n = s.size();
	vector<int> pi(n);
	for(int i = 1; i < n; i++) {
		int g = pi[i-1];
		while (g && s[i] != s[g]) g = pi[g-1];
		pi[i] = g + (s[i] == s[g]);
	}
	return pi;
}