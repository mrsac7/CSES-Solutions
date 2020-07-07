/*
Problem Name: Meet in the Middle
Problem Link: https://cses.fi/problemset/task/1628
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<int,int, custom_hash> mp;
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, k; cin>>n>>k;
    vector<int> v1, v2;
    for (int i = 0; i < n/2; i++) {
        int x; cin>>x;
        v1.push_back(x);
    }
    for (int i = n/2; i < n; i++) {
        int x; cin>>x;
        v2.push_back(x);
    }
    int n1 = n/2;
    int n2 = n - n/2;
    for (int i = 0; i < (1<<n1); i++) {
        int x = 0, y = 0, st = i;
        while(st > 0) {
            if (st&1) x += v1[y];
            y++; st>>=1;
        }
        mp[x]++;
    }
    int ans = 0;
    for (int i = 0; i < (1<<n2); i++) {
        int x = 0, y = 0, st = i;
        while(st > 0) {
            if (st&1) x+= v2[y];
            y++; st>>=1;
        }
        if (mp.count(k-x)) ans += mp[k-x];
    }
    cout<<ans;
}