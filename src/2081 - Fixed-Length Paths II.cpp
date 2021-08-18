/*
Problem Name: Fixed-Length Paths II
Problem Link: https://cses.fi/problemset/task/2081
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
 
const int mxN = 2e5+5;
vector<int> adj[mxN];
int mark[mxN], dp[mxN], bit[mxN];
int k1, k2;
int ans = 0, mxd = 0;

void update(int k, int x) {
    for (; k < mxN; k += k&-k)
        bit[k] += x;
}

int query(int l, int r) {
    int s = 0, k = r;
    for (; k > 0; k -= k&-k)
        s += bit[k];
    k = l-1;
    for (; k > 0; k -= k&-k)
        s -= bit[k];
    return s + (l == 0);
}

 
int dfs(int s, int p) {
    dp[s] = 1;
    for (auto i: adj[s]) {
        if (i != p && !mark[i]) {
            dp[s] += dfs(i, s);
        }
    }
    return dp[s];
}
 
 
int dfs2(int s, int p, int n) {
    for (auto i: adj[s]) {
        if (i != p && !mark[i] && dp[i] > n/2) {
            return dfs2(i, s, n);
        }
    }
    return s;
}
 
 
void dfs3(int s, int p, int d, int flag) {
    if (d > k2) return;
    mxd = max(mxd, d);
    if (flag) update(d, 1);
    else ans += query(max(0LL, k1-d), k2-d);
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
    for (int i = 1; i <= mxd; i++) 
        update(i, -query(i, i));
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
    
    int n; cin>>n>>k1>>k2;
    for (int i = 1; i < n; i++) {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    solve(1);
    cout<<ans;
}