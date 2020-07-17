/*
Problem Name: String Transform
Problem Link: https://cses.fi/problemset/task/1113
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
    
    string s; cin>>s;
    vector<int> v;
    vector<int> a[26];
    int n= s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '#')
            v.push_back(i);
        else
            a[s[i]-'a'].push_back(i);
    }
    for (int i = 0; i < 26; i++) {
        for (auto j: a[i])
            v.push_back(j);
    }
    string ans;
    int i = v[v[0]];
    while(s[i] != '#') {
        ans += s[i];
        i = v[i];
    }
    cout<<ans;
}