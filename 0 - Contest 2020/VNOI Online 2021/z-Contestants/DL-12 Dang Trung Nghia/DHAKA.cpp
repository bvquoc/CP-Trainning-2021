#include<bits/stdc++.h>
using namespace std;

typedef pair<long, long> ii;

struct Ore
{
    long long u, mask, du;
    bool operator < (Ore other) const
    {
        return du > other.du;
    }
};

long n, m, K, L, c[100005];
long long d[100005][45];
vector<ii> g[100005];
priority_queue<Ore, vector<Ore> > pq;

void dik()
{
    for (long i = 1; i <= n; i++) for (long mask = 0; mask < (1 << K); mask++) d[i][mask] = 1e15;
    d[1][c[1]] = 0;
    pq.push({1, c[1], 0});
    while (!pq.empty())
    {
        long u = pq.top().u;
        long mask = pq.top().mask;
        long long du = pq.top().du;
        pq.pop();
        if (d[u][mask] != du) continue;
        for (long i = 0; i < g[u].size(); i++)
        {
            long v = g[u][i].first;
            long nMask = mask | c[v];
            if (d[v][nMask] > d[u][mask] + g[u][i].second)
            {
                d[v][nMask] = d[u][mask] + g[u][i].second;
                pq.push({v, nMask, d[v][nMask]});
            }
        }
    }
    long long res = 1e15;
    for (long mask = 0; mask < (1 << K); mask++)
    {
        if (__builtin_popcount(mask) >= L) res = min(res, d[n][mask]);
    }
    if (res == 1e15) res = -1;
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("DHAKA.INP", "r", stdin);
    freopen("DHAKA.OUT", "w", stdout);
    cin >> n >> m >> K >> L;
    for (long i = 1; i <= n; i++)
    {
        long sz, x;
        cin >> sz;
        while (sz--)
        {
            cin >> x;
            x--;
            c[i] |= (1 << x);
        }
    }
    for (long i = 1; i <= m; i++)
    {
        long u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(ii(v, w));
        g[v].push_back(ii(u, w));
    }
    dik();
    return 0;
}
