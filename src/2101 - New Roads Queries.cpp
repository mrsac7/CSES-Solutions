/*
Problem Name: New Roads Queries
Problem Link: https://cses.fi/problemset/task/2101
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define endl '\n'
#define F first
#define S second

const int mxN = 2e5+5;
int par[mxN], len[mxN];

void init() {
    for (int i = 0; i < mxN; i++)
        par[i] = i, len[i] = 1;
}

int find(int x) {
    if (par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (len[x] < len[y])
            swap(x, y);
        par[y] = x;
        len[x] += len[y];
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, m, t; cin >> n >> m >> t;
    vector<pair<int, int>> edges(m);
    for (auto &[i, j]: edges)
        cin >> i >> j;
    vector<pair<int, int>> v(t);
    for (auto &[i, j]: v)
        cin >> i >> j;

    vector<pair<int, int>> range(t);
    vector<int> ans(t, -1);
    for (int i = 0; i < t; i++) {
        range[i] = {0, m};
    }
    
    while (1) {
        init();
        vector<pair<int, int>> mid;
        for (int i = 0; i < t; i++) if (range[i].F <= range[i].S) {
            int m = (range[i].F + range[i].S) / 2;
            mid.push_back({m, i});
        }
        if (mid.size() == 0)
            break;

        sort(mid.begin(), mid.end());
        int j = 0;
        for (int i = 0; i <= m; i++) {
            if (i) join(edges[i-1].F, edges[i-1].S);
            while (j < mid.size() && mid[j].F == i) {
                int k = mid[j].S;
                if (find(v[k].F) == find(v[k].S)) {
                    ans[k] = i;
                    range[k] = {range[k].F, i-1};
                }
                else {
                    range[k] = {i+1, range[k].S};                    
                }
                j++;
            }
        }
    }
    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;
}