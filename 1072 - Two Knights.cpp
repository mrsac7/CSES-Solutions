/*
Problem Name: Two Knights
Problem Link: https://cses.fi/problemset/task/1072
Author: Sachin Srivastava (mrsac7)
*/
//----------HEADER----------
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
//----------TEMPLATES----------
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
//----------MACROS----------
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
#define nl cout<<'\n'
#define E cerr<<'\n'
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false)
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//----------CONSTANTS----------
const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
//----------GLOBALS----------
int rec(int n){
	if (n==1) {putl(0); return 0;}
	int c=0;
	int t=n*n-1;
	rep(i,1,n+1){
		int x=0;
		if (1+1<=n && i+2<=n) x++;
		if (1+2<=n && i+1<=n) x++;
		if (1+2<=n && i-1>0) x++;
		if (1+1<=n && i-2>0) x++;
		c = c+ t-x;
		t--;
	}
	rep(i,2,n+1){
		int x=0;
		if (i+1<=n && 1+2<=n) x++;
		if (i+2<=n && 1+1<=n) x++;
		if (i-1>0 && 1+2<=n && i!=2) x++;
		if (i-2>0 && 1+1<=n && i!=3) x++;
		c = c+ t-x;
		t--;
	}
	c = c+ rec(n-1);
	putl(c);
	return c;
}
//----------SOLUTION----------
void solve(){
	int n; see(n);
	rec(n);
}	
//----------MAIN----------
signed main(){
	IOS;
	#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r" , stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
    	solve();
    	//cout<<'\n';
    }
}