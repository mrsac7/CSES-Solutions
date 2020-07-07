/*
Problem Name: Grid Paths
Problem Link: https://cses.fi/problemset/task/1625
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
string s;
bool vis[7][7];
bool check(int i, int j){
	int c=0;
	if (vis[i][j]) return 0;
	if (i-1>=0 && vis[i-1][j]==0) c++;
	if (i+1<7 && vis[i+1][j]==0) c++;
	if (j-1>=0 && vis[i][j-1]==0) c++;
	if (j+1<7 && vis[i][j+1]==0) c++;
	if (i==6 && j==0 && c>0) return 0;
	if (c<2) {
		return 1;
	}
	return 0;
}
bool trap(int i, int j){
	int x=0,y=0;
	if (i-1>=0 && vis[i-1][j]==0) y++;
	if (i+1<7 && vis[i+1][j]==0) y++;
	if (j-1>=0 && vis[i][j-1]==0) x++;
	if (j+1<7 && vis[i][j+1]==0) x++;
	if ((x==0 && y==2) || (x==2 && y==0)) return 1;
	return 0;
}
int c=0;
void rec(int mv,int i, int j){
	if (vis[i][j]) return;
	vis[i][j]=1;
	//diagonals
	int f=0;
	if (i==6 && j==0 ) {if(mv==48) c++; else {vis[i][j]=0;f+=1;}}
	if (i-1>=0 && j-1>=0 )f+=check(i-1,j-1);
	if (i-1>=0 && j+1<7 )f+=check(i-1,j+1);
	if (i+1<7 && j+1<7)f+=check(i+1,j+1);
	if (i+1<7 && j-1>=0)f+=check(i+1,j-1);
	f += trap(i,j);
	if (f!=0){ vis[i][j]=0;return;}
	// if (mv==48) {error(c,i,j);}
	if (mv<48){ 
		if (s[mv]=='?'){
			if (i-1>=0) rec(mv+1,i-1,j); //up
			if (i+1<7) rec(mv+1,i+1,j); //down
			if (j-1>=0) rec(mv+1,i,j-1); //left
			if (j+1<7) rec(mv+1,i,j+1); //right
		}
		else {
			if (s[mv]=='L' and j-1>=0) rec(mv+1,i,j-1);
			else if (s[mv]=='R' and j+1<7) rec(mv+1,i,j+1);
			else if (s[mv]=='U' and i-1>=0) rec(mv+1,i-1,j); 
			else if (s[mv]=='D' and i+1<7) rec(mv+1,i+1,j);
		}
	}
	vis[i][j]=0;
}

//----------SOLUTION----------
void solve(){
	see(s);
	rec(0,0,0);
	put(c);
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