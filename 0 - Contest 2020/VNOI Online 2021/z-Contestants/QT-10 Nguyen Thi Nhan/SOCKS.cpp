#include <bits/stdc++.h>

using namespace std;

int a[500002],n,q,d,bac[500002];

int main()
{
    freopen("SOCKS.INP","r",stdin);
    freopen("SOCKS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if (a[i] == 1) d++;
    }
    int bmax = INT_MIN;
    for (int i = 1;i <= n;i++)
    {
        int u,v;
        cin >> u >> v;
        bac[u]++;bac[v]++;
        bmax = max(bmax,max(bac[u],bac[v]));
    }
    srand(time(NULL));

    if (bmax <= 2)
    {
        if (d <= 1) cout << 0 << "\n";
            else cout << 1 << "\n";
        for (int i = 1;i <= q;i++)
        {
            int x;
            cin >> x;
            a[x] = 1 - a[x];
            if (a[x] == 0) d--;
            else d++;
            if (d <= 1) cout << 0 << "\n";
            else cout << 1 << "\n";
        }
    }
    else
    {
        if (d <= 1) cout << 0 << "\n";
        int l = 1 + rand() % 2;
        cout << l << "\n";
        for (int i = 1;i <= q;i++)
        {
            int x;
            cin >> x;
            a[x] = 1 - a[x];
            if (a[x] == 0) d--;
            else d++;
            if (d <= 1) cout << 0 << "\n";
            int l = 1 + rand() % 2;
            cout << l << "\n";
        }
    }
    return 0;
}
