/*
Problem Name: Stick Divisions
Problem Link: https://cses.fi/problemset/task/1161
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
    
    int k,n; cin>>k>>n;
    int ans = 0;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        s.insert(x);
    }
    while(s.size() > 1) {
        auto x = s.begin();
        s.erase(x);
        auto y = s.begin();
        s.erase(y);
        ans += *x+*y;
        s.insert(*x+*y);
    }
    cout<<ans;
}