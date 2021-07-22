/*
Problem Name: Pizzeria Queries
Problem Link: https://cses.fi/problemset/task/2206
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second


const int N = 1LL<<19;
const int INF = 1LL<<60;
pair<int,int> tree[N];

int n;
void upd(int k, int x){
    k+=n;
    tree[k] = {x, x}; k>>=1;
    int dist = 1;
    while(k>=1){
        tree[k].F = min(tree[2*k].F, tree[2*k+1].F + dist);
        tree[k].S = min(tree[2*k+1].S, tree[2*k].S + dist);
        dist<<=1;
        k>>=1;
    }
}

pair<int, int> qry(int a, int b){
    a+=n, b+=n;
    pair<int, int> x = {INF, INF}, y = {INF, INF};
    int x_dist = 0;
    int y_dist = 0;
    int dist = 1;
    while(a<=b){
        if (a&1) {
            x.F = min(x.F, tree[a].F + x_dist);
            x.S = min(tree[a].S, x.S + dist);
            a++;
            x_dist += dist;
        }
        if (~b&1) {
            y.F = min(tree[b].F, y.F + dist);
            y.S = min(y.S, tree[b].S + y_dist);
            b--;
            y_dist += dist;
        }
        a>>=1, b>>=1, dist<<=1;
    }
    return {min(x.F, y.F + x_dist), min(y.S, x.S + y_dist)};
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int nn, t; cin>>nn>>t;
    n = 1<<((int) ceil(log2(nn)));
    for (int i = 0; i < N; i++)
        tree[i] = {INF, INF};
    for (int i = 0; i < nn; i++) {
        int x; cin>>x;
        upd(i, x);
    }
    while(t--) {
        int c; cin>>c;
        if (c == 1) {
            int a, b; cin>>a>>b;
            upd(a-1, b);
        }
        else {
            int a; cin>>a;
            pair<int, int> x = qry(0, a-1);
            pair<int, int> y = qry(a-1, nn-1);
            cout<<min(x.S, y.F)<<endl;
        }
    }
    
}