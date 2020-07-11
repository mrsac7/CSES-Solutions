/*
Problem Name: Bit Problem
Problem Link: https://cses.fi/problemset/task/1654
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1<<21;
int freq[mxN];
int dp1[mxN][21], dp2[mxN][21];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        a[i] = x;
        freq[x]++;
    }
    for (int i = 1; i < mxN>>1; i++) {
        dp1[i][0] = freq[i];
        if (i&1)
            dp1[i][0] += freq[i^1];
        for (int k = 1; k < 21; k++) {
            dp1[i][k] = dp1[i][k-1];
            if (i>>k&1)
                dp1[i][k] += dp1[i^1<<k][k-1];
        }
    }
    for (int i = mxN>>1; i > 0; i--) {
        dp2[i][0] = freq[i];
        if (i&1^1)
            dp2[i][0] += freq[i^1];
        for (int k = 1; k < 21; k++) {
            dp2[i][k] = dp2[i][k-1];
            if (i>>k&1^1)
                dp2[i][k] += dp2[i^1<<k][k-1];
        }
    }

    for (int i = 0; i < n; i++) 
        cout<<dp1[a[i]][20]<<' '<<dp2[a[i]][20]<<' '<<
        n - dp1[a[i]^((mxN>>1) - 1)][20]<<endl;
}