/*

*/


#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long int
#define sz(a) (int)a.size()
#define ff first
#define ss second
#define inf 1e18
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define mod 1000000007
#define pi pair<int, int>
#define ti tuple<int, int, int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define set_bits(x) __builtin_popcountll(x)
#define deb(x) cout << "[" << #x << " = " << x << "]"
#define deb2(x, y) cout << "[" << #x << " = " << x << "  " << #y << " = " << y << "]"
#define output_vector(a) for(auto x : a) cout << x << " "
#define output_vector2(a) for(auto i : a) { for(auto j : i) cout << j << " "; cout << "\n"; }

void solve() {
	string s;
	cin >> s;
	
	int n = sz(s);
	
	pi g = {0, 0}, c = {0, 0}, a = {0, 0}, t = {0, 0};
	
	int k = 0;
	string ans;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'G') g.ff++, g.ss = i;
		else if(s[i] == 'C') c.ff++, c.ss = i;
		else if(s[i] == 'A') a.ff++, a.ss = i;
		else if(s[i] == 'T') t.ff++, t.ss = i;
		if(g.ff && c.ff && a.ff && t.ff) {
			k++;
//			deb(i);
			int j = max({g.ss, c.ss, a.ss, t.ss});
			ans += s[j]; 
			g = c = a = t = {0, 0};
		}
	}
	
	
	if(a.ff == 0) ans += "A";
	else if(c.ff == 0) ans += "C";
	else if(g.ff == 0) ans += "G";
	else if(t.ff == 0) ans += "T";
	else ans += "A";
	cout << ans << "\n";
}

int32_t main() {

	fastio;

	int test_cases = 1;
//	cin >> test_cases;

	while(test_cases--) {
	   solve();
	}
	
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n ";

	return 0;
}

