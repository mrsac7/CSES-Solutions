/*
Problem Name: Counting Tilings
Problem Link: https://cses.fi/problemset/task/2181
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int dp[1003][1030], n,m;
const int md = 1e9+7;

void solve(int x = 0, int y = 0, int mask = 0, int next_mask = 0) {
    if (x == n)
        return;
    if (y >= m)
        (dp[x+1][next_mask] += dp[x][mask])%=md;
    else
    {
        int my_mask = 1 << y;
        if (mask & my_mask)
            solve (x, y+1, mask, next_mask);
        else
        {
            solve (x, y+1, mask, next_mask | my_mask);
            if (y+1 < m && ! (mask & (my_mask << 1)))
                solve (x, y+2, mask, next_mask);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    cin>>m>>n;
    dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1<<m); j++) {
			solve(i, 0, j, 0);
		}
	}    
	cout<<dp[n][0];
}