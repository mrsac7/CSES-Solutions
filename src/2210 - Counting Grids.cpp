/*
Problem Name: Counting Grids
Problem Link: https://cses.fi/problemset/task/2210
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
    
    int n; cin>>n;
    //burnside's lemma: https://youtu.be/D0d9bYZ_qDY
    //no. of objects = avg. no of symmetrical pictures over all symmetries.
    int n0 = n*n;
    int n90 = 1;
    int n180 = 1;
    if (n > 1 && (n&1)) {
        n90 = (n+3)*(n-1)/4 - (n-1)/2 + 1;
        n180 = (n+3)*(n-1)/2 - (n-1) + 1;
    }
    else if (n&1^1) {
        n90 = n*(n+2)/4 - n/2;
        n180 = n*(n+2)/2 - n;
    }
    int ans = 0;
    ans = (ans + exp(2, n0, md)) % md; //0 deg
    ans = (ans + exp(2, n90, md)) % md; //90 deg
    ans = (ans + exp(2, n180, md)) % md; //180 deg
    ans = (ans + exp(2, n90, md)) % md; //270 deg
    ans = ans * exp(4, md-2, md) % md;
    cout<<ans;
}