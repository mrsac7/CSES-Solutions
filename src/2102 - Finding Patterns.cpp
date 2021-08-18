/*
Problem Name: Finding Patterns
Problem Link: https://cses.fi/problemset/task/2102
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1e5+5;
int sa[mxN], pos[mxN], tmp[mxN];
int gap, N;
string S;

bool comp(int x, int y) {
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}

void suffix() {
    for (int i = 0; i < N; i++)
        sa[i] = i, pos[i] = S[i];

    for (gap = 1;; gap <<= 1) {
        sort(sa, sa+N, comp);
        for (int i = 0; i < N-1; i++)
            tmp[i+1] = tmp[i] + comp(sa[i], sa[i+1]);
        for (int i = 0; i < N; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}

int check(int m, string &x) {
    int f = -1, k = x.size(), j = sa[m];
    if (N - j >= k) 
        f = 0;
    for (int i = 0; i < min(N - j, k); i++) {
        if (S[j+i] < x[i])
            return -1;
        if (S[j+i] > x[i])
            return 1;
    }
    return f;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    cin>>S;
    N = S.size();
    suffix();
    int t; cin>>t;
    while (t--) {
        string x; cin>>x;
        int l = 0, r = N - 1;
        int f = 0;
        while (l <= r) {
            int m = l + (r-l)/2;
            int v = check(m, x);
            if (v == 0) {
                f = 1;
                break;
            }
            else if (v == -1)
                l = m + 1;
            else
                r = m - 1;
        }
        cout << (f ? "YES" : "NO") << endl;
    }
}