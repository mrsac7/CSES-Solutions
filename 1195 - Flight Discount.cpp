/*
Problem Name: Flight Discount
Problem Link: https://cses.fi/problemset/task/1195
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
const ll inf = 10000000000000000LL;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

const int N = 100005;
int vis[N];
int dis1[N],dis2[100005];
void dij(int s, int dis[], vii adj[]){
    priority_queue<pii> q;
    rep(i,1,N) dis[i]=inf;
    dis[s]=0;
    q.push({0,s});
    memset(vis,0,sizeof vis);
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

void solve(){
    int n,m; see(n,m);
    vii adj1[n+1], adj2[n+1];
    vc<tuple<int,int,int>> e;
    rep(i,0,m){
        int a,b,w; see(a,b,w);
        e.pb({a,b,w});
        adj1[a].pb({b,w});
        adj2[b].pb({a,w});
    }
    dij(1,dis1,adj1);
    dij(n,dis2,adj2);
    int mn = inf;
    for (auto [a,b,w]:e){
        mn = min(mn, dis1[a]+ dis2[b]+ w/2);
    }
    put(mn);
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