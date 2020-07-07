/*
Problem Name: Subarray Sum Queries
Problem Link: https://cses.fi/problemset/task/1190
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

int seg[1000005][4], n;
//max, pre, suff, total
void update(int k, int x) {
    k+=n;
    rep(i,0,4) seg[k][i] = x;
    k>>=1;
    while(k>0) {
        seg[k][0] = max({seg[2*k][0], seg[2*k+1][0], seg[2*k][2] + seg[2*k+1][1], 0LL}); //max
        seg[k][1] = max({seg[2*k][1], seg[2*k][3] + seg[2*k+1][1], 0LL}); //pre
        seg[k][2] = max({seg[2*k][2] + seg[2*k+1][3], seg[2*k+1][2], 0LL}); //suff
        seg[k][3] = seg[2*k][3] + seg[2*k+1][3]; //total
        k>>=1;
    }
}
void solve(){
    int nn,q; see(nn,q);
    n = pow(2,ceil(log2(nn)));
    rep(i,0,nn) {
        int x; see(x);
        update(i,x);
    }
    while(q--) {
        int k,x; see(k,x);
        update(k-1,x);
        putl(seg[1][0]);
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
    rep(i,1,t+1){
        solve();
        cout<<'\n';
    }
    #ifdef LOCAL
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}