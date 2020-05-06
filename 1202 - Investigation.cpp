/*
Problem Name: Investigation
Problem Link: https://cses.fi/problemset/task/1202
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

const int N = 100005;
int vis[N];
int dis[N];
priority_queue<pii> q;
vi adj2[100005];
vii adj[100005];
void dij(int s){
    rep(i,1,N) dis[i]=inf;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int a = q.top().S; q.pop();
        if (vis[a]) continue;
        vis[a]=1;
        for (auto [b,w]: adj[a]){
            if (dis[a]+w < dis[b]){
                dis[b] = dis[a]+w;
                q.push({-dis[b],b});
            }
        }
    }
}
bool v2[100005];
vi v;
void dfs(int s){
    if (v2[s]) return;
    v2[s]=1;
    for (auto i: adj2[s]) dfs(i);
    v.pb(s);
}
int path[100005], mx[100005], mn[100005];
void solve(){
    //dijkstra + dp
    int n,m; see(n,m);
    rep(i,0,m){
        int a,b,w; see(a,b,w);
        adj[a].pb({b,w});
    }
    dij(1);
    rep(i,1,n+1){
        for (auto [j,w]: adj[i]){
            if (dis[j]==dis[i]+w) adj2[j].pb(i);
        }
    }
    rep(i,1,n+1){
        if (!v2[i]) dfs(i);
    }
    vi t; int f=0;
    rep(i,0,v.sz){
        if (v[i]==1) f=1;
        if (f) t.pb(v[i]);
    }
    rep(i,1,n+1) mn[i] = inf;
    path[1]=1, mx[1]=1, mn[1]=1;
    for (auto i : t){
        for (auto j: adj2[i]){
            (path[i]+=path[j])%=md;
            if ( mn[i] > mn[j]+1 && mn[j]) mn[i] = mn[j]+1;
            if (mx[i] < mx[j]+1 && mx[j]) mx[i] = mx[j]+1;

        }
    }
    put(dis[n], path[n], mn[n]-1, mx[n]-1);
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