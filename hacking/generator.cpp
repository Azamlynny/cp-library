#include <bits/stdc++.h>  
using namespace std;

#ifdef LOCAL
#include "../cp-library/debug/debug.h"
#endif

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define pb push_back
#define endl "\n" 



void solve() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = 1000;
	cout << t << endl;
	for(int i = 0; i < t; i++) {
		ll n = 1e11;
        ll nv = uniform_int_distribution<int>(1, n)(rng);
        cout << nv << " ";
        ll kv = 2;
        while(kv == 2) {
            kv = uniform_int_distribution<int>(1, nv)(rng);
        }
        cout << kv << endl;
	}
}
  
    
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cout.precision(20);
	int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
} 
