/*
Problem Name: Bracket Sequences I
Problem Link: https://cses.fi/problemset/task/2064
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int md = 1e9+7;
int exp(int x, int y, int md){
    int ans = 1;
    x = x%md;
    while (y > 0) {
        if (y&1)
            ans = ans*x%md;
        y = y>>1;
        x = x*x%md;
    }
    return ans;
}

const int mxN = 2e6+6;
int F[mxN], I[mxN];

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    //catalan
    int n; cin>>n; 
    if (n&1) return cout<<0, 0;
    n >>= 1;
    F[0] = 1, I[0] = 1;
    for (int i = 1; i < mxN; i++) {
        F[i] = F[i-1]*i%md;
        I[i] = exp(F[i], md-2, md);
    }
    int ans = F[2*n]*I[n]%md*I[n]%md;
    ans = ans*exp(n+1, md-2, md)%md;
    cout<<ans;
}