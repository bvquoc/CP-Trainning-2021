#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define int long long
using namespace std;
const int MOD = 998244353;
int T,n,chan,le,sc,sl,t,tong;
string a,s;
signed main()
{
    FastIO;
    freopen("GIFT11.INP","r",stdin);
    freopen("GIFT11.OUT","w",stdout);
    cin >> T;
    while (T--)
    {
        cin >> n;
        s = "";
        chan = 0;
        le = 0;
        for (int i = 1; i <= n; i++)
            {
                cin >> a;
                if (a.size() % 2 == 0)
                    chan++;
                else le++;
                s = s + a;
            }
        for (int i = 0 ; i < s.size(); i++)
        {
            if (i % 2 == 0)
                sl += (s[i] - '0');
            else
                sc += (s[i] - '0');
        }
        tong = 0;
        if ((sl - sc) % 11 == 0)
        {
            if (chan > 1)
            {t = 1;
            for (int i = 1; i <= chan; i++)
                t = (t * i) % MOD;
            tong = (tong + t) % MOD;
            }
            if (le > 1)
            {
            t = 1;
            for (int i = 1; i <= le; i++)
                t = (t * i) % MOD;
            tong = (tong + t) % MOD;
            }
            cout << tong << endl;
        }
        else cout << 0 << endl;
    }
    return 0;
}
