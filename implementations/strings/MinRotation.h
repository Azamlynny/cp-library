// Description: Finds the lexicographically smallest rotation of a string
// Source: https://github.com/kth-competitive-programming/kactl/blob/main/content/strings/MinRotation.h
// Verification: https://cses.fi/problemset/task/1110/
// Time: O(n)
// Pasteable: Full 

// rotate(s.begin(), s.begin() + minRotation(s), s.end());
int minRotation(string s) {
	int n = s.size();
	int a = 0;
	s.append(s);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a + j == i || s[a + j] < s[i + j]) {
				i += max(0, j - 1);
				break;
			}
			if(s[a + j] > s[i + j]) {
				a = i;
				break;
			}
		}
	}
	return a;
}