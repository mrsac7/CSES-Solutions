/*
Problem Name: Graph Girth
Problem Link: https://cses.fi/problemset/task/1707
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define endl '\n'

vector<int> adj[2505];
int ct = 0;
int ans = 5000;
int vis[2505];
void bfs(int x, int t){
    queue<int> q;
    vis[x]=1;
    q.push(x);
    while(!q.empty()){
        int s = q.front(); q.pop(); 
        for(auto i: adj[s]){
            if (x == s && i == t) continue;
            if (vis[i]) continue;
            vis[i]=vis[s]+1;
            if (i == t) return;
            q.push(i);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n,m; cin>>n>>m;
    vector<pair<int, int>> e;
    for (int i = 0; i < m; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        e.push_back({u, v});
    }
    for (auto [i, j]: e) {
        memset(vis, 0, sizeof vis);
        bfs(i, j);
        if (vis[j]) ans = min(ans, vis[j]);
    }
    if (ans < 5000) cout<<ans;
    else cout<<-1;
}   