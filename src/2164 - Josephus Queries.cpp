/*
Problem Name: Josephus Queries
Problem Link: https://cses.fi/problemset/task/2164
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int solve(int n, int k) {
    // cerr<<n<<' '<<k<<endl;
    if (n == 1) 
        return 1;
    if (k <= (n+1)/2) {
        if (2*k > n) return 2*k%n;
        else return 2*k;
    }
    
    int c = solve(n>>1, k - (n+1)/2);
    if (n&1) return 2*c + 1;
    else return 2*c - 1;
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k;
        cout<<solve(n, k)<<endl;
    }
}