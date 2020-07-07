/*
Problem Name: Cycle Finding
Problem Link: https://cses.fi/problemset/task/1197
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

void solve(){
    int n,m; see(n,m);
    vc<tuple<int,int,int>> e;
    rep(i,0,m){
        int a,b,w; see(a,b,w);
        e.pb({a,b,w});
    }
    //bellman-ford
    int dis[n+1], par[n+1]={0};
    rep(i,1,n+1) dis[i]=inf;
    dis[1]=0; 
    int f;
    rep(i,1,n+1){
        f=0;
        for (auto [a,b,w]: e){
            if (dis[a]+w<dis[b]){
                dis[b] = dis[a]+w;
                par[b] = a;
                f=b;
            }
        }
    }
    if (!f){put("NO"); return;}
    else{
        putl("YES");
        vi cyc;
        rep(i,1,n+1) f = par[f];
        for (int x = f;; x = par[x]){
            cyc.pb(x);
            if (x==f && cyc.sz>1) break;
        }
        
        reverse(all(cyc));
        for (auto i: cyc) put(i);
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