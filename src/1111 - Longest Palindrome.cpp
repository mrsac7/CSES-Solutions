/*
Problem Name: Longest Palindrome
Problem Link: https://cses.fi/problemset/task/1111
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

template<typename... T>
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}

#define int long long
#define F first
#define S second

const long long inf = 1LL<<62;
const int md = 1000000007;

void solve(){
    string s; cin>>s;
    int n = s.size();
    int dp[n][2] = {0};
    int x1 = 0, y1 = -1;
    int x2 = 0, y2 = -1;
    int mx = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int k = 0;
        if (i>y1) k = 1;
        else k = min(dp[x1+y1-i][0], y1-i+1);
        while (0<=i-k && i+k<n && s[i-k] == s[i+k]) k++;
        dp[i][0] = k--;
        if (i+k>y1) x1 = i-k, y1 = i+k;
        if (2*dp[i][0] - 1 > mx) ans = i-k, mx = 2*dp[i][0] - 1;
        k = 0;
        if (i<=y2) k = min(dp[x2+y2-i+1][1],y2-i+1);
        while(0<=i-k-1 && i+k<n && s[i-k-1] == s[i+k]) k++;
        dp[i][1] = k--;
        if (i+k>y2) x2 = i-k-1, y2 = i+k;
        if (2*dp[i][1] > mx) ans = i-k-1, mx = 2*dp[i][1];
    }
    cout<<s.substr(ans,mx);
}    
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    //cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }
}