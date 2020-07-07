/*
Problem Name: Maximum Xor Subarray
Problem Link: https://cses.fi/problemset/task/1655
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 30;
int trie[200005*N][2], ct = 0;
void insert(int x) {
    int node = 0;
    for (int i = N; i >= 0; i--) {
        int y = x>>i&1;
        if (!trie[node][y]) trie[node][y] = ++ct;
        node = trie[node][y];
    }
}
int search(int x) {
    int ans = 0, node = 0;
    for (int i = N; i>=0; i--) {
        int y = x>>i&1;
        if (trie[node][y^1]) {
            node = trie[node][y^1];
            ans += (1<<i);
        }
        else 
            node = trie[node][y];
    }   
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n;
    int xr = 0, mx = 0;
    insert(xr);
    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        xr ^= x;
        insert(xr);
        mx = max(search(xr), mx);
    }
    cout<<mx;
}