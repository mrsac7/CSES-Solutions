/*
Problem Name: Labyrinth
Problem Link: https://cses.fi/problemset/task/1193
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
const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

int vis[1000005]={0};
vi adj[1000005];
queue<int> q;
int par[1000005];
bool bfs(int s){
    vis[s]=1;
    q.push(s);
    while(!q.empty()){
        int s = q.front(); q.pop(); 
        for( auto i: adj[s]){
            if (vis[i]) continue;
            vis[i]=vis[s]+1;
            par[i]=s;
            q.push(i);
        }
    }
    return 0;
}
void solve(){
    int n,m; see(n,m);
    char grid[n][m];
    int st=0, end=0;
    rep(i,0,n){
        rep(j,0,m){
            int z = i*m+j;
            see(grid[i][j]);
            if (grid[i][j]=='#') continue;
            if (grid[i][j]=='A') st=z;
            if (grid[i][j]=='B') end=z;
            if (i>=1 && grid[i-1][j]!='#') adj[z].pb(z-m), adj[z-m].pb(z);
            if (j>=1 && grid[i][j-1]!='#') adj[z].pb(z-1), adj[z-1].pb(z);
        }
    }
    bfs(st);
    if (!vis[end]){put("NO"); return;}
    vi v; int i = end;
    while (i!=st){
        v.pb(i);i=par[i];
    }
    putl("YES");putl(v.sz);
    int x = st/m, y = st%m;
    string ans="";
    rev(i,v.sz-1,-1){
        int x1 = v[i]/m, y1 = v[i]%m;
        if (x==x1) ans+=(y>y1?'L':'R');
        else ans+=(x>x1?'U':'D'); 
        x = x1, y = y1;
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