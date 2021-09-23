/*
Problem Name: Strongly Connected Edges
Problem Link: https://cses.fi/problemset/task/2177
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1e5+5;
vector<pair<int,int>> ans;
int flag = 0, cnt = 0;
vector<int> adj[mxN];
int vis[mxN], low[mxN];

void dfs(int s, int p) {
    vis[s] = ++cnt;
    low[s] = vis[s];
    for (auto i: adj[s]) {
        if (i != p) {
            if (vis[i]) {
                low[s] = min(low[s], vis[i]);
                if (vis[i] > vis[s])
                    ans.push_back({i, s});
            }
            else {
                dfs(i, s);
                ans.push_back({s, i});
                low[s] = min(low[i], low[s]);
                if (low[i] > vis[s]) 
                    flag = 1;
            }
        }
    }
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
    dfs(1, 0);
    if (flag == 1) return cout<<"IMPOSSIBLE", 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            return cout<<"IMPOSSIBLE", 0;
    for (auto [i, j]: ans)
        cout<<i<<' '<<j<<endl;
}