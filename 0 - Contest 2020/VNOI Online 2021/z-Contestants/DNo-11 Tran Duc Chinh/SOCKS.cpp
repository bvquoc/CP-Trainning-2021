#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define int long long
using namespace std;
int n,q,a[500005],u,v,t,sub1;
vector<int> b[500005],c;
signed main()
{
    FastIO;
    freopen("SOCKS.INP","r",stdin);
    freopen("SOCKS.OUT","w",stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        b[u].push_back(v);
        b[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (a[i] == 1)
        c.push_back(i);
    for (int i = 1; i <= n; i++)
    {
        if (b[i].size() > 2)
            sub1 = 1;
    }
    if (!sub1)
    {
        t = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == 1)
            t++;
        if (t > 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        while (q--)
        {
            cin >> u;
            if (a[u] == 0)
                a[u] = 1;
            else
                a[u] = 0;
            t = 0;
            for (int i = 1; i <= n; i++)
            if (a[i] == 1)
            t++;
            if (t > 1)
            cout << 1 << endl;
            else
            cout << 0 << endl;
        }
    }
    else
    {
        t = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == 1)
            t++;
        cout << t/2 << endl;
        while (q--)
        {
            cin >> u;
            if (a[u] == 0)
                a[u] = 1;
            else
                a[u] = 0;
            t = 0;
            for (int i = 1; i <= n; i++)
            if (a[i] == 1)
            t++;
            cout << t/2 << endl;
        }
    }
    return 0;
}
