/*
Problem Name: Maximum Subarray Sum II
Problem Link: https://cses.fi/problemset/task/1644
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
    
    int n,x,y; cin>>n>>x>>y;
    int a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    int pre[n+1] = {0};
    for (int i = 1; i <= n; i++) 
        pre[i] = pre[i-1] + a[i-1];
    int s = 0, len = x;
    set<pair<int,int>> st;
    for (int i = 0; i < x; i++)
        s += a[i];
    st.insert({pre[1], 0});
    int mx = s;
    for (int i = x; i < n; i++) {
        int z = pre[i+1] - pre[i+1-x];
        if (len == y) {
            auto it = st.begin();
            s = max(z, s + a[i] - (it->first - pre[i-len]));
            if (s == z) len = x, st.clear();
            else {
                for (int k = i-y; k <= it->second; k++)
                    st.erase({pre[k+1], k});
                len = i - it->second;
            }
            st.insert({pre[i-x+2], i-x+1});
        }
        else {
            s = max(z, s + a[i]);
            if (s == z) len = x, st.clear();
            else len++;
            st.insert({pre[i-x+2], i-x+1});
        }
        mx = max(mx, s);
    }
    cout<<mx;
}
