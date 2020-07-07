/*
Problem Name: Prüfer Code
Problem Link: https://cses.fi/problemset/task/1134
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n;
    vector<int> v(n-2);
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    int a[n+1] = {0};
    for (auto &i: v) {
        cin>>i;
        a[i]++;
        if (s.count(i))
            s.erase(i);
    }
    for (int i = 0; i < n-2; i++) {
        int x = *s.begin();
        s.erase(x);
        cout<<x<<' '<<v[i]<<endl;
        a[v[i]]--;
        if (a[v[i]] == 0) s.insert(v[i]);
    }
    cout<<*s.begin()<<' '<<*s.rbegin();
}