/*
Problem Name: Counting Necklaces
Problem Link: https://cses.fi/problemset/task/2209
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

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, m; cin>>n>>m;
    //burnside's lemma
    //no. of objects = avg. no of symmetrical pictures over all symmetries.
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + exp(m, __gcd(i, n), md)) % md;
    }
    ans = ans * exp(n, md-2, md) % md;
    cout<<ans;
}