/*
Problem Name: School Excursion
Problem Link: https://cses.fi/problemset/task/1706
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1e5+5;
int c = 0;
vector<int> adj[mxN];
bool vis[mxN];
void dfs(int s){
    if (vis[s]) return;
    vis[s]=1; c++;
    for (auto i: adj[s]) dfs(i);
}
int dp[mxN];
map<int,int> mp;
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, m; cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for (int i = 0; i < n; i++) {
        if (!vis[i+1]) {
            c = 0;
            dfs(i+1);
            mp[c]++;
        }
    }
    vector<int> v;
    for (auto [i, c]: mp) {
        int x = 0;
        while(1<<x < c) {
            v.push_back((1<<x)*i);
            c -= 1<<x;
            x++;
        }
        if (c)
            v.push_back(c*i);
    }
    m = v.size();
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = n; j >= 1; j--) {
            if (j >= v[i]) {
                dp[j] = max(dp[j-v[i]], dp[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout<<dp[i];
}