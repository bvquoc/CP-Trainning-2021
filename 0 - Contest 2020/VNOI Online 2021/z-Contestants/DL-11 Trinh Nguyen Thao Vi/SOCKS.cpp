#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair <long, long>
#define NAME "SOCKS"

using namespace std;

const long N = 5e5 + 5, oo = 1e9, mod = 1e9 + 7;

long n, Q, b[N], u, v, t, cnt, spec, ok[N];
vector <long> a[N], save, luu[N];

void sub1 ()
{
    long cnt = 0, res = 0;
    for (long i = 1; i <= n; ++i) cnt += b[i];
    if (cnt >= 2) cout << 1 << '\n';
    else cout << 0 << '\n';
    while (Q--)
    {
        cin >> t;
        cnt += (b[t] == 0);
        b[t] = 1;
        if (cnt >= 2) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}

void dfs1 (long u, long p)
{
    ok[u] = cnt;
    for (long v : a[u])
    {
        if (v != p)
        {
            if (u == spec) ++cnt;
            dfs1 (v, u);
        }
    }
}

void sub2 ()
{
    long v[4] = { };
    cnt = 0;
    memset (ok, 0, sizeof (ok));
    for (long i = 1; i <= n; ++i) if (a[i].size() == 3) spec = i;
    dfs1 (spec, spec);
    for (long i = 1; i <= n; ++i) if (b[i]) ++v[ok[i]];
    cnt = (v[1] > 0) + (v[2] > 0) + (v[3] > 0);
    cout << cnt - 1 << '\n';

    while (Q--)
    {
        cin >> t;
        if (b[t] == 0)
        {
            ++v[ok[t]];
            b[t] = 1;
        }
        cnt = (v[1] > 0) + (v[2] > 0) + (v[3] > 0);
        cout << cnt - 1 << '\n';
    }
}

/**
void dfs (long u, long p)
{
    luu[u].push_back (++cnt);
    save.push_back (u);
    for (long v : a[u])
    {
        if (v != p)
        {
            dfs (v, u);
            save.push_back (u);
            luu[u].push_back (++cnt);
        }
    }
}

void sub3 ()
{
    cnt = -1;
    dfs (1, -1);
    for (long i : save) cout << i << ' ';
}**/

int main()
{
    freopen (NAME".INP", "r", stdin);
    freopen (NAME".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cin >> n >> Q;
    for (long i = 1; i <= n; ++i) cin >> b[i];
    bool _sub1 = 1;
    long _sub2 = 0;
    for (long i = 1; i < n; ++i)
    {
        cin >> u >> v;
        a[u].push_back (v);
        a[v].push_back (u);
        if (a[u].size() > 2 || a[v].size() > 2) _sub1 = 0;
        _sub2 += (a[u].size() == 3);
        _sub2 += (a[v].size() == 3);
    }
    if (_sub1) sub1 ();
    else if (_sub2 == 1) sub2 ();

    return 0;
}
