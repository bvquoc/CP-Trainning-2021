#include <bits/stdc++.h>

#define TASK "DHAKA"

using namespace std;

const int maxn = 1e5 + 5;

int n, m, k, l, c[maxn];
vector <pair <int, int> > a[maxn];

namespace Sub1
{
    long long d[1005][1005], res = 1e18 + 69;
    bool mk[maxn];
    vector <int> cur;

    void Dijkstra(int S)
    {
        priority_queue <pair <long long, int> > Q;
        d[S][S] = 0;
        Q.push({0, S});
        while (!Q.empty())
        {
            long long l = -Q.top().first;
            int u = Q.top().second;
            Q.pop();
            if (l > d[S][u]) continue;
            for (auto p : a[u])
            {
                int v = p.first;
                int w = p.second;
                if (d[S][v] > d[S][u] + w)
                {
                    d[S][v] = d[S][u] + w;
                    Q.push({-d[S][v], v});
                }
            }
        }
    }

    void Solve()
    {
        int state = 0;
        long long dist = 0;
        for (int i = 0; i < cur.size(); i ++)
        {
            state |= c[cur[i]];
            if (i != 0)
            {
                if (d[cur[i - 1]][cur[i]] >= 1e18) return;
                dist += d[cur[i - 1]][cur[i]];
            }
        }
        if (__builtin_popcount(state) >= l)
            res = min(res, dist);
    }

    void Arrg(int pos, int val)
    {
        mk[val] = 1;
        cur.push_back(val);
        if (val == n) Solve();
        if (pos < n)
        {
            for (int i = 1; i <= n; i ++)
                if (!mk[i]) Arrg(pos + 1, i);
        }
        mk[val] = 0;
        cur.pop_back();
    }

    void Main()
    {
        for (int i = 1; i <= n; i ++)
            fill(d[i] + 1, d[i] + n + 1, 1e18 + 69);
        for (int i = 1; i <= n; i ++)
            Dijkstra(i);
        Arrg(1, 1);
        cout << (res < 1e18 ? res : -1) << "\n";
    }
}

namespace Sub5
{
    long long d[45][maxn];

    void Dijkstra(int t)
    {
        priority_queue <pair <long long, int> > Q;
        for (int i = 1; i <= n; i ++)
            if (d[t][i] < 1e18) Q.push({-d[t][i], i});
        while (!Q.empty())
        {
            long long l = -Q.top().first;
            int u = Q.top().second;
            Q.pop();
            if (l > d[t][u]) continue;
            for (auto p : a[u])
            {
                int v = p.first;
                int w = p.second;
                if (d[t | c[v]][v] > d[t][u] + w)
                {
                    d[t | c[v]][v] = d[t][u] + w;
                    if ((t | c[v]) == t) Q.push({-d[t][v], v});
                }
            }
        }

    }

    void Main()
    {
        for (int i = 0; i <= 32; i ++)
            fill(d[i] + 1, d[i] + n + 1, 1e18 + 69);
        d[c[1]][1] = 0;
        for (int i = 0; i < (1 << k); i ++)
            Dijkstra(i);

        long long res = 1e18 + 69;
        for (int i = 0; i < (1 << k); i ++)
        {
            int cnt = __builtin_popcount(i);
            if (cnt >= l)
                res = min(res, d[i][n]);
        }
        cout << (res >= 1e18 + 69 ? -1 : res) << "\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen(TASK".inp", "r", stdin);
	freopen(TASK".out", "w", stdout);

	cin >> n >> m >> k >> l;
	for (int cnt, i = 1; i <= n; i ++)
    {
        cin >> cnt;
        for (int x, j = 1; j <= cnt; j ++)
        {
            cin >> x;
            c[i] |= (1 << (x - 1));
        }
    }
	for (int u, v, w, i = 1; i <= m; i ++)
    {
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
//    if (n <= 10) Sub1::Main();
    Sub5::Main();

	return 0;
}
