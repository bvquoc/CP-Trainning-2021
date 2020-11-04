#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f;

template<typename T> void maximize(T &res, T val) { if (res < val) res = val; }
template<typename T> void minimize(T &res, T val) { if (res > val) res = val; }

int n, m, p, l, k;
vector<vector<pi> > G;

void dijkstra(vector<ll> &d, int s)
{
    d.assign(n + 1, +LINF);
    d[s] = 0;

    priority_queue<pli, vector<pli>, greater<pli> > pq;
    pq.push(make_pair(d[s], s));

    while (pq.size())
    {
        ll du = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (du != d[u]) continue;
        for (const pi &e : G[u])
        {
            int v = e.first;
            int w = e.second;

            if (d[v] > du + w)
            {
                d[v] = du + w;
                pq.push(make_pair(d[v], v));
            }
        }
    }
}

vector<vector<ll> > d;
int main()
{
    cin >> n >> m >> p >> l >> k;

    G.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;

        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    vector<ll> dist;
    dijkstra(dist, 1);
    cout << dist[n];
    return 0;

    d.resize(n + 1);
    for (int u = 1; u <= n; ++u)
        dijkstra(d[u], u);

    return 0;
}