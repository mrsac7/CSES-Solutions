/*
Problem Name: Tree Isomorphism II
Problem Link: https://cses.fi/problemset/task/1701
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
 
vector<int> center(int n, vector<int> adj[]) {
    int deg[n+1] = {0};
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        deg[i] = adj[i].size();
        if (deg[i] == 1)
            v.push_back(i), deg[i]--;
    }
    int m = v.size();
    while(m < n) {
        vector<int> vv;
        for (auto i: v) {
            for (auto j: adj[i]) {
                deg[j]--;
                if (deg[j] == 1)
                    vv.push_back(j);
            }
        }
        m += vv.size();
        v = vv;
    }
    return v;
}
map<vector<int>, int> mp;
int idx = 0;

int dfs(int s, int p, vector<int> adj[]) {
    vector<int> v;
    for (auto i: adj[s]) {
        if (i != p) 
            v.push_back(dfs(i, s, adj));
    }
    sort(v.begin(), v.end());
    if (!mp.count(v)) mp[v] = idx++;
    return mp[v];
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> adj1[n+1], adj2[n+1];
        for (int i = 1; i < n; i++) {
            int x,y; cin>>x>>y;
            adj1[x].push_back(y);
            adj1[y].push_back(x);
        }
        for (int i = 1; i < n; i++) {
            int x,y; cin>>x>>y;
            adj2[x].push_back(y);
            adj2[y].push_back(x);
        }
        vector<int> v1 = center(n, adj1), v2 = center(n, adj2);
        int s1 = dfs(v1[0], -1, adj1);
        int f = 0;
        for (auto s: v2) {
            int s2 = dfs(s, -1, adj2);
            if (s1 == s2)
                f = 1;
        }
        if (f) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}