/*
Problem Name: Giant Pizza
Problem Link: https://cses.fi/problemset/task/1684
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

int tval[200005];
vi adj[200005], adj2[200005];
vi v;
bool vis[200005];
void dfs(int s){
    if (vis[s]) return;
    vis[s]=1;
    for (auto i: adj[s]) dfs(i);
    v.pb(s);
}
int k=0;
int comp[200005];
void dfs2(int s){
    if (vis[s]) return;
    vis[s]=1; comp[s]=k;
    for (auto i: adj2[s]) dfs2(i);
}
void solve(){
    int n,m; see(n,m);
    //2sat
    rep(i,0,n){
        char x,y;
        int a,b; see(x,a,y,b);
        if (x=='-') a=2*m-a+1;
        if (y=='-') b=2*m-b+1;
        adj[2*m-a+1].pb(b), adj[2*m-b+1].pb(a);
        adj2[a].pb(2*m-b+1), adj2[b].pb(2*m-a+1);
    }
    rep(i,1,2*m+1){
        if (!vis[i]) dfs(i);
    }
    memset(vis,0,sizeof vis);
    for (auto i=v.rbegin();i!=v.rend();i++){
        int x = *i;
        if (!vis[x]){k++; dfs2(x);}
    }
    rep(i,1,m+1){
        if (comp[i]==comp[2*m-i+1]){put("IMPOSSIBLE"); return;}
        tval[i] = (comp[i]>comp[2*m-i+1]);
    }
    rep(i,1,m+1){
        put((tval[i])?'+':'-');
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
    while(t--){
        solve();
        //cout<<'\n';
    }
    #ifdef LOCAL
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}