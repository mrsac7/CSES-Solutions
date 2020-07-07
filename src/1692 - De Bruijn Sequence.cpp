/*
Problem Name: De Bruijn Sequence
Problem Link: https://cses.fi/problemset/task/1692
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


unordered_map<string,int> mp;
string mp2[100005];
int k=0,n;
void rec(string s){
    if (s.sz==n-1) {mp[s]=++k; mp2[k] = s; return;}
    rec(s+'0');
    rec(s+'1');
}
vc<pair<int,char>> adj[100005];
void solve(){
    see(n);
    if (n==1) {put("01"); return;}
    rec("");
    int t = (1<<(n-1));
    rep(i,1,t+1){
        string x = mp2[i].substr(1,n-2);
        adj[i].pb({mp[x+"0"],'0'});
        adj[i].pb({mp[x+"1"],'1'});
    }
    //eulerian path always exists
    string path;
    stack<pair<int,char>> st;
    st.push({1,'#'});
    while(!st.empty()){
        auto [i,c] = st.top();
        if (adj[i].sz==0) {if (c!='#')path+=c; st.pop();}
        else{
            auto [j,c2] = adj[i].back(); adj[i].pop_back();
            st.push({j,c2});
        }
    }
    path+=mp2[1];
    put(path);
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