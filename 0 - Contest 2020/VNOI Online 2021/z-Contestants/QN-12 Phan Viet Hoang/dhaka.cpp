#include <bits/stdc++.h>
#define fi first
#define se second
#define fr(i, x, y) for (int i = x; i <= y; ++i)
#define ft(i, x, y) for (int i = y; i >= x; --i)
#define pii pair <int, int>
#define getbit(x, k) ((x) & (1 << (k)))
#define flip(x, k) ((x) ^ (1 << (k)))
#define ll long long
using namespace std;
int n, m, k, l, dist[1010][1010], country[100010], dd[100010];
vector <int> fruit[100010];
vector <pii> edge[100010];
set <int> s;
ll res = 1e18, d[100010], _d[3][100010];
void inp ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("dhaka.inp", "r", stdin);
    freopen ("dhaka.out", "w", stdout);
    cin >> n >> m >> k >> l;
    fr (i, 1, n)
    {
        int number;
        cin >> number;
        fr (j, 1, number)
        {
            int tc;
            cin >> tc;
            fruit[i].push_back(tc);
        }
    }
    fr (i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
        if (n <= 1000) dist[u][v] = dist[v][u] = w;
    }
}
void sub1 ()
{
    fr (i, 1, n) country[i] = i;
    do
    {
        s.clear();
        fr (i, 1, n) dd[i] = 0;
        ll check = 0;
        fr (i, 1, n)
        {
            int u = country[i];
            int v = country[i + 1];
            dd[u] = 1;
            s.insert(fruit[u].begin(), fruit[u].end());
            if (u == n) break;
            if (dist[u][v] == 0) break;
            check += dist[u][v];
        }
        if (dd[1] == 1 and dd[n] == 1 and s.size() >= l) res = min(res, check);
    } while (next_permutation(country + 1, country + n + 1));
    cout << res;
    exit(0);
}
void dijkstra ()
{
    priority_queue <pair<ll, int>> q;
    fr (i, 1, n) d[i] = 1e18;
    d[1] = 0;
    q.push({0, 1});
    while (!q.empty())
    {
        int u = q.top().se;
        ll du = -q.top().fi;
        q.pop();
        if (du != d[u]) continue;
        for (pii v : edge[u])
        {
            if (d[v.fi] > d[u] + v.se)
            {
                d[v.fi] = d[u] + v.se;
                q.push({-d[v.fi], v.fi});
            }
        }
    }
}
void sub2 ()
{
    dijkstra ();
    cout << d[n];
    exit(0);
}
void dijkstra_sub3 (int st, int mode)
{
    priority_queue <pair<ll, int>> q;
    fr (i, 1, n) _d[mode][i] = 1e18;
    _d[mode][st] = 0;
    q.push({0, st});
    while (!q.empty())
    {
        int u = q.top().se;
        ll du = -q.top().fi;
        q.pop();
        if (du != _d[mode][u]) continue;
        for (pii v : edge[u])
        {
            if (mode == 2 and v.fi == 1) continue;
            if (_d[mode][v.fi] > _d[mode][u] + v.se)
            {
                _d[mode][v.fi] = _d[mode][u] + v.se;
                q.push({-_d[mode][v.fi], v.fi});
            }
        }
    }
}
void sub3 ()
{
    dijkstra_sub3(1, 1);
    dijkstra_sub3(n, 2);
    fr (i, 1, n) if (fruit[i].size() >= l)
    {
        res = min(_d[1][i] + _d[2][i], res);
    }
    if (fruit[1].size() >= l or fruit[n].size() >= l) res = min(res, _d[1][n]);
    cout << res;
    exit(0);
}
int main ()
{
    inp();
    if (n <= 10) sub1();
    if (l == 0) sub2();
    sub3();
    return 0;
}




