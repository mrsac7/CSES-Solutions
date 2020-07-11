/*
Problem Name: Permutations II
Problem Link: https://cses.fi/problemset/task/1075
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int md = 1e9+7;
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    //A002464 - OEIS
    int n; cin>>n;
    int dp[n+1] = {0};
    dp[0] = 1, dp[1] = 1;
    for (int i = 4; i <= n; i++) {
        dp[i] = (i+1)*dp[i-1] - (i-2)*dp[i-2]
                - (i-5)*dp[i-3] + (i-3)*dp[i-4];
        dp[i]%=md;
        dp[i] = (dp[i] + md)%md;
    }
    cout<<dp[n];
}