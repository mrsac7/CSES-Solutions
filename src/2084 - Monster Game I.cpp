/*
Problem Name: Monster Game I
Problem Link: https://cses.fi/problemset/task/2084
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, k; cin >> n >> k;
    vector<pair<int, int>> S = {{k, 0}};
    vector<int> v = {1};
    int s[n], f[n];
    for (auto &i: s)
        cin >> i;
    for (auto &i: f)
        cin >> i;
    int c = 0;
    for (int i = 0; i < n; i++) {
        int x = s[i];
        int it = upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
        int m = f[i];
        c = x*S[it].F + S[it].S;
        if (S.back().F == m) continue; // if same slope then always bad line
        while (S.size() >= 2) {
            auto y2 = S[S.size() - 1];
            auto y3 = S[S.size() - 2];
            if ((y2.S - c)*(m - y3.F) < (y3.S - c)*(m - y2.F)) {
                S.pop_back();
                v.pop_back();
            }
            else break;
        }
        int x1 = ceil((S.back().S - c)*1.0/(m - S.back().F));
        v.push_back(x1);
        S.push_back({m, c});
    }
    cout << c;
}