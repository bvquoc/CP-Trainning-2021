#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair <int, int>
#define NAME "TEST"

using namespace std;

const int N = 1e5 + 5, oo = 1e9, mod = 1e9 + 7;

int n, m, P, L, K, x, y, t, d[N];
vector <ii > a[N];

void dijkstra()
{
    int u, v, du, uv;
    priority_queue <ii, vector <ii >, greater <ii> > pq;
    for (int i = 1; i <= n; ++i) d[i] = oo;
    d[1] = 0;
    pq.push({0, 1});
    while (pq.size())
    {
        u = pq.top().se;
        du = pq.top().fi;
        pq.pop();
        if (du != d[u]) continue;
        for (int i = 0; i < a[u].size(); ++i)
        {
            v = a[u][i].se;
            uv = a[u][i].fi;
            if (d[v] > du + uv)
            {
                d[v] = du + uv;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
//    freopen (NAME".INP", "r", stdin);
//    freopen (NAME".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> P >> L >> K;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y >> t;
        a[x].push_back({t, y});
        a[y].push_back({t, x});
    }
    dijkstra();
    cout << d[n];

    return 0;
}
