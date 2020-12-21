#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair <long, long>
#define NAME "COOLMAC"

using namespace std;

const long N = 1e5 + 5, M = 1e6 + 5, oo = 1e9, mod = 1e9 + 7;

long n, m, t, save, ok[N], vi;
ii a[N], ST[M];

void sub1 ()
{
    long res = oo;
    for (long i = 1L; i < (1L << m); ++i)
    {
        long st = -1, fin = -1;
        for (long j = 0; j < m; ++j)
        {
            if ((i >> j) & 1L)
            {
                if (fin == -1)
                {
                    st = a[j + 1].fi;
                    fin = a[j + 1].se;
                }
                else
                {
                    if (a[j + 1].fi <= fin && a[j + 1].se > fin) fin = a[j + 1].se;
                    else {st = fin = -1; break;}
                }
            }
        }
        long cnt = __builtin_popcount (i);
        if (st <= save && fin == 1e5) res = min (res, cnt);
    }
    if (res == oo) res = -1;
    cout << res;
}

void sub2 ()
{
    memset (ok, 0, sizeof (ok));
    for (long i = 1; i <= m; ++i)
    {
        if (a[i].fi <= save)
        {
            ok[i] = 0;
            long tmp = -oo, pos = 0;
            for (long j = i + 1; j <= m; ++j)
            {
                if (a[j].fi > a[i].se) break;
                if (a[j].se > tmp) tmp = a[j].se, pos = j;
            }
            if (!pos) continue;
            if (!ok[pos]) ok[pos] = ok[i] + 1;
            else ok[pos] = min (ok[pos], ok[i] + 1);
        }
        else if (ok[i])
        {
            long tmp = -oo, pos = 0;
            for (long j = i + 1; j <= m; ++j)
            {
                if (a[j].fi > a[i].se) break;
                if (a[j].se > tmp) tmp = a[j].se, pos = j;
            }
            if (!pos) continue;
            if (!ok[pos]) ok[pos] = ok[i] + 1;
            else ok[pos] = min (ok[pos], ok[i] + 1);
        }
    }
    long res = oo;
    for (long i = 1; i <= m; ++i)
    {
        if (a[i].se == 1e5)
        {
            if (!ok[i] && a[i].fi <= save) res = min (ok[i] + 1, res);
            else if (ok[i]) res = min (ok[i] + 1, res);
        }
    }
    if (res == oo) res = -1;
    cout << res;
}

void build (long id, long l, long r)
{
    if (l == r)
    {
        ST[id] = {a[l].se, l};
        return;
    }
    long mid = (l + r) / 2;
    build (id * 2, l, mid);
    build (id * 2 + 1, mid + 1, r);
    if (ST[id * 2].fi < ST[id * 2 + 1].fi) ST[id] = ST[id * 2];
    else ST[id] = ST[id * 2 + 1];
}

ii get (long id, long l, long r, long u, long v)
{
    if (v < l || u > r) return {oo, oo};
    if (u <= l && r <= v) return ST[id];
    long mid = (l + r) / 2;
    ii g1 = get (id * 2, l, mid, u, v);
    ii g2 = get (id * 2 + 1, mid + 1, r, u, v);
    if (g1.fi < g2.fi) return g1;
    else return g2;
}

void bina (long x, long L, long R)
{
    long mid, l = L, r = R;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid].fi <= x)
        {
            vi = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return;
}

void sub3 ()
{
    build (1, 1, m);
    memset (ok, 0, sizeof (ok));
    for (long i = 1; i <= m; ++i)
    {
        if (a[i].fi <= save)
        {
            ok[i] = 0;
            vi = 0;
            bina (a[i].se, i + 1, m);
            long j = vi;
            if (j > i && a[j].fi <= a[i].se)
            {
                ii k = get (1, 1, m, i + 1, j);
                if (!ok[k.se]) ok[k.se] = ok[i] + 1;
                else ok[k.se] = min (ok[k.se], ok[i] + 1);
            }
        }
        else if (ok[i])
        {
            vi = 0;
            bina (a[i].se, i + 1, m);
            long j = vi;
            if (j > i && a[j].fi <= a[i].se)
            {
                ii k = get (1, 1, m, i + 1, j);
                if (!ok[k.se]) ok[k.se] = ok[i] + 1;
                else ok[k.se] = min (ok[k.se], ok[i] + 1);
            }
        }
    }
    long res = oo;
    for (long i = 1; i <= m; ++i)
    {
        if (a[i].se == 1e5)
        {
            if (!ok[i] && a[i].fi <= save) res = min (ok[i] + 1, res);
            else if (ok[i]) res = min (ok[i] + 1, res);
        }
    }
    if (res == oo) res = -1;
    cout << res;
}

int main()
{
    freopen (NAME".INP", "r", stdin);
    freopen (NAME".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cin >> m;
    for (long i = 1; i <= m; ++i) cin >> a[i].fi >> a[i].se;
    cin >> n;
    save = N;
    for (long i = 1; i <= n; ++i)
    {
        cin >> t;
        save = min (save, t);
    }
    sort (a + 1, a + m + 1);
    if (n <= 10 && m <= 16) sub1 ();
    else if (n <= 3e3 && m <= 3e3) sub2 ();
    else sub3 ();

    return 0;
}
