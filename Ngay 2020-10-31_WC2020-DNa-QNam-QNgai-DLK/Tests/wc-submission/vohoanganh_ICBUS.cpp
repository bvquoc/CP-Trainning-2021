#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

template<typename T> void maximize(T &res, T val) { if (res < val) res = val; }
template<typename T> void minimize(T &res, T val) { if (res > val) res = val; }

int n, m;
vector<int> c, d;
vector<vector<int> > G;
vector<vector<int> > T;

int readGraph()
{
    cin >> n >> m;
    
    c.assign(n + 1, 0);
    d.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> c[i] >> d[i];

    G.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    return 0;
}

struct dij_t {
    ll w;
    int v, k;
    dij_t (ll w = 0, int v = 0, int k = 0)
    : w(w), v(v), k(k) {}

    bool operator < (const dij_t &o) const {
        return w > o.w;
    }
};

ll dijkstra(int s, int t)
{
    vector<vector<int> > f(n + 1, vector<int>(n + 1, +INF));
    f[s][d[s]] = c[s];

    priority_queue<dij_t> pq;
    pq.push(dij_t(c[s], s, d[s]));
    while (pq.size())
    {
        ll du = pq.top().w;
        int u = pq.top().v;
        int k = pq.top().k;
        pq.pop();
        
        if (du != f[u][k]) continue;

        if (f[u][d[u]] > du + c[u])
        {
            // cout << u << " -> " << u << " (" << k << ") = ";
            // cout << f[u][d[u]] << ' ' << du << " + " << c[u] << endl;
            f[u][d[u]] = du + c[u];
            pq.push(dij_t(f[u][d[u]], u, d[u]));
        }
        if (k == 0) continue;
        for (int v : G[u])
        {
            if (f[v][k - 1] > du + 0)
            {
                // cout << "@" << u << " -> " << v << " (" << k << ") = ";
                // cout << f[v][k - 1] << ' ' << du << endl;
                f[v][k - 1] = du + 0;
                pq.push(dij_t(f[v][k - 1], v, k - 1));
            }
        }
    }

    return *min_element(all(f[t]));
}

int main()
{
    readGraph();
    cout << dijkstra(1, n);
    return 0;
}