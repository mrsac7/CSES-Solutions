/*
Problem Name: Download Speed
Problem Link: https://cses.fi/problemset/task/1694
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

vc<tiii> adj[505];
int xpow(int x, unsigned int y){
    int res=1;
    while(y>0){
        if (y&1) res= (res*x); y=y>>1; x=(x*x);
    }
    return res;
}
int d,n;
bool vis[505];
int dfs(int s, int f){
    if (s==n) return f;
    vis[s]=1;
    for (auto &[i,w,j]: adj[s]) {
        if (w>=d && !vis[i]){
            int b = dfs(i,min(f,w));
            if (b>0){
                w-=b;
                get<1>(adj[i][j])+=b;
                return b;
            }
        }
    }
    return 0;
}
void solve(){
    int m; see(n,m);
    int mx = 0;
    rep(i,0,m){
        int x,y,w; see(x,y,w);
        mx = max(mx,w);
        int j1 = adj[x].sz;
        int j2 = adj[y].sz;
        adj[x].pb({y,w,j2}); //residual edge of x->y lies at index j2 in adj[y]
        adj[y].pb({x,0,j1});
    }
    d = xpow(2, (int) log2(mx));
    int ans=0;
    while(d>0){
        while(1){
            memset(vis,0,sizeof vis);
            int f = dfs(1,inf);
            ans+=f;
            if (f==0) break;
        }
        d>>=1;
    }
    put(ans);
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