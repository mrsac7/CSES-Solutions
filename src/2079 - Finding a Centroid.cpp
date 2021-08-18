/*
Problem Name: Finding a Centroid
Problem Link: https://cses.fi/problemset/task/2079
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 2e5+5;
vector<int> adj[mxN];
int dp[mxN];

void dfs(int s, int p) {
    dp[s] = 1;
    for (auto i: adj[s]) {
        if (i != p) {
            dfs(i, s);
            dp[s] += dp[i];
        }
    }
}

int n;
int dfs2(int s, int p) {
    pair<int, int> mx = {0, s};
    for (auto i: adj[s]) {
        if (i != p) {
            mx = max(mx, {dp[i], i});
        }
    }
    if (mx.first <= n/2)
        return s;
    return dfs2(mx.second, s);
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    cin>>n;
    for (int i = 1; i < n; i++) {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    cout<<dfs2(1, 0);

}