/*
Problem Name: String Reorder
Problem Link: https://cses.fi/problemset/task/1743
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
    
    string s; cin>>s;
    int n = s.size();
    sort(s.begin(), s.end());
    set<int> str;
    int fq[27] = {0};
    for (auto i: s) {
        fq[i-'A']++;
        str.insert(i);
    }

    auto it = max_element(fq, fq+27);
    if (2**it - n > 1) return cout<<-1, 0;

    string ans;
    char prev = 26+'A';
    while(2**it - n < 1) {
        char x = *str.begin();
        str.erase(x);
        ans += x; fq[x-'A']--;
        if (fq[prev-'A'])
            str.insert(prev);
        prev = x;
        it = max_element(fq, fq+27);
        n--;
    }
    if (*it) {
        string aux; char x = it-fq+'A';
        for (int i = 0; i < 26; i++) if (x-'A' != i)
            for (int j = 0; j < fq[i]; j++) 
                aux += i+'A';
        ans += x;
        for (auto i: aux)
            ans += i, ans += x;
    }
    cout<<ans;
}