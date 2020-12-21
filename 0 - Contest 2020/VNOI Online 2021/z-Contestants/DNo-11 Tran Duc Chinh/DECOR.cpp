#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define int long long
using namespace std;
int n,m,k,a[500005],b[500005],q,u,v,maxz;
string s;
signed main()
{
    FastIO;
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    cin >> n >> m >> k;
    cin >> s;
    for (int i = 1; i <= m; i++)
        cin >> a[i] >> b[i];
    if (m == 0 && k == 0)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                q++;
            else
            {
                if (maxz < q)
                    {
                        maxz = q;
                        u = i - maxz + 1;
                        v = i;
                    }
                q = 0;
            }
        }
        cout << u << " " << v;
        return 0;
    }
    q = 0;
    maxz = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                q++;
            else
            {
                if (maxz < q)
                    {
                        maxz = q;
                        u = i - maxz + 1;
                        v = i;
                    }
                q = 0;
            }
        }
        if (u - 1 <= k)
        {
            k = k - (u-1);
            u = 1;
            v = min(v + k,n);
        }
        else
            u = u-k;
        cout << u << " " << v;
    return 0;
}
