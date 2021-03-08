/*
Problem Name: Gray Code
Problem Link: https://cses.fi/problemset/task/2205
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n;
    int a[1<<n + 1] = {0};
    for (int i = 0; i < n; i++)
    	cout<<0;
    cout<<endl;
    a[0] = 1;
    int x = 0;
    for (int i = 1; i < 1<<n; i++) {
    	for (int j = 0; j < n; j++) {
    		int y = x^(1<<j);
    		if (!a[y]) {
    			x = y;
    			a[y] = 1;
				string s;
				while (y) {
					if (y&1) s += '1';
					else s += '0';
					y >>= 1;
				}
				reverse(s.begin(), s.end());
				for (int i = 0; i < n - s.size(); i++)
					cout<<0;
				cout<<s<<endl;
				break;
    		}
    	}
    }
}