/*
Problem Name: Divisor Analysis
Problem Link: https://cses.fi/problemset/task/2182
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
    int c[3] = {1, 1, 1};
    int flag = 0;
    int sq = 1, num = 1, d = 1;
    for (int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        c[0] = c[0]*(y+1)%md;
        int gsum = (exp(x, y+1, md) - 1 + md)%md*exp(x-1, md-2, md)%md;
        c[1] = c[1]*gsum%md;
        sq = sq*exp(x, y/2, md)%md;
        num = num*exp(x, y, md)%md;
        if ((y&1) && flag == 0) {
            d = d*((y+1)/2)%(md-1);
            flag = 1;
        }
        else 
            d = d*(y+1)%(md-1);
    }
    //now two cases for product:
    //if all powers are even, then ans = sq^d
    //if at least power is odd, the ans = num^(d/2) [Use Fermat's little theorem]
    if (flag == 1) 
        c[2] = exp(num, d, md);
    else 
        c[2] = exp(sq, d, md);

    cout<<c[0]<<' '<<c[1]<<' '<<c[2];
}