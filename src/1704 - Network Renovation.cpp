/*
Problem Name: Network Renovation
Problem Link: https://cses.fi/problemset/task/1704
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'

vector<int> adj[100005]; 
vector<int> v;
void dfs(int s, int p) {
    for (auto i : adj[s]) {
        if (i != p)
            dfs(i, s);
    }
    if (adj[s].size() == 1) 
        v.push_back(s);
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n;
    for (int i = 0; i < n-1; i++) {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    int k = v.size();
    if (k&1) 
        v.push_back(v[0]), k++;
    cout<< k/2<<endl;
    for (int i = 0; i < k/2; i++) 
        cout<<v[i]<<' '<<v[i+k/2]<<endl;
}