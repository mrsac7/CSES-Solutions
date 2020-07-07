/*
Problem Name: Increasing Subsequence II
Problem Link: https://cses.fi/problemset/task/1748
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

map<int,int> mp;
const int mxN = 200005;
const int md = 1e9+7;
int bit[mxN];
void upd(int k, int v) {
    for (; k < mxN; k += k&-k) 
        (bit[k] += v)%=md;;
}
int qry(int k) {
    int sum = 0;
    for (; k > 0; k -= k&-k)
        (sum += bit[k])%=md;
    return sum;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n;
    //index compression
    int a[n];
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        s.insert(a[i]);
    }
    int ct = 0;
    for (auto i: s)
        mp[i] = ++ct;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = qry(mp[a[i]]-1)+1;
        (ans += x)%=md;
        upd(mp[a[i]], x);
    }
    cout<<ans;
}