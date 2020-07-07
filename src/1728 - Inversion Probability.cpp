/*
Problem Name: Inversion Probability
Problem Link: https://cses.fi/problemset/task/1728
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
    int n, r[105];
    long double p[105][105] = {0};
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>r[i];
    }
    long double ans = 0;
    for (int i = 0; i < n; i++) {
        for ( int j = i + 1; j < n; j++) {
            for (int k = 1; k <= r[i]; k++) {
                p[i][j] += 1.0/r[i]*(((k - 1) >= r[j])?1.0:(k-1.0)/r[j]);
            }
            ans += p[i][j];
        }
    }
    cout<<setprecision(6)<<fixed;
    cout<<ans;
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