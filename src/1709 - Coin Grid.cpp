/*
Problem Name: Coin Grid
Problem Link: https://cses.fi/problemset/task/1709
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 205;
const int INF = 1LL<<60;
vector<tuple<int,int,int>> adj[mxN];
bool vis[mxN];
int dfs(int s, int f) {
    if (s == 201) 
        return f;
    vis[s] = 1;
    for (auto &[i, w, j]: adj[s]) {
        if (w >= 1 && !vis[i]) {
            int b = dfs(i, 1);
            if (b > 0) {
                w -= b;
                get<1>(adj[i][j])+=b;
                return b;
            }
        }
    }
    return 0;
}
set<int> adj2[mxN];
void dfs(int s){
    if (vis[s]) return;
    vis[s] = 1;
    for (auto i: adj2[s]) dfs(i);
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=n; j++) {
            char x; cin>>x;
            if (x != '.') {
                int j1 = adj[100+j].size();
                int j2 = adj[i].size();
                adj[i].push_back({100+j, 1, j1});
                adj[100+j].push_back({i, 0, j2});
                adj2[i].insert(100+j);
            }
        }
    }
    for (int i = 1; i <= 100; i++) {
        int j1 = adj[i].size();
        int j2 = adj[0].size();
        adj[0].push_back({i, 1, j1});
        adj[i].push_back({0, 0, j2});
        j1 = adj[201].size();
        j2 = adj[100+i].size();
        adj[100+i].push_back({201, 1, j1});
        adj[201].push_back({100+i, 0, j2});
    }
    int ans = 0;
    while(1) {
        memset(vis, 0, sizeof vis);
        int f = dfs(0, INF);
        ans += f;
        if (!f) 
            break;
    }
    cout<<ans<<endl;
    int k = 0;
    set<int> st;
    for (int i = 1; i <= 100; i++) {
        st.insert(i);
        for (auto [s, w, j]: adj[i]) {
            if (w == 0 && s>100) {
                adj2[i].erase(s);
                adj2[s].insert(i);
                st.erase(i);
            }
        }
    }
    memset(vis, 0, sizeof vis);
    for (auto i: st) {
        if (!vis[i])
            dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            cout<<1<<' '<<i<<endl;
        if (vis[100+i])
            cout<<2<<' '<<i<<endl;
    }
}