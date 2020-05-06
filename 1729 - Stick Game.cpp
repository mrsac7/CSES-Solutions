/*
Problem Name: Stick Game
Problem Link: https://cses.fi/problemset/task/1729
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
#define pb push_back
#define F first
#define S second

const int inf = 1LL<<62;
const int md = 1000000007;

void solve(){
    int n,k; cin>>n>>k;
    int dp[n+1] = {0};
    dp[0] = 0;
    vector<int> p;
    for (int i = 0; i < k ; i++)  {
        int x; cin>>x;
        p.push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (auto j: p) {
            if (i - j >= 0) {
                if (dp[i - j] == 0) dp[i]=1;
            }
        }
        if (dp[i]) cout<<'W';
        else cout<<'L';
    }
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