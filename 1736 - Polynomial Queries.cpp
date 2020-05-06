/*
Problem Name: Polynomial Queries
Problem Link: https://cses.fi/problemset/task/1736
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

struct node {
    int s = 0, z0 = 0, z1 = 0;
};
struct node seg[1000005];
void build(int p, int v, int k, int x, int y) {
    if (x == y) {
        if (x == p) seg[k].s = v;
        return;
    }
    if (x<=p && y>=p) {
        int d = (x+y)/2;
        build(p,v,2*k,x,d);
        build(p,v,2*k+1,d+1,y);
        seg[k].s = seg[2*k].s + seg[2*k+1].s;
    }
} 
void update(int a, int b, int k, int x, int y) {
    if (a > y || b < x) return;
    if (a <= x && b >= y) {
        seg[k].z0 += (1 + x - a);
        seg[k].z1++;
        // error(seg[k].z0, seg[k].z1,k);cerr<<endl;
        return;
    }
    int xx = max(a,x), yy = min(b,y);
    seg[k].s += (yy - xx + 1)*(1 + x - min(x,a)) + (yy - xx)*(yy - xx + 1)/2; 
    // error(seg[k].s,k);cerr<<endl;
    int d = (x+y)/2;
    update(a, b, 2*k, x, d);
    update(a, b, 2*k + 1, d + 1, y);
}

int sum(int a, int b, int k, int x, int y) {
    if (a>y || b<x) return 0;
    if (a<=x && b>=y) {
        // error("ss",k,seg[k].s,seg[k].z0,seg[k].z1*(y-x)*(y-x+1)/2);cerr<<endl;
        return seg[k].s + seg[k].z0*(y-x+1) + seg[k].z1*(y-x)*(y-x+1)/2;
    }
    seg[k].s += seg[k].z0*(y-x+1) + seg[k].z1*(y-x)*(y-x+1)/2;
    // error(k,seg[k].z0, seg[k].z1);
    seg[2*k].z1 += seg[k].z1, seg[2*k + 1].z1 += seg[k].z1;
    seg[2*k].z0 += seg[k].z0;
    seg[2*k + 1].z0 += (y-x+1)/2*seg[k].z1 + seg[k].z0;
    seg[k].z0 = 0, seg[k].z1 = 0;
    // error(seg[k].s,k);cerr<<endl;
    int d = (x+y) / 2;
    return sum(a, b, 2*k, x, d) + sum(a, b, 2*k + 1, d + 1, y);
}

void solve(){
    int n,nn,q;
    cin>>n>>q;
    nn = n;
    n = 1<<(int) ceil(log2(n));
    for (int i = 0; i < nn; i++) {
        int x; cin>>x;
        build(i,x,1,0,n-1);
    }
    while ( q--) {
        int z; cin>>z; 
        int x,y; cin>>x>>y;
        x--, y--;
        if (z == 1) update(x,y,1,0, n-1);
        else cout<<sum(x,y,1,0,n-1)<<'\n';
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