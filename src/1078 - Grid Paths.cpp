/*
Problem Name: Grid Paths
Problem Link: https://cses.fi/problemset/task/1078
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int md = 1e9+7, mxN = 2e6+6, N = 2e3+3;
int dp[N], F[mxN], I[mxN];

int exp(int x, int y, int md){
    int ans = 1;
    x = x%md;
    while (y > 0) {
        if (y&1)
            ans = ans*x%md;
        y = y>>1;
        x = x*x%md;
    }
    return ans;
}

int C(int n, int k) {
    if (k > n) return 0;
    return F[n] * I[k] % md * I[n-k] % md;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    F[0] = 1, I[0] = 1;
    for (int i = 1; i < mxN; i++) {
        F[i] = F[i-1] * i % md;
        I[i] = exp(F[i], md-2, md);
    }

    int n, k; cin >> n >> k;
    vector<pair<int, int>> v(k);
    for (auto &[i, j]: v) {
        cin >> i >> j;
        i--, j--;
    }
    v.push_back({n-1, n-1});

    sort(v.begin(), v.end());
    for (int i = 0; i <= k; i++) {
        auto [x, y] = v[i];
        dp[i] = C(x+y, x);
        for (int j = 0; j < i; j++) {
            auto [a, b] = v[j];
            if (b > y) continue;
            dp[i] = (dp[i] - dp[j] * C(x+y-a-b, x-a) % md + md) % md;
        }
    }
    cout << dp[k];
}