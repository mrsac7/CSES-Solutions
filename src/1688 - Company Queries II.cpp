/*
Problem Name: Company Queries II
Problem Link: https://cses.fi/problemset/task/1688
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}
#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define L cout<<'\n';
#define E cerr<<'\n';
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const ll inf = 1LL<<62;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

int p[21][200005];
vi adj[200005];
int lev[200005];
void dfs(int s, int p) {
    for (auto i: adj[s]){
        if (i!=p) {
            lev[i] = lev[s] + 1;
            dfs(i,s);
        }
    }
}
int raise(int x, int y) {
    int z=0;
    while(y>0) {
        if (y&1) x = p[z][x];
        z++; y>>=1;
    }
    return x;
}
int lca(int x, int y) {
    if (lev[x] > lev[y]) swap(x,y);
    int d = lev[y] - lev[x];
    y = raise(y,d);
    if (x == y) return x;
    rev(i,20,-1) {
        if (p[i][x] != p[i][y]) {
            x = p[i][x];
            y = p[i][y];
        }
    }
    return p[0][x];
}
void solve(){
    int n,q; see(n,q);
    rep(i,2,n+1){
        int x; see(x);
        p[0][i] = x;
        adj[x].pb(i), adj[i].pb(x);
    }
    rep(i,1,21) {
        rep(j,1,n+1){
            p[i][j] = p[i-1][p[i-1][j]];
        }
    }
    dfs(1,0);
    while(q--){
        int x,y; see(x,y);
        putl(lca(x,y));
    }
}    
signed main(){
    IOS;
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    //cin>>t;
    rep(i,1,t+1){
        solve();
        cout<<'\n';
    }
    #ifdef LOCAL
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}