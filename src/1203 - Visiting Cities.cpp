/*
Problem Name: Visiting Cities
Problem Link: https://cses.fi/problemset/task/1203
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1e5+5, INF = 1LL<<60;
int md1, md2;
int dis[mxN], vis[mxN], dp[mxN][2][2];
vector<pair<int, int>> adj[mxN];
vector<int> G[mxN], H[mxN]; 

void bfs(int s) {
    fill(dis, dis + mxN, INF);
    dis[s] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    while (!q.empty()) {
        auto [c, x] = q.top(); q.pop();
        if (abs(c) > dis[x]) continue;
        for (auto [i, w]: adj[x]) {
            if (dis[x] + w < dis[i]) {
                dis[i] = dis[x] + w;
                q.push({-dis[i], i});
            }
        }
    }
    for (int i = 1; i < mxN; i++) {
        for (auto [j, w]: adj[i]) {
            if (dis[j] == dis[i] + w) {
                G[i].push_back(j);
                H[j].push_back(i);
            }
        }
    }
}

vector<int> v;
void dfs(int s, vector<int> G[]) {
    if (vis[s]) return;
    vis[s] = 1;
    for (auto i: G[s]) {
        dfs(i, G);
    }
    v.push_back(s);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    md1 = uniform_int_distribution<int>(1e9+73, 1e9+7337)(rng);
    md2 = uniform_int_distribution<int>(1e9+13, 1e9+73)(rng);
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, c; cin >> x >> y >> c;
        adj[x].push_back({y, c});
    }
    bfs(1);
    dfs(1, G);
    reverse(v.begin(), v.end());
    dp[1][0][0] = dp[1][0][1] = 1;
    for (auto i: v) {
        for (int j: G[i]) {
            (dp[j][0][0] += dp[i][0][0]) %= md1;
            (dp[j][0][1] += dp[i][0][1]) %= md2;
        }
    }
    v.clear();
    memset(vis, 0, sizeof vis);
    dfs(n, H);
    reverse(v.begin(), v.end());
    dp[n][1][0] = dp[n][1][1] = 1;
    for (auto i: v) {
        for (int j: H[i]) {
            (dp[j][1][0] += dp[i][1][0]) %= md1;
            (dp[j][1][1] += dp[i][1][1]) %= md2;
        }
    }
    int x1 = dp[n][0][0];
    int x2 = dp[n][0][1];
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (x1 == dp[i][0][0] * dp[i][1][0] % md1 && x2 == dp[i][0][1] * dp[i][1][1] % md2)
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto i: ans)
        cout << i << ' ';
}