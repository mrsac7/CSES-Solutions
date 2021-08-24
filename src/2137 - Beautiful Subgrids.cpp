/*
Problem Name: Beautiful Subgrids
Problem Link: https://cses.fi/problemset/task/2137
Author: Sachin Srivastava (mrsac7)
*/
#pragma GCC target("popcnt")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin >> n;
    vector<bitset<3000>> v(n);
    for (auto &i: v)
        cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int cnt = (v[i]&v[j]).count();
            ans += cnt * (cnt - 1) / 2;
        }
    }
    cout << ans;
}