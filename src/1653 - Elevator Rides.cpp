/*
Problem Name: Elevator Rides
Problem Link: https://cses.fi/problemset/task/1653
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
    
    int n, k; cin>>n>>k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    pair<int, int> dp[1<<n];
    dp[0] = {0, k+1};
    for (int s = 1; s < (1<<n); s++) {
        dp[s] = {25, 0};
        for (int i = 0; i < n; i++) {
            if (s>>i&1){
                auto [c, w] = dp[s^(1<<i)];
                if (w + a[i] > k) {
                    c++;
                    w = min(a[i], w);
                }
                else
                    w += a[i];
                dp[s] = min(dp[s], {c, w});
            }
        }
        // cerr<<s<<' '<<dp[s].first<<' '<<dp[s].second<<endl;
    }
    cout<<dp[(1<<n)-1].first;
}