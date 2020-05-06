/*
Problem Name: Distinct Values Queries
Problem Link: https://cses.fi/problemset/task/1734
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

int a[200005];
map<int,int> mp;
bool comp(tiii x, tiii y){
    return get<1>(x) > get<1>(y);
}
int T[200005];
int n;
void U(int k, int x) {
    for (; k <= n; k += k&-k) T[k] += x;
}
int Q(int k) {
    int s = 0;
    for (; k > 0; k -= k&-k) s += T[k];
    return s;
}
int vis[200005];
int qry[200005];
void solve(){
    int q; see(n,q);
    seea(a,0,n);
    int id = 1;
    rep(i,0,n) {
        if (mp.find(a[i]) == mp.end()) mp[a[i]] = id++;
        a[i] = mp[a[i]];
    }
    vc<tiii> v;
    rep(i,0,q) {
        int x,y; see(x,y);
        v.pb({x,y,i});
    }
    sort(all(v), comp);
    memset(vis, -1, sizeof vis);
    rep(i,0,n) {
        if (vis[a[i]] != -1) U(vis[a[i]] + 1, -1);
        vis[a[i]] = i;
        U(i+1, 1);
        while (v.sz && get<1>(v.back()) == i+1) {
            auto [l,r,x] = v.back();
            v.pop_back();
            qry[x] = Q(r) - Q(l-1);
        }
    }
    rep(i,0,q) putl(qry[i]);
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