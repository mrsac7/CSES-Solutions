/*
Problem Name: Polygon Area
Problem Link: https://cses.fi/problemset/task/2191
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

#define X first
#define Y second

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n;
    pair<int,int> a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i].X>>a[i].Y;
    int ans = 0;
    //shoelace formula
    for (int i = 0; i < n; i ++) {
        ans += (a[i].X*a[(i+1)%n].Y - a[(i+1)%n].X*a[i].Y);
    }
    cout<<abs(ans);
}