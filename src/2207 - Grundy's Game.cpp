/*
Problem Name: Grundy's Game
Problem Link: https://cses.fi/problemset/task/2207
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1e6+6;

vector<int> dp = {0, 0, 0};
int mex(vector<int> v) {
    set<int> s;
    for (auto i: v)
        s.insert(i);
    for (int i = 0; i < mxN; i++) {
        if (s.count(i) == 0) return i;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin>>t;
    for (int i = 3; i < 2000; i++) {
        vector<int> v;
        for (int j = 1; i-j > j; j++) {
            v.push_back(dp[j]^dp[i-j]);
        }
        dp.push_back(mex(v));
    }
    while(t--) {
        int n; cin>>n;
        if (n >= 2000) cout<<"first"<<endl;
        else cout<< (dp[n] > 0 ? "first" : "second")<<endl;
    }
}