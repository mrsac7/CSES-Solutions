#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
class RollHash{
public:
    int fenwick[200005];
    int N;
    RollHash(int n)
    {
        N = n;
        memset(fenwick,0,sizeof fenwick);
    }
    void update(int index,int x)
    {
       for(int i=index;i<=N;i+=(i&-i))
       {
          fenwick[i]+=x;
          fenwick[i]%=mod;
       }
    }
    int sum(int index)
    {
       int ans = 0;
       for(int i=index;i>0;i-=(i&-i))
       {
          ans+=fenwick[i];
          ans%=mod;
       }
       return ans;
    }
    int power(int x, int y)
    {
        int res = 1; 
     
        x = x % mod; 
     
        while (y > 0) 
        {
         
            if (y & 1)
                res = (res * x) % mod;
     
            y = y >> 1; 
            x = (x * x) % mod;
        }
        return res;
    }
    int get(int l,int r)
    {
        // Modulo Inverse - Fermat Theorem
        return ((sum(r) - sum(l-1) + mod)*power(power(131,l-1),mod-2))%mod;
    }
};
signed main()
{
    
    #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
    #endif
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;

    RollHash normal(n),rev(n);

    string r = s;
    reverse(r.begin(),r.end());
    int x = 131;

    for(int i=0;i<n;i++)
    {
        normal.update(i+1,x*(s[i]-'a'+1));
        rev.update(i+1,x*(r[i]-'a'+1));
        x *=131;
        x%=mod;
    }

    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int pos;
            char ch;
            cin >> pos >> ch;
            int p = normal.power(131,pos);
            normal.update(pos,-p*(s[pos-1]-'a'+1));
            s[pos-1] = ch;
            normal.update(pos,p*(s[pos-1]-'a'+1));

            int reversepos = n - pos + 1;
            p = normal.power(131,reversepos);
            rev.update(reversepos,-p*(r[reversepos-1]-'a'+1));
            r[reversepos-1] = ch;
            rev.update(reversepos,p*(r[reversepos-1]-'a'+1));
        }
        else
        {
            int l,r;
            cin >> l >> r;
            int rl,rr;
            rl = n - l + 1;
            rr = n - r + 1;
            if(rl > rr)swap(rl,rr);

            if(normal.get(l,r) == rev.get(rl,rr))cout << "YES\n";
            else
                cout << "NO\n";
            
        }
    }
    return 0;
}