/*
Problem Name: Minimum Euclidean Distance
Problem Link: https://cses.fi/problemset/task/2194
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define P pair<int, int>
#define X first
#define Y second

int norm(P a, P b) {
    return (b.X - a.X) * (b.X - a.X) + (b.Y - a.Y) * (b.Y - a.Y);
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n;
    vector<P> v(n);
    int d = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v[i] = {x, y};
    }
    sort(v.begin(), v.end());
    set<P> s = {{v[0].Y, v[0].X}};
    int j = 0;
    for (int i = 1; i < n; i++) {
        auto it = s.begin();
        int dd = ceil(sqrt(d));
        while (j < i && v[j].X < v[i].X - dd) {
            s.erase({v[j].Y, v[j].X});
            j++;
        }

        auto l = s.lower_bound({v[i].Y - dd, 0});
        auto r = s.upper_bound({v[i].Y + dd, 0});
        for (auto it = l; it != r; it++) {
            d = min(d, norm({it->Y, it->X}, v[i]));
        } 
        s.insert({v[i].Y, v[i].X});
    }
    cout << d;
}