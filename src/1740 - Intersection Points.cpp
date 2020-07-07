/*
Problem Name: Intersection Points
Problem Link: https://cses.fi/problemset/task/1740
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 2000006;
int y[100005];
pair<int,int> ver[100005];
int bit[mxN] = {0};
void upd(int x, int v) {
    for (; x < mxN; x += (x&-x)) 
        bit[x] += v;
}

int qry(int x) {
    int ans = 0;
    for (; x > 0; x -= (x&-x)) 
        ans += bit[x];
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n;
    vector<tuple<int,int,int>> points; //x, 0/1/2, ind;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; 
        cin>>x1>>y1>>x2>>y2;
        if (x1 == x2) {
            points.push_back({x1, 1, i});
            ver[i] = {y1, y2};
        }
        else {
            points.push_back({x1, 0, i});
            points.push_back({x2, 2, i});
            y[i] = y1;
        }
    }
    sort(points.begin(), points.end());
    int ans = 0;
    for (auto [x, e, i]: points) {
        if (e == 0) {
            int yc = y[i];
            upd(yc+1e6+1, 1);
        } else if (e == 2) {
            int yc = y[i];
            upd(yc+1e6+1, -1);
        } else {
            auto [y1, y2] = ver[i];
            ans += qry(y2+1e6+1) - qry(y1+1e6);
        }
    }
    cout<<ans;
}