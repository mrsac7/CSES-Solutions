/*
Problem Name: Path Queries II
Problem Link: https://cses.fi/problemset/task/2134
Author: Sachin Srivastava (mrsac7)
*/
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 2e5+5;
vector<int> adj[mxN];
int dp[mxN], depth[mxN], par[mxN];
int heavy[mxN], head[mxN], id[mxN];
int seg[10*mxN];
int N;
int val[mxN];

void update(int k, int x) {
    k += N; seg[k] = x; k >>= 1;
    while (k > 0) {
        seg[k] = max(seg[2*k], seg[2*k+1]);
        k >>= 1;
    }
}

int query(int a, int b) {
    a += N, b += N;
    int s = 0;
    while (a <= b) {
        if (a & 1) {
            s = max(s, seg[a]);
            a++;
        }
        if (~b & 1) {
            s = max(s, seg[b]);
            b--;
        }
        a >>= 1, b >>= 1;
    }
    return s;
}

void dfs(int s, int p) {
    dp[s] = 1;
    int mx = 0;
    for (auto i: adj[s]) if (i != p) {
        par[i] = s;
        depth[i] = depth[s] + 1;
        dfs(i, s);
        dp[s] += dp[i];        
        if (dp[i] > mx)
            mx = dp[i], heavy[s] = i;
    }
}

int cnt = 0;
void hld(int s, int h) {
    head[s] = h;
    id[s] = ++cnt;
    update(id[s]-1, val[s]);
    if (heavy[s])
        hld(heavy[s], h);
    for (auto i: adj[s]) {
        if (i != par[s] && i != heavy[s])
            hld(i, i);
    }
}

int path(int x, int y){
    int ans = 0;
    while (head[x] != head[y]) {
        if (depth[head[x]] > depth[head[y]])
            swap(x, y);
        ans = max(ans, query(id[head[y]]-1, id[y]-1));
        y = par[head[y]];
    }
    if(depth[x] > depth[y]) 
        swap(x, y);
    ans = max(ans, query(id[x]-1, id[y]-1));
    return ans;
}


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, t; cin>>n>>t;
    N = 1 << (int) ceil(log2(n));
    for (int i = 1; i <= n; i++) 
        cin>>val[i];

    for (int i = 1; i < n; i++) {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    hld(1, 1);

    while (t--) {
        int ch; cin>>ch;
        if (ch == 1) {
            int k, x; cin>>k>>x;
            update(id[k]-1, x);
        }
        else {
            int x, y; cin>>x>>y;
            cout << path(x, y) << ' ';
        }
    }
}