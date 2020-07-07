/*
Problem Name: Tree Traversals
Problem Link: https://cses.fi/problemset/task/1702
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<int> pre, in;
int a[100005];
void post(int l1, int h1, int l2, int h2) {
    if (l1 > h1)
        return;
    int i = a[pre[l1]];
    post(l1+1, l1+1+i-l2-1, l2, i);
    post(l1+1+i-l2, h1, i+1, h2);
    cout<<in[i]<<' ';
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n;
    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        pre.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        in.push_back(x);
        a[x] = i;
    }
    post(0,n-1,0,n-1);
}
