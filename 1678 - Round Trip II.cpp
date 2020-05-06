/*
Problem Name: Round Trip II
Problem Link: https://cses.fi/problemset/task/1678
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

vi adj[100005];
int vis[100005];
vi cyc;
bool dfs(int s){
    vis[s]=1;
    for (auto i: adj[s]) {
        cyc.pb(i);
        if (vis[i]==0) {if (dfs(i)) return 1;}
        else if (vis[i]==1){return 1;}
        cyc.pop_back();
    }
    vis[s]=2;
    return 0;
}
void solve(){
    int n,m; see(n,m);
    rep(i,0,m){
        int u,v; see(u,v);
        adj[u].pb(v);
    }
    rep(i,1,n+1){
        cyc.pb(i);
        if (!vis[i] && dfs(i)){
            vi ans={*cyc.rbegin()};
            for (auto j=cyc.rbegin()+1; j!=cyc.rend();j++){
                ans.pb(*j);
                if (*j==*cyc.rbegin()) break;
            }
            putl(ans.sz);
            reverse(all(ans));
            for (auto i: ans)  put(i);
            return;
        }
        cyc.pop_back();
    }
    put("IMPOSSIBLE");
 
}
signed main(){
    IOS;
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        // cout<<'\n';
    }
    #ifdef LOCAL
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}