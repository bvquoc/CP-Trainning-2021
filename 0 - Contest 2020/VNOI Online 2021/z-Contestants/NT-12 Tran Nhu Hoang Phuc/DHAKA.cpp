#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define FILE_NAME "DHAKA"

using namespace std;

const ll MAXN = 1e5+5, oo = 1e15;
ll n, m, k, l;
ll d[MAXN];
bool melon[MAXN][6];
vector<pair<ll, ll> > adj[MAXN];

void _Dijkstra(ll uStart)
{
    fill(d+1, d+n+1, oo);
    d[uStart] = 0;
    priority_queue<pair<ll, ll> > pq;
    pq.push({0, uStart});

    while(!pq.empty()) {
        ll u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();

        if (du != d[u])
            continue;

        for (auto it : adj[u]) {
            ll v = it.first;
            ll uv = it.second;
            if (d[v] > d[u]+uv) {
                d[v] = du+uv;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    FAST_IO;
    ifstream cin(FILE_NAME".INP");
    ofstream cout(FILE_NAME".OUT");

    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; ++i) {
        ll s;
        cin >> s;
        for (int j = 1; j <= s; ++j) {
            ll a;
            cin >> a;
            melon[i][a] = true;
        }
    }
    for (int i = 1; i <= m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    if (l == 0) {
        _Dijkstra(1);
        if (d[n] == oo)
            cout << -1;
        else cout << d[n];
        return 0;
    }
    return 0;
}
