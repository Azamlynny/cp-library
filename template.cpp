#include <bits/stdc++.h>  
using namespace std;

template<typename T>ostream&operator<<(ostream&out,const vector<T>&vec){if(vec.empty()){out<<"[]";return out;}out<<'[';for(int i=0;i<(int)vec.size()-1;i++){out<<vec[i]<<", ";}return out<<vec.back()<<']';}
template<typename T>ostream&operator<<(ostream&out,const set<T>&set){out<<'{';for(auto it=set.begin();it!=set.end();it++){T element=*it;out<<element;if(next(it)!=set.end()){out<<", ";}}return out<<'}';}
template<typename T>ostream&operator<<(ostream&out,const unordered_set<T>&set){out<<'{';for(auto it=set.begin();it!=set.end();it++){T element=*it;out<<element;if(next(it)!=set.end()){out<<", ";}}return out<<'}';}
template<typename T>ostream&operator<<(ostream&out,const multiset<T>&set){out<<'{';for(auto it=set.begin();it!=set.end();it++){T element=*it;out<<element;if(next(it)!=set.end()){out<<", ";}}return out<<'}';}
template<typename T>ostream&operator<<(ostream&out,const unordered_multiset<T>&set){out<<'{';for(auto it=set.begin();it!=set.end();it++){T element=*it;out<<element;if(next(it)!=set.end()){out<<", ";}}return out<<'}';}
template<typename T1,typename T2>ostream&operator<<(ostream&out,const pair<T1,T2>&pair){return out<<'('<<pair.first<<", "<<pair.second<<')';}

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define pb push_back
#define endl "\n" 


void solve() {
	
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
