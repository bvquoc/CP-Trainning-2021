#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

long long d[MAXN][64];
int s[MAXN], n, m, k, l;
vector <pair <int, int> > adj[MAXN];

int turnOn(int v, int p)
{
    return (1 << p) | v;
}

int main()
{
    if (fopen("tst.inp", "r"))
    {
        freopen("tst.inp", "r", stdin);
        freopen("tst.out", "w", stdout);
    }
    else
    {
        freopen("DHAKA.INP", "r", stdin);
        freopen("DHAKA.OUT", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k >> l;
    for (int i = 1, x, y; i <= n; ++i)
    {
        cin >> x;
        while (x--)
        {
            cin >> y;
            s[i] = turnOn(s[i], y - 1);
        }
    }

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int mx = 1 << k;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < mx; ++j)
            d[i][j] = LLONG_MAX;

    set <pair <long long, pair <int, int> > > S;
    d[1][s[1]] = 0;
    S.insert({0, {1, s[1]}});
    while (S.size())
    {
        auto p = *S.begin(); S.erase(S.begin());
        int u = p.second.first, tt = p.second.second;
        if (p.first > d[u][tt]) continue;

        for (auto x: adj[u])
        {
            int v = x.first, w = x.second, tt1 = tt | s[v];
            if (d[v][tt1] > p.first + 1LL * w)
            {
                d[v][tt1] = p.first + 1LL * w;
                S.insert({d[v][tt1], {v, tt1}});
            }
        }
    }

    long long ans = LLONG_MAX;
    for (int i = 0; i < mx; ++i)
        if (__builtin_popcount(i) >= l)
            ans = min(ans, d[n][i]);

    cout << (ans == LLONG_MAX ? - 1 : ans);
    return 0;
}
