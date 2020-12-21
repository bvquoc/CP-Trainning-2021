#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair <ll, long>
#define iii pair <ll, pair <long, long> >
#define NAME "DHAKA"

using namespace std;

const long N = 1e5 + 5;
const ll oo = 1e18, mod = 1e9 + 7;

long n, m, K, L, u, v, s[N];
vector <iii> a[N];
ll w, d[N][35];

void sub1 ()
{
    long u, v, msku, mskv;
    ll du, uv;
    priority_queue <iii, vector <iii>, greater <iii>> pq;
    for (long i = 1; i <= n; ++i)
        for (long j = 0; j <= 32; ++j)
            d[i][j] = oo;
    d[1][0] = 0;
    pq.push ({0, {1, 0}});
    while (pq.size())
    {
        u = pq.top().se.fi, du = pq.top().fi, msku = pq.top().se.se;
        pq.pop();
        if (du != d[u][msku]) continue;
        for (iii tmp : a[u])
        {
            v = tmp.se.fi, uv = tmp.fi, mskv = tmp.se.se;
            if (d[v][mskv | msku] > du + uv)
            {
                d[v][mskv | msku] = du + uv;
                pq.push ({d[v][mskv | msku], {v, msku | mskv}});
            }
        }
    }
    ll res = oo;
    for (long i = 0; i <= 32; ++i)
    {
        if (__builtin_popcount (i) >= L)
            res = min (res, d[n][i]);
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
    cin >> n >> m >> K >> L;
    for (long i = 1; i <= n; ++i)
    {
        s[i] = 0;
        long t, A;
        cin >> t;
        while (t--)
        {
            cin >> A;
            s[i] |= (1 << (A - 1));
        }
    }
    for (long i = 1; i <= m; ++i)
    {
        cin >> u >> v >> w;
        long t = (s[u] | s[v]);
        a[u].push_back ({w, {v, t}});
        a[v].push_back ({w, {u, t}});
    }
    sub1 ();
    return 0;
}
