/*
Problem Name: Range Updates and Sums
Problem Link: https://cses.fi/problemset/task/1735
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

pair<int,int> seg[1000005];
int mark[1000005];

void push(int k) {
    if (mark[k]) {
        mark[k] = 0;
        seg[2*k].F = seg[2*k + 1].F = seg[k].F/2;
        seg[2*k].S = seg[2*k + 1].S = 0;
        mark[2*k] = mark[2*k + 1] = 1;
    }   
}

void update(int v, int a, int b, int k, int x, int y) {
    if (b < x || a > y) return;
    if (a<=x && b>=y) {
        seg[k].S += v;
        return;
    }
    int h = min(b,y) - max(a,x) + 1;
    push(k); 
    seg[k].F += h*v;
    int d = (x+y)/2;
    update(v, a, b, 2*k, x, d);
    update(v, a, b, 2*k + 1, d + 1, y);
}
int assign(int v, int a, int b, int k, int x, int y) {
    if (b < x || a > y) return seg[k].F + (y - x + 1)*seg[k].S;
    if (a <= x && b >= y) {
        seg[k].F = (y-x+1)*v;
        seg[k].S = 0;
        mark[k] = 1; 
        return seg[k].F;
    }
    push(k); 
    int d = (x+y)/2;
    seg[2*k].S += seg[k].S,  seg[2*k + 1].S += seg[k].S;
    seg[k].S = 0;
    seg[k].F = assign(v, a, b, 2*k, x, d) + assign(v, a, b, 2*k + 1, d + 1, y);
    return seg[k].F;

}
int sum(int a, int b, int k, int x, int y) {
    if (b < x || a > y) return 0;
    if (a <= x && b >= y) {
        return seg[k].F + (y-x+1)*seg[k].S;
    }
    push(k); 
    seg[k].F += (y-x+1)*seg[k].S;
    seg[2*k].S += seg[k].S, seg[2*k + 1].S += seg[k].S;
    seg[k].S = 0;
    int d = (x+y)/2;
    return sum(a, b, 2*k, x, d) + sum(a, b, 2*k + 1, d + 1, y);
}
void solve(){
    int n,q; cin>>n>>q;
    int nn =n;
    n = 1<<(int)ceil(log2(n));
    for (int i = 0; i< nn; i++) {
        int x; cin>>x;
        update(x,i,i,1,0,n-1);
    }
    while (q--) {
        int z;
        cin>>z;
        if (z == 1) {
            int a,b,x;
            cin>>a>>b>>x;
            a--,b--;
            update(x,a,b,1,0,n-1);
        }
        else if (z == 2) {
            int a,b,x;
            cin>>a>>b>>x;
            a--,b--;
            assign(x,a,b,1,0,n-1);
        }
        else {
            int a,b;
            cin>>a>>b; a--, b--;
            cout<<sum(a,b,1,0,n-1)<<'\n';
        }
    }
}    
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }
}