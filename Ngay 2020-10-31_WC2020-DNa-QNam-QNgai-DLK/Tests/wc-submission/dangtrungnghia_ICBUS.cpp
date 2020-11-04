#include<bits/stdc++.h>
using namespace std;

typedef pair<long, long> ii;

struct Backoi
{
    long c, d;
} a[5005];

struct ore
{
    long du, u, k;
    bool operator < (ore other) const
    {
        return du > other.du;
    }
};
long n, m, visit[5005], timed = 0, d[5005], f[5005][5005];
ii trace[5005][5005];
vector<long> c[5005];
priority_queue<ore, vector<ore> > pq;


void dik()
{
    for (long i = 1; i <= n; i++) fill(f[i], f[i] + n + 1, 2e9);

    f[1][a[1].d] = a[1].c;
    pq.push({f[1][a[1].d], 1, a[1].d});
    while (!pq.empty())
    {
        long u = pq.top().u;
        long k = pq.top().k;
        long du = pq.top().du;
        pq.pop();
        if (du != f[u][k]) continue;

        if (f[u][a[u].d] > f[u][k] + a[u].c)
        {
            f[u][a[u].d] = f[u][k] + a[u].c;
            pq.push({f[u][a[u].d], u, a[u].d});
        }
        if (k == 0) continue;
        for (long v: c[u])
        {
            if (f[v][k - 1] > f[u][k])
            {
                //trace[v][k - 1] = ii(u, k);
                f[v][k - 1] = f[u][k];
                pq.push({f[v][k - 1], v, k - 1});
            }
        }
    }
//    for (long i = 1; i <= n; i++)
//    {
//        cout << i << " :   " << '\n';
//        for (long j = 1; j <= n; j++)
//        {
//            cout << f[i][j] << " -- " << trace[i][j].first << ' ' << trace[i][j].second << '\n';
//        }
//        cout << '\n';
//    }
    long res = 2e9;
    for (long i = 0; i <= n; i++) res = min(res, f[n][i]);
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> n >> m;
    for (long i = 1; i <= n; i++) cin >> a[i].c >> a[i].d;
    for (long i = 1; i <= m; i++)
    {
        long u, v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    dik();
    return 0;
}
