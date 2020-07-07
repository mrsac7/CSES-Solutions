/*
Problem Name: Advertisement
Problem Link: https://cses.fi/problemset/task/1142
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
    
    int n; cin>>n;
    int pre[n] = {0}, suf[n+1] = {0}, a[n];
    int ans = 0;
    stack<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        while(!q.empty() && q.top().first >= a[i])
            q.pop();
        int x = -1;
        if (!q.empty()) {
            x = q.top().second;
        }
        pre[i] = 1 + i-x-1;
        q.push({a[i], i});
    }
    while(!q.empty()) q.pop();

    for (int i = n-1; i >= 0; i--) {
        while(!q.empty() && q.top().first >= a[i])
            q.pop();
        int x = n;
        if (!q.empty()) {
            x = q.top().second;
        }
        suf[i] = 1 + x-i-1;
        q.push({a[i], i});
        ans = max(ans, (pre[i]+suf[i]-1)*a[i]);
    }
    cout<<ans;
}