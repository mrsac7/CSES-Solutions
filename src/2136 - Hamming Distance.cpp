/*
Problem Name: Hamming Distance
Problem Link: https://cses.fi/problemset/task/2136
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n,k; cin>>n>>k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
    	string s; cin>>s;
    	reverse(s.begin(), s.end());
    	for (int j = 0; j < s.size(); j++) {
    		v[i] += (s[j] == '1')*(1<<j);
    	}
    }
    int ans = 32;
    for (int i = 0; i < n; i++) {
    	for (int j = i+1; j < n; j++) {
    		ans = min(ans, (int) __builtin_popcount(v[i]^v[j]));
    	}
    }
    cout<<ans;
}