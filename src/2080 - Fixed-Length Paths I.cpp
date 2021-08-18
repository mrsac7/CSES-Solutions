/*
Problem Name: Fixed-Length Paths I
Problem Link: https://cses.fi/problemset/task/2080
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
 
const int mxN = 2e5+5;
vector<int> adj[mxN];
int mark[mxN], dp[mxN], dis[mxN] = {1};
 
int dfs(int s, int p) {
    dp[s] = 1;
    for (auto i: adj[s]) {
        if (i != p && !mark[i]) {
            dp[s] += dfs(i, s);
        }
    }
    return dp[s];
}
 
int k;
int ans = 0, mxd = 0;
 
int dfs2(int s, int p, int n) {
    for (auto i: adj[s]) {
        if (i != p && !mark[i] && dp[i] > n/2) {
            return dfs2(i, s, n);
        }
    }
    return s;
}
 
 
void dfs3(int s, int p, int d, int flag) {
    if (d > k) return;
    mxd = max(mxd, d);
    if (flag) dis[d]++;
    else ans += dis[k-d];
    for (auto i: adj[s]) {
        if (i != p && !mark[i])
            dfs3(i, s, d+1, flag);
    }
}

 
void solve(int s) {
    dfs(s, 0);
    int ct = dfs2(s, 0, dp[s]);
    mark[ct] = 1;
    mxd = 0;
    for (auto i: adj[ct]) {
        if (!mark[i]) {
            dfs3(i, ct, 1, 0);
            dfs3(i, ct, 1, 1);
        }
    }
    fill(dis + 1, dis + mxd + 1, 0);
    for (auto i: adj[ct]) if (!mark[i]) {
        solve(i);
    }
}
 
 
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n>>k;
    for (int i = 1; i < n; i++) {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    solve(1);
    cout<<ans;
}