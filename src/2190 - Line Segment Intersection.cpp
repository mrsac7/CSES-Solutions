/*
Problem Name: Line Segment Intersection
Problem Link: https://cses.fi/problemset/task/2190
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define P complex<int>
#define X real()
#define Y imag()

int cross(P a, P b, P c) {
    P u = b - a;
    P v = c - a;
    return (conj(u)*v).Y;
}

bool comp(const P &a, const P &b) {
    return (a.X == b.X) ? (a.Y < b.Y) : (a.X < b.X);
}

bool mid(P a, P b, P c) {
    vector<P> v = {a, b, c};
    sort(v.begin(), v.end(), comp);
    return (v[1] == c);
}

int sgn(int x) {
    return (x > 0) - (x < 0);
}

bool check(P a, P b, P c, P d) {
    int cp1 = cross(a, b, c);
    int cp2 = cross(a, b, d);
    int cp3 = cross(c, d, a);
    int cp4 = cross(c, d, b);
    if (cp1 == 0 && mid(a, b, c)) return 1;
    if (cp2 == 0 && mid(a, b, d)) return 1;
    if (cp3 == 0 && mid(c, d, a)) return 1;
    if (cp4 == 0 && mid(c, d, b)) return 1;
    if (sgn(cp1) != sgn(cp2) && sgn(cp3) != sgn(cp4)) return 1;
    return 0;
}


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin>>t;
    while (t--) {
        int x, y;
        P a, b, c, d;
        cin >> x >> y; a = {x, y};
        cin >> x >> y; b = {x, y};
        cin >> x >> y; c = {x, y};
        cin >> x >> y; d = {x, y};
        cout << (check(a, b, c, d) ? "YES" : "NO") << endl;
    }
}