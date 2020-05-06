/*
Problem Name: Moving Robots
Problem Link: https://cses.fi/problemset/task/1726
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

int dir(int x, int y) {
    int c = 0;
    if ( x + 1 < 8) c++;
    if ( y + 1 < 8) c++;
    if ( x - 1 >= 0 ) c++;
    if ( y - 1 >=0) c++;
    return c;
}

long double dp[65][65][105] = {0};
void solve(){
    for (int i = 0; i < 64; i++) dp[i][i][0] = 1;
    int k; cin>>k;
    for (int i = 1; i <=k; i++) {
        for ( int x= 0; x <64; x++) {
            for (int y = 0; y < 64; y++) {
                int a = x/8, b = x%8;
                long double p = 0;
                if (a+1 < 8 ) {
                    p += 1.0/dir(a+1,b)*dp[a*8 + 8 + b][y][i-1];
                }
                if (b+1 < 8 ) {
                    p += 1.0/dir(a,b+1)*dp[a*8 + b + 1][y][i-1];
                }
                if ( a - 1 >= 0) {
                    p += 1.0/dir(a-1, b)*dp[a*8 - 8 +b][y][i-1];
                }
                if ( b - 1 >=0) {
                    p += 1.0/dir(a, b- 1)*dp[a*8 + b-1][y][i-1];
                }
                dp[x][y][i] = p;
            }
        }
    }
    long double ans = 0;
    for (int x = 0; x < 64; x++){
        long double t = 1;
        for (int y = 0; y < 64; y++) {
            t*=(1 - dp[x][y][k]);
        }
        ans += t;
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