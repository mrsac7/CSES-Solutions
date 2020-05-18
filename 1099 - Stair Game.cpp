/*
Problem Name: Stair Game
Problem Link: https://cses.fi/problemset/task/1099
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

void solve(){
    int n; cin>>n;
    //even positions do not contribute
    int a[n];
    int x = 0;
    for(int i =0; i < n; i++) {
        cin>>a[i];
        if (i&1) x^=a[i];
    }
    if (x) cout<<"first";
    else cout<<"second";

}    
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    cin>>t;
    for (int i = 1; i <= t; i++) {
        //cout<<"Case #"<<i<<": ";
        solve();
        cout<<'\n';
    }
}