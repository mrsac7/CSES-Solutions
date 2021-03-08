/*
Problem Name: Counting Towers
Problem Link: https://cses.fi/problemset/task/2413
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1e6+6;
int dp[mxN][3];

const int md = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
                                   
    //                                      _  _
    // dp[i][1] = last blocks are separate | || |
    //                                   _ _
    // dp[i][2] = last blocks are fused |   |
    
    // transition:
    //              _  _    _  _    _  _    _  _     _ _
    //  _  _       | || |  |_|| |  | ||_|  |_||_|   |_ _|
    // | || | =>   | || |, | || |, | || |, | || |,  | | |
    //              _ _    _ _    _ _ 
    //  _ _        |   |  |_|_|  |_ _|
    // |   |  =>   |   |, |   |, |   |

    // dp[i][1] = dp[i-1][1]*4 + dp[i-1][2]
    // dp[i][2] = dp[i-1][1] + dp[i-1][2]*2


    dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i < mxN; i++) {
        dp[i][1] = (dp[i-1][1]*4%md + dp[i-1][2])%md;
        dp[i][2] = (dp[i-1][1] + dp[i-1][2]*2%md)%md;
    }

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        cout<<(dp[n][1] + dp[n][2])%md<<endl;
    }

}