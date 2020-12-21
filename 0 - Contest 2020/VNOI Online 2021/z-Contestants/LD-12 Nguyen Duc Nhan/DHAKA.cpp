#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
const int maxN = 1e5;
int n, m, k, l;
int c[maxN + 5];
vector <ii> a[maxN + 5];
int d1[maxN + 5];
void dijkstra()
{
    priority_queue <ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i++)
        d1[i] = 1e18;
    d1[1] = 0;
    pq.push({0, 1});
    while (pq.size())
    {
        int u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();
        if (du != d1[u])
            continue;
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].fi;
            int uv = a[u][i].se;
            if (d1[v] > du + uv)
            {
                d1[v] = du + uv;
                pq.push({d1[v], v});
            }
        }
    }
}
int d2[maxN + 5][3];
void dijkstra2()
{
    priority_queue <iii, vector<iii>, greater<iii>> pq;

    for (int i = 1; i <= n; i++)
        d2[i][0] = d2[i][1] = 1e18;
    d2[1][c[1]] = 0;
    pq.push({{0,1},c[1]});
    while (pq.size())
    {
        int u = pq.top().fi.se;
        int du = pq.top().fi.fi;
        int color = pq.top().se;
        pq.pop();
        if (du != d2[u][color])
            continue;
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].fi;
            int uv = a[u][i].se;
            int ncolor = color | c[v];
            if (d2[v][ncolor] > du + uv)
            {
                d2[v][ncolor] = du + uv;
                pq.push({{d2[v][ncolor], v}, color | c[v]});
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DHAKA.INP", "r", stdin);
    freopen("DHAKA.OUT", "w", stdout);
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; i++)
    {
        int val = 0, cnt;
        cin >> cnt;
        while (cnt--)
        {
            int x;
            cin >> x;
            val |= (1 << (x - 1));
        }
        c[i] = val;
    }
    while (m--)
    {
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back({y,w});
        a[y].push_back({x,w});
    }
    if (l == 0)
    {
        dijkstra();
        if (d1[n] == 1e18) cout << -1;
        else cout << d1[n];
        return 0;
    }
    if (k == 1)
    {
        dijkstra2();
        if (d2[n][1] == 1e18) cout << -1;
        else cout << d2[n][1];
        return 0;
    }
    cout << -1;
    return 0;
}
