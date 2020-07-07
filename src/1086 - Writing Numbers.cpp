/*
Problem Name: Writing Numbers
Problem Link: https://cses.fi/problemset/task/1086
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

bool check(int n, int k) {
    int ans = 0;
    for (int i = 1; i <= n; i*=10) {
        int d = i*10;
        ans += n/d*i + min(max(n%d-i+1,0LL), i);
    }
    if (ans <= k) return 1;
    return 0;
}   
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int k; cin>>k;
    int l = 1, h = 6e17;
    int ans = 1;
    while(l <= h ) {
        int m = (l+h)/2;
        if (check(m, k)) {
            ans = m;
            l = m + 1;
        }
        else h = m - 1;
    }
    cout<<ans;
}