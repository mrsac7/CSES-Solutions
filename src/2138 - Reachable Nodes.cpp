/*
Problem Name: Reachable Nodes
Problem Link: https://cses.fi/problemset/task/2138
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 5e4 + 5;
vector<bitset<mxN>> dp(mxN);
vector<int> v, adj[mxN];
bool vis[mxN];

void dfs(int s) {
    if (vis[s]) return;
    vis[s] = 1;
    for (auto i: adj[s])
        dfs(i);
    v.push_back(s);
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
        dfs(i);

    for (auto s: v) {
        dp[s][s] = 1;
        for (auto i: adj[s])
            dp[s] |= dp[i];
    }
    for (int i = 1; i <= n; i++)
        cout << dp[i].count() << ' ';
}