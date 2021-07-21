/*
Problem Name: Prefix Sum Queries
Problem Link: https://cses.fi/problemset/task/2166
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define lsum first
#define sum second


const int N = 1LL<<19;
pair<int,int> tree[N];

int n;
void upd(int k, int x){
    k+=n;
    tree[k] = {x, x}; k>>=1;
    while(k>=1){
        tree[k].sum = tree[2*k].sum + tree[2*k+1].sum;
        tree[k].lsum = max(tree[2*k].lsum, tree[2*k].sum + tree[2*k+1].lsum);
        k>>=1;
    }
}
int qry(int a, int b){
    a+=n, b+=n;
    pair<int, int> x = {0, 0}, y = {0, 0};
    while(a<=b){
        if (a&1) 
            x = {max(x.lsum, x.sum + tree[a].lsum),  x.sum + tree[a++].sum};
        if (~b&1) 
            y = {max(tree[b].lsum, tree[b].sum + y.lsum), y.sum + tree[b--].sum}; 
        a>>=1, b>>=1;
    }
    return max(x.lsum, x.sum + y.lsum);
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin>>n>>t;
    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        upd(i, x);
    }
    while(t--) {
        int x, a, b; cin>>x>>a>>b;
        if (x == 1)
            upd(a-1, b);
        else
            cout<<qry(a-1, b-1)<<endl;
    }
    
}