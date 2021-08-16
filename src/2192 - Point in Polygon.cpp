/*
Problem Name: Point in Polygon
Problem Link: https://cses.fi/problemset/task/2192
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
#define P complex<int>
#define X real()
#define Y imag()
 
const int INF = 1e9 + 7;
 
int cross(P a, P b, P c) {
    P u = b - a;
    P v = c - a;
    int cp = (conj(u)*v).Y;
    return (cp > 0) - (cp < 0);
}
 
bool comp(const P &a, const P &b) {
    return (a.X == b.X) ? (a.Y < b.Y) : (a.X < b.X);
}
 
bool mid(P a, P b, P c) {
    vector<P> v = {a, b, c};
    sort(v.begin(), v.end(), comp);
    return (v[1] == c);
}
 
bool check(P a, P b, P c, P d) {
    int cp1 = cross(a, b, c);
    int cp2 = cross(a, b, d);
    int cp3 = cross(c, d, a);
    int cp4 = cross(c, d, b);
    if (cp1 * cp2 < 0 && cp3 * cp4 < 0) return 1;
    if (cp3 == 0 && mid(c, d, a) && cp4 < 0) return 1;
    if (cp4 == 0 && mid(c, d, b) && cp3 < 0) return 1;
    return 0;
}
 
 
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
        
    //https://en.wikipedia.org/wiki/Point_in_polygon#Ray_casting_algorithm
    int n, m; cin >> n >> m;
    vector<P> v;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    v.push_back(v[0]);
    while (m--) {
        int x, y; cin >> x >> y;
        P a = {x, y};
        P b = {INF, INF};
        int cnt = 0;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            int cp = cross(v[i], v[i+1], a);
            if (cp == 0 && mid(v[i], v[i+1], a)) {
                flag = 1;
                break;
            }
            cnt += check(v[i], v[i+1], a, b);
        }
        if (flag) cout << "BOUNDARY" << endl;
        else cout << (cnt & 1 ? "INSIDE" : "OUTSIDE") << endl;
    }
}