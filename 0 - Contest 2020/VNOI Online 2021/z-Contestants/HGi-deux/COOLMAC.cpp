#include <bits/stdc++.h>
#define int long long
#define X first
#define Y second
using namespace std;

vector < pair <int, int> > v;

main()
{
    freopen("COOLMAC.inp", "r", stdin);
    //freopen("COOLMAC.out", "w", stdout);
    int m, n, ans = -1, d = 1;
    cin >> m;
    int l[m+1], r[m+1];
    for(int i = 0; i < m; ++i)
    {
        cin >> l[i] >> r[i];
        v.push_back(make_pair(r[i], l[i]));
    }
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    sort(v.rbegin(), v.rend());
    if(v[0].X != 100000)
    {
        cout << -1;
        return 0;
    }
    int kt = 0;
    int t = a[0], mi = v[0].Y, idx = 0;
    for(int i = 1; i < m; ++i)
    {
        if(v[i].X == v[i-1].X)
        {
            mi = v[i].Y;
            idx = i;
            continue;
        }else if(v[i].X < v[idx].X)
        {
            if(v[i].X < mi)
            {
                mi = v[idx].Y;
                kt = 0;
            }
            else if(v[i].X < v[idx].Y)
                continue;
            else if(v[i].Y >= v[idx].Y)
                continue;
            if(v[i].X >= mi && v[i].Y < mi)
            {
                idx = i;
                int x, y;
                x = min(mi, v[i].X);
                y = min(mi, v[i].Y);
                if(x == mi && y != mi)
                {
                    if(kt == 0)
                    {
                        d++;
                        kt = 1;
                    }
                    else if(kt == 1)
                        idx = i;
                }
                if(v[i].Y <= t)
                    break;
            }
        }
    }
    if(d != 1)
        ans = d;
    cout << ans;
}
