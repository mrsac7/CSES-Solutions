/*
Problem Name: Required Substring
Problem Link: https://cses.fi/problemset/task/1112
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
#define ff first
#define ss second
#define endl '\n'

const long long inf = 1LL<<60; //1.5e18
const int md = 1000000007;

int dp[1005][105];
int exp(int x, unsigned int y, int p){
    int res=1; x=x%p;
    while(y>0){
        if (y&1) res= (res*x)%p; y=y>>1; x=(x*x)%p;
    }
    return res;
}
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int m = s.size();
    //dp[i][j] = no of strings of length i which do not contain s
    //           and whose suffix of length j is equal to the prefix of s
    //           
    //Let's add one character to each prefix of s and determine the max length 
    //of suffix which is also a prefix of s formed by the addition of each character
    int len[m][26];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 26; j++) {
            string pre = s.substr(0,i);
            pre += j+'A';
            len[i][j] = 0;
            for (int k = 0; k < pre.size(); k++) {
                if (pre.substr(k) == s.substr(0,pre.size() - k)) {
                    len[i][j] = pre.size() - k;
                    break;
                }
            }
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <=n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 26; k++) {
                (dp[i][len[j][k]] += dp[i-1][j])%=md;
            }
        }
    }
    int ans = exp(26,n,md);
    for (int i = 0; i < m; i++) {
        ans = (ans - dp[n][i] + md) % md;
    }
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
        //cout<<"Case #"<<i<<": ";
        solve();
        cout<<'\n';
    }
}