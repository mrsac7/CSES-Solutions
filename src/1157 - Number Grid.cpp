/*
Problem Name: Number Grid
Problem Link: https://cses.fi/problemset/task/1157
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
    
    int x,y; cin>>x>>y;
    cout<<((x-1)^(y-1));
}