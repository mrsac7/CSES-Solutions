/*
Problem Name: Swap Game
Problem Link: https://cses.fi/problemset/task/1670
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define endl '\n'

unordered_set<int> vis;
int go(int x1,int  x2, int x3,int  x4,int  x5,int  x6,int  x7,int  x8,int  x9) {
    return x1*100000000 + x2*10000000 + x3*1000000 
    + x4*100000 + x5*10000 + x6*1000 + x7*100 + x8*10 + x9;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int x = 0;
    for (int i = 0; i < 9; i++) {
        int a; cin>>a;
        x = x*10+a;
    }
    queue<pair<int, int>> q;
    q.push({123456789, 0});
    vis.insert(123456789);
    while(!q.empty()) {
        auto [s, c] = q.front();
        q.pop();
        if (s == x) return cout<<c, 0;
        int x9 = s%10; s/=10;
        int x8 = s%10; s/=10;
        int x7 = s%10; s/=10;
        int x6 = s%10; s/=10;
        int x5 = s%10; s/=10;
        int x4 = s%10; s/=10;
        int x3 = s%10; s/=10;
        int x2 = s%10; s/=10;
        int x1 = s%10; s/=10;

        int n1 = go(x2, x1, x3, x4, x5, x6, x7, x8, x9);
        int n2 = go(x1, x3, x2, x4, x5, x6, x7, x8, x9);
        int n3 = go(x1, x2, x3, x5, x4, x6, x7, x8, x9);
        int n4 = go(x1, x2, x3, x4, x6, x5, x7, x8, x9);
        int n5 = go(x1, x2, x3, x4, x5, x6, x8, x7, x9);
        int n6 = go(x1, x2, x3, x4, x5, x6, x7, x9, x8);
        int n7 = go(x4, x2, x3, x1, x5, x6, x7, x8, x9);
        int n8 = go(x1, x2, x3, x7, x5, x6, x4, x8, x9);
        int n9 = go(x1, x5, x3, x4, x2, x6, x7, x8, x9);
        int n10 = go(x1, x2, x3, x4, x8, x6, x7, x5, x9);
        int n11 = go(x1, x2, x6, x4, x5, x3, x7, x8, x9);
        int n12 = go(x1, x2, x3, x4, x5, x9, x7, x8, x6);
        if (!vis.count(n1)) {
            q.push({n1, c+1});
            vis.insert(n1);
        }
        if (!vis.count(n2)) {
            q.push({n2, c+1});
            vis.insert(n2);
        }
        if (!vis.count(n3)) {
            q.push({n3, c+1});
            vis.insert(n3);
        }
        if (!vis.count(n4)) {
            q.push({n4, c+1});
            vis.insert(n4);
        }
        if (!vis.count(n5)) {
            q.push({n5, c+1});
            vis.insert(n5);
        }
        if (!vis.count(n6)) {
            q.push({n6, c+1});
            vis.insert(n6);
        }
        if (!vis.count(n7)) {
            q.push({n7, c+1});
            vis.insert(n7);
        }
        if (!vis.count(n8)){
            q.push({n8, c+1});
            vis.insert(n8);
        }
        if (!vis.count(n9)){
            q.push({n9, c+1});
            vis.insert(n9);
        }
        if (!vis.count(n10)){
            q.push({n10, c+1});
            vis.insert(n10);
        }
        if (!vis.count(n11)){
            q.push({n11, c+1});
            vis.insert(n11);
        }
        if (!vis.count(n12)){
            q.push({n12, c+1}); 
            vis.insert(n12)  ;     
        }
    }   
}