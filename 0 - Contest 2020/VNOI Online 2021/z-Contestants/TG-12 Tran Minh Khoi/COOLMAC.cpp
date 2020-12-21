#include <bits/stdc++.h>
#define fi "COOLMAC.inp"
#define fo "COOLMAC.out"
#define ii pair<int, int>
#define X first
#define Y second
#define MAX 100000

using namespace std;

int m, n, low;
ii a[100011];

bool cmp(const ii x, const ii y)
{
    return (x.X < y.X) || ((x.X == y.X) && (x.Y > y.Y));
}

void INP()
{
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].X >> a[i].Y;
    cin >> n;
    sort(a + 1, a + m + 1, cmp);
    low = 1e5+11;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        low = min(low, t);
    }
}

void Solve()
{
    int r1 = -1, r2 = low, res = 0;
    for (int i = 1; i <= m; i++)
    {
        int ln = a[i].X, rn = a[i].Y;
        if (rn <= r2) continue;
        if (ln > r2)
        {
            cout << -1;
            return;
        }
        if (r1 < ln)
        {
            res++;
            r1 = r2;
            r2 = rn;
        } else
        {
            r2 = rn;
        }
        if (r2 >= MAX) break;
    }
    if (r2 < MAX) cout << -1; else
    cout << res;
}

int main()
{
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
    INP();
    Solve();
    return 0;
}
