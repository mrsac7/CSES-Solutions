/*
Problem Name: Common Divisors
Problem Link: https://cses.fi/problemset/task/1081
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

#define MAX 1000005
int spf[MAX];
int xpow(int x, unsigned int y){
    int res=1;
    while(y>0){
        if (y&1) res= (res*x); y=y>>1; x=(x*x);
    }
    return res;
}
void sievespf(int n) {
    for (int i=1; i<=n; i++){
        spf[i] = i;
    }
    for (int p=2; p*p<=n; p++) {
        if (spf[p] == p) {
            for (int i=p*p; i<=n; i += p) 
                if (spf[i]==i) spf[i]=p; 
        }
    } 
} 
int d[1000001];
vii f;
void rec(int x, int i){
    if (i==f.sz) {d[x]++;return;}
    rep(j,0,f[i].S+1){
        rec(x*xpow(f[i].F,j),i+1);
    }
}
void solve(){
    int n; see(n);
    rep(i,0,n){
        int x; see(x);
        map<int,int> fac;
        f.clear();
        while(x!=1){
            int y = spf[x];
            while(x%y==0) fac[y]++,x/=y;
        }
        for (auto [i,j]: fac) f.pb({i,j});
        rec(1,0);
    }
    rev(i,1000000,0){
        if (d[i]>1) {put(i); return;}
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
    sievespf(1000001);
    while(t--){
        solve();
        //cout<<'\n';
    }
    #ifdef LOCAL
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}