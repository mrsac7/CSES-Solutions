/*
Problem Name: Necessary Cities
Problem Link: https://cses.fi/problemset/task/2077
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1e5+5;
vector<int> adj[mxN];
int ans[mxN];
int vis[mxN], low[mxN];
int cnt = 0;

void dfs(int s, int p) {
    vis[s] = ++cnt;
    low[s] = vis[s];
    int ch = 0; //children connected with tree-edge
    for (auto i: adj[s]) {
        if (i != p) {
            if (vis[i]) //back edge
                low[s] = min(low[s], vis[i]);
            else {
                dfs(i, s);
                low[s] = min(low[s], low[i]);
                if (p != 0 && low[i] >= vis[s])
                    ans[s] = 1;
                ch++;
            }
        }
    }
    if (p == 0 && ch > 1)
        ans[s] = 1;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, m; cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i, 0);
    }
    cout<<accumulate(ans, ans+n+1, 0)<<endl;
    for (int i = 1; i <= n; i++) if (ans[i])
        cout<<i<<' ';
}