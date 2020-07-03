/*
Problem Name: Range Queries and Copies
Problem Link: https://cses.fi/problemset/task/1737
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

//persistent segment tree

int cur = 1, n, q;
vector<int> ver;
const int mxN = 2e5;
struct node {
    int left, right, sum;
} seg[mxN*40];

void update(int &root, int idx, int val, int l = 0, int h = n-1) {
    seg[cur].left = seg[root].left;
    seg[cur].right = seg[root].right;
    seg[cur].sum = seg[root].sum + val;
    root = cur; cur++;
    int mid = (l+h)/2;
    if (l == h)
        return;
    if (idx <= mid)
        update(seg[root].left, idx, val, l, mid);
    else
        update(seg[root].right, idx, val, mid+1, h);
}

int query(int root, int a, int b, int l = 0, int h = n-1) {
    if (a<=l && h<=b)
        return seg[root].sum;
    int mid = (l+h)/2;
    return (a<=mid?query(seg[root].left, a, b, l, mid):0) +
           (mid<b?query(seg[root].right, a, b, mid+1, h):0);
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    cin>>n>>q;
    ver.push_back(0);
    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        update(ver[0], i, x);
    }
    while(q--) {
        int ch; cin>>ch;
        if (ch == 1) {
            int k, a, x; cin>>k>>a>>x;
            k--, a--;
            update(ver[k], a, x - query(ver[k], a, a));
        }
        else if (ch == 2) {
            int k, a, b; cin>>k>>a>>b;
            k--, a--, b--;
            cout<<query(ver[k], a, b)<<endl;
        }
        else {
            int k; cin>>k;
            ver.push_back(ver[k-1]);
        }
    }

}
