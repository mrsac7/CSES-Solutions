/*
Problem Name: Polygon Lattice Points
Problem Link: https://cses.fi/problemset/task/2193
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define P complex<int>
#define X real()
#define Y imag()



signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    //pick's theorem + https://math.stackexchange.com/a/301895/530789
    int n; cin >> n;
    vector<P> v(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v[i] = {x, y};
    }
    v.push_back(v[0]);
    int area = 0;
    int b = 0;
    for (int i = 0; i < n; i++) {
        P x = v[i], y = v[i+1];
        area += (conj(x) * y).Y;
        P z = y - x;
        int g = __gcd(z.X, z.Y);
        b += abs(g);
    }
    //2*area = 2*a + b - 2
    int a = abs(area) - b + 2;
    cout << a/2 << ' ' << b;
}