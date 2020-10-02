#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 102;
const int INF = LLONG_MAX - (1e9*1e9);

int n, m, a[N][N];
vector <ii> ke[N], edges;
int cost = INF;
stack <int> ans;
int d[N], t[N];
bool pre[N];

void dijkstra(int _u, int _v) {
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    FOR(i,1,n) {
        d[i] = INF;
        t[i] = -1;
        pre[i] = true;
    }
    stack <int> S;
    d[_u] = 0;
    pq.push(ii(d[_u], _u));

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (u == _v) {
            if (cost > a[_u][_v] + d[_v]) {
                cost = a[_u][_v] + d[_v];
                while (u != -1) {
                    S.push(u);
                    u = t[u];
                }
                ans = S;
            }
            return;
        }
        if (!pre[u]) continue;
        pre[u] = true;

        for (ii tmp: ke[u]) {
            int v = tmp.first, w = tmp.second;
            if (!pre[v]) continue;
            if (u == _u && v == _v) continue;
            if (d[v] < d[u] + w) continue;
            d[v] = d[u] + w;
            t[v] = u;
            pq.push(ii(d[v], v));
        }
    }
}

signed main(void) {
    FastIO;
    freopen("DULICH.INP", "r", stdin);
    freopen("DULICH.OUT", "w", stdout);

    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        if (a[u][v]) a[u][v] = a[v][u] = min(a[u][v], w);
        else a[u][v] = a[v][u] = w;
    }

    FOR(i,1,n) {
        FOR(j,i+1,n) {
            if (!a[i][j]) continue;
            edges.push_back(ii(i, j));
            ke[i].push_back(ii(j, a[i][j]));
            ke[j].push_back(ii(i, a[i][j]));
        }
    }

    for (ii e: edges) {
        dijkstra(e.first, e.second);
    }

    if (cost != INF) {
        cout << "1\n";
        cout << cost << endl;
        cout << ans.size() << endl;
        while (!ans.empty()) {
            cout << ans.top() << endl;
            ans.pop();
        }
    } else cout << '0';

    return 0;
}