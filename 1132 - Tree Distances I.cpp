/*
Problem Name: Tree Distances I
Problem Link: https://cses.fi/problemset/task/1132
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

vi adj[200005];
pii mx[200005][2];
void dfs(int s, int p){
    pii a={-1,-1} ,b = {-1,-1};
    for (auto i: adj[s]){
        if (i!=p) {
            dfs(i,s);
            if (mx[i][0].F > a.F) {
                b = a, a = {mx[i][0].F,i};
            }
            else if (mx[i][0].F > b.F) {
                b = {mx[i][0].F, i};
            }
        }
    }
    mx[s][0] = {a.F+1,a.S};
    mx[s][1] = {b.F+1,b.S};
}
void dfs2(int s, int p){
    if (mx[p][0].S != s && p) {
        if (mx[s][0].F < mx[p][0].F+1) {
            mx[s][1] = mx[s][0];
            mx[s][0] = {mx[p][0].F+1,p}; 
        }
        else if (mx[s][1].F < mx[p][0].F +1) {
            mx[s][1] = {mx[p][0].F+1,p};
        }
    }
    else if (p){
        if (mx[s][0].F < mx[p][1].F+1) {
            mx[s][1] = mx[s][0];
            mx[s][0] = {mx[p][1].F+1,p}; 
        }
        else if (mx[s][1].F < mx[p][1].F +1) {
            mx[s][1] = {mx[p][1].F+1,p};
        }
    }
    for (auto i: adj[s]){
        if (i!=p) dfs2(i,s);
    }
}
void solve(){
    int n; see(n);
    rep(i,0,n-1){
        int x,y; see(x,y);
        adj[x].pb(y), adj[y].pb(x);
    }
    dfs(1,0);
    dfs2(1,0);
    rep(i,1,n+1) put(mx[i][0].F);
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