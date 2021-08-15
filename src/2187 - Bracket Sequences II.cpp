/*
Problem Name: Bracket Sequences II
Problem Link: https://cses.fi/problemset/task/2187
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1e6+6;
const int md = 1e9+7;
int F[mxN], I[mxN];

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
    string s; cin>>s;
    if (n&1) return cout<<0, 0;
    n >>= 1;
    int c = 0, k = s.size();
    int x = 0, y = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == ')') c--, y++;
        else if (s[i] == '(') c++, x++;
        if (c < 0) return cout<<0, 0;
    }
    if (x > n) return cout<<0, 0;
    if (x == n) return cout<<1, 0;
    F[0] = 1, I[0] = 1;
    for (int i = 1; i < mxN; i++) {
        F[i] = i*F[i-1]%md;
        I[i] = exp(F[i], md-2, md);
    }
    //total ways from remaining brackets
    int ans = F[2*n-x-y]*I[n-x]%md*I[n-y]%md; 
    //subtracting invalid ways: taking more left brakcets than right
    ans = (ans - F[2*n-x-y]*I[n-x-1]%md*I[n-y+1]%md + md)%md; 
    cout<<ans;
}