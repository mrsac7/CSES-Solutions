/*
Problem Name: Sorting Methods
Problem Link: https://cses.fi/problemset/task/1162
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 2e5+5;
int bit[mxN];
void upd(int k) {
    for (; k < mxN; k += k&-k)
        bit[k]++;
}
int qry(int k) {
    int ans = 0;
    for (; k > 0; k -= k&-k)
        ans += bit[k];
    return ans;
}
vector<int> adj[mxN];
int c = 0;
bool vis[mxN];
void dfs(int s){
    if (vis[s]) return;
    vis[s]=1; c++;
    for (auto i: adj[s]) dfs(i);
}
int ind[mxN];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n;
    int a[n];
    int ans1 = 0, ans2 = 0, ans3 = n, ans4 = n;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        ans1 += qry(mxN) - qry(a[i]);
        upd(a[i]);
        if (i+1 != a[i]) {
            adj[i+1].push_back(a[i]),
            adj[a[i]].push_back(i+1);
        }
        int it = upper_bound(ind, ind+mx+1, a[i]) - ind;
        mx = max(mx, it);
        ind[it] = a[i];
    }
    ans3 = n-mx;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            c = 0; dfs(i);
            ans2 += c-1;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == ans4)
            ans4--;
    }
    cout<<ans1<<' '<<ans2<<' '<<ans3<<' '<<ans4;
}