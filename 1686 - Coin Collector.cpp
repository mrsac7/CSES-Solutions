/*
Problem Name: Coin Collector
Problem Link: https://cses.fi/problemset/task/1686
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
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
const ll inf = 1LL<<62;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

vi a1[100005], a2[100005];
unordered_set<int> b[100005];
bool vis[100005];
int comp[100005];
int sm[100005];
int k = 0;
vi t;
void dfs(int s){
    if (vis[s]) return;
    vis[s]=1;
    for (auto i: a1[s]) dfs(i);
    t.pb(s);
}

void dfs2(int s){
    if (vis[s]) return;
    comp[s]=k; vis[s]=1;
    for (auto i: a2[s]) dfs2(i);
}
void solve(){
    int n,m; see(n,m);
    int c[n+1]; seea(c,1,n+1);
    while(m--){
        int u,v ;see(u,v);
        a1[u].pb(v); a2[v].pb(u);
    }
    rep(i,1,n+1) if (!vis[i]) dfs(i);
    memset(vis,0,sizeof vis);
    rev(i,t.sz-1,-1){
        int u = t[i];
        if (!vis[u]) {k++; dfs2(u);}
    }
    rep(i,1,n+1){
        sm[comp[i]]+= c[i];
    }
    rep(i,1,n+1){
        for (auto j: a1[i]){
            if (comp[i]!=comp[j])b[comp[i]].insert(comp[j]);
        }
    }
    vi v; memset(vis,0,sizeof vis);
    while(!t.empty()){
        int i = t.back(); t.pop_back();
        if (!vis[comp[i]]) {v.pb(comp[i]); vis[comp[i]]=1;}
    }
    while(!v.empty()){
        int u = v.back(); v.pop_back();
        int mx = sm[u];
        for (auto i: b[u]){
            mx = max(mx,sm[u]+sm[i]);
        }
        sm[u] = mx;
    }
    put(*max_element(sm+1,sm+k+1));
}    
signed main(){
    IOS;
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        //cout<<'\n';
    }
    #ifdef LOCAL
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}