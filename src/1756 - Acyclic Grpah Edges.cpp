/*
Problem Name: Edge Directions
Problem Link: https://cses.fi/problemset/task/1756
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n,m; cin>>n>>m;
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int vis[n+1] = {0};
    queue<int> q;
    for (int i = 1; i < n+1; i++) {
        if (vis[i] == 0) {
            q.push(i);
            vis[i] = 1;

            while(!q.empty()) {
                int s = q.front();
                q.pop();
                vis[s] = 2;
                for (auto x: adj[s]) {
                    if (vis[x] == 2) continue;
                    cout<<x<<' '<<s<<endl;
                    if (vis[x] == 0) {
                        q.push(x);
                        vis[x] = 1;
                    }
                }
            }
        }
    }
}