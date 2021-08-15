/*
Problem Name: Another Game
Problem Link: https://cses.fi/problemset/task/2208
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
    
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x; cin>>x;
            if (x&1) ans = 1;
        }
        cout<<(ans ? "first" : "second")<<endl;
    }   
}