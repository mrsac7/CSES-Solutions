/*
Problem Name: Network Breakdown
Problem Link: https://cses.fi/problemset/task/1677
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 200005;
int len[mxN], par[mxN];
void init() {
    for (int i = 1; i < mxN; i++)
        len[i] = 1, par[i] = i;
}
int find(int x) {
    int s = x;
    while(par[s] != s) 
        s = par[s];
    while(par[x] != x) {
        int k = x;
        x = par[x];
        par[k] = s;
    }
    return s;
}
void join(int x, int y) {
    int s1 = find(x), s2 = find(y);
    if (s1 == s2)
        return;
    if (len[s1] > len[s2])
        swap(s1, s2);
    par[s1] = s2;
    len[s2] += len[s1];
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, m, k; cin>>n>>m>>k;
    set<pair<int, int>> e;
    init();
    for (int i = 0; i < m; i++) {
        int x, y; cin>>x>>y;
        if (x > y) swap(x, y);
        e.insert({x, y});
    }
    vector<pair<int,int>> q;
    for (int i = 0; i < m; i++) {
        int x,y; cin>>x>>y;
        if (x > y) swap(x, y);
        e.erase({x, y});
        q.push_back({x, y});
    }
    int comp = n;
    for (auto [x, y]: e) {
        if (find(x) != find(y)) {
            comp--;
            join(x, y);
        }
    }
    int ans[k] = {0};
    for (int i = k-1; i >= 0; i--) {
        ans[i] = comp;
        auto [x, y] = q[i];
        if (find(x) != find(y)) {
            comp--;
            join(x, y);
        }   
    }
    for (int i = 0; i < k; i++)
        cout<<ans[i]<<' ';
}