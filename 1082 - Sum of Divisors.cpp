/*
Problem Name: Sum of Divisors
Problem Link: https://cses.fi/problemset/task/1082
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

int exp(int x, unsigned int y, int p){
    int res=1; x=x%p;
    while(y>0){
        if (y&1) res= (res*x)%p; y=y>>1; x=(x*x)%p;
    }
    return res;
}
void solve(){
    //calculte in two parts
    //1st - contribution of each number upto sqrt(n)
    //2nd - from sqrt(n) to n calculate how many numbers give 1, 2, 3...sqrt(n) contribution
    int n; cin>>n;
    int s = 0;
    int sq = sqrt(n);
    int inv = exp(2,md-2,md);
    for (int i = 1; i <= sq; i++) {
        int x = (n/i - n/(i+1))%md;
        int r = n/i, l = n/(i+1) + 1;
        s = ( s + x*((l+r)%md)%md*inv%md*i%md)%md;
    }
    for (int i = 1; i <= n/(sq+1); i++) {
        s = (s + n/i*i) % md; 
    }
    cout<< s;
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
        // cout<<'\n';
    }
}