/*
Problem Name: Missing Coin Sum
Problem Link: https://cses.fi/problemset/task/2183
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 2e5+5;
int dp[mxN];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n;
    int a[n+1] = {0};
    for (int i = 1; i <= n; i++) 
        cin>>a[i];
    sort(a, a+n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[i-1] < a[i]) return cout<<dp[i-1], 0;
        dp[i] = dp[i-1] + a[i];
    }
    cout<<dp[n];
}