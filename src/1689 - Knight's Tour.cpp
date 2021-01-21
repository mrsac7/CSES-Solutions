/*
Problem Name: Knight's Tour
Problem Link: https://cses.fi/problemset/task/1689
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

const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};
const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1};

int grid[9][9];

int deg(int x1, int y1){
    int s = 0;
    rep(i1,0,8){
        int x2 = x1+fx[i1], y2 = y1+fy[i1];
        if (x2>=1 && x2<=8 && y2>=1 && y2<=8 && !grid[x2][y2]) s++;
    }
    return s;
}
bool rec(int mv, int x, int y){
    grid[x][y] = mv;
    if (mv == 64) return 1;
    vc<tiii> v;
    rep(i,0,8){
        int x1 = x+fx[i], y1 = y+fy[i];
        if (x1>=1 && x1<=8 && y1>=1 && y1<=8 && !grid[x1][y1]){
            int d = deg(x1,y1);
            v.pb({d,x1,y1});
        }
    }
    sort(all(v));
    for (auto [d,x1,y1]: v){
        if (rec(mv+1,x1,y1)) return 1;
    }
    grid[x][y]=0;
    return 0;
}
void solve(){
    int x,y; see(y,x);
    rec(1,x,y);
    rep(i,1,9){
        rep(j,1,9){
            printf("%-2d ",grid[i][j]);
        }
        printf("\n");
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
