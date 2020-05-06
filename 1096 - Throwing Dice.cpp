/*
Problem Name: Throwing Dice
Problem Link: https://cses.fi/problemset/task/1096
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

vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> c(6, vector<int>(b[0].size()));
    for (int i = 0; i < 6; i++) 
        for (int j = 0; j < b[0].size(); j++) 
            for ( int k = 0; k < 6; k++) 
                (c[i][j] += a[i][k]*b[k][j]%md)%=md;
    return c;
}

vector<vector<int>> exp(vector<vector<int>> x, unsigned int y){
    vector<vector<int>> res(6, vector<int>(6));
    for ( int i = 0; i < 6; i++) 
        res[i][i] = 1;

    while(y>0){
        if (y&1) {
            res = mul(res,x);
        }
        y=y>>1; 
        x = mul(x,x);
    }
    return res;
}
void solve(){
    vector<vector<int>> x(6, vector<int>(6));
    for (int i = 0; i < 5; i++) 
        x[i][i+1] = 1, x[5][i] = 1;
    x[5][5] = 1;
    int n; cin>>n;
    x = exp(x,n);
    cout<< x[5][5];
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