/*
Problem Name: Bit Inversions
Problem Link: https://cses.fi/problemset/task/1188
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
    set<int> up, lo;
    int n = s.size();
    int l = 0, r = 0;
    up.insert(0);
    lo.insert(0);
    multiset<int> ans;
    int mx = 0;
    while (l < n) {
        r = l + 1;
        while(r < n && s[r] == s[l]) r++;
        up.insert(r);
        lo.insert(-r);
        ans.insert(r-l);
        l = r;
    }
    int q; cin>>q;
    while(q--) {
        int x; cin>>x;
        int r = n, l = 0;
        if (x < n)
            r = *up.upper_bound(x);
        if (x > 1)
            l = -*lo.upper_bound(1-x);
        if (up.count(x) && up.count(x-1)) {
            if (r-x) 
                ans.erase(ans.find(r-x));
            if (x-1-l)
                ans.erase(ans.find(x-1-l));
            ans.erase(ans.find(1));
            if (x != n)
                up.erase(x), lo.erase(-x);
            if (x-1)
                up.erase(x-1), lo.erase(1-x);
            ans.insert(r-l);
        }
        else if (up.count(x-1)) {
            if (r-x+1)
                ans.erase(ans.find(r-x+1));
            if (x-1-l)
                ans.erase(ans.find(x-1-l));
            if (x-1)
                up.erase(x-1), lo.erase(1-x);
            if (x-l)
                ans.insert(x-l);
            if (r-x)
                ans.insert(r-x);
            up.insert(x); lo.insert(-x);
        }
        else if (up.count(x)) {
            if (r-x)
                ans.erase(ans.find(r-x));
            if (x-l)
                ans.erase(ans.find(x-l));
            if (x != n)
                up.erase(x), lo.erase(-x);
            if (x-1-l)
                ans.insert(x-1-l);
            if (r-x+1)
                ans.insert(r-x+1);
            up.insert(x-1); lo.insert(1-x);
        }
        else {
            if (r-l)
                ans.erase(ans.find(r-l));
            up.insert(x); lo.insert(-x);
            up.insert(x-1); lo.insert(1-x);
            if (x-1-l)
                ans.insert(x-1-l);
            if (r-x)
                ans.insert(r-x);
            ans.insert(1);
        }
        cout<<*ans.rbegin()<<' ';
    }
}