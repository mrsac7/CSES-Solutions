/*
Problem Name: Counting Bits
Problem Link: https://cses.fi/problemset/task/1146
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
    
    int n; cin>>n;
    int dp[50] = {0};
    dp[0] = 1;
    for (int i = 1; i < 50; i++) 
        dp[i] = 2*dp[i-1] + ((1LL<<(i-1)) - 1);
    int ans = 0;
    while(n>0) {
        int b = log2(n);
        ans += dp[b];
        b = 1LL<<b;
        ans += n - b;
        n = n - b;
    }
    cout<<ans;
}