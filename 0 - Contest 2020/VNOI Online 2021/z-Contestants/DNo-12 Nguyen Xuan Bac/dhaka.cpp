#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define fi first
#define se second

#define MASK(i) (1LL << (i))
#define BIT(i, x) (((x) >> (i)) & 1)

#define INF 1e15
const int MAX = 1e5 + 5;
const int maxK = 6;

int n, m, k, l;
int typeD[MAX];
vector<pii> adj[MAX];

pii sta[5000006];
int id[MAX][40];
ll d[5000006];
bool fre[5000006];

void dijsktra() {
    memset(d, -1, sizeof d);
    memset(fre, true, sizeof fre);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    d[id[1][typeD[1]]] = 0;
    pq.push(pli(0LL, id[1][typeD[1]]));

    while (!pq.empty()) {
        int cur = pq.top().se, _w = pq.top().fi; pq.pop();
        if (d[cur] != _w || !fre[cur]) continue;
        fre[cur] = false;
        int u = sta[cur].fi, mask = sta[cur].se;

        for (pii i : adj[u]) {
            int v = i.fi, w = i.se;
            int nxt = id[v][mask | typeD[v]];
            if (!fre[nxt]) continue;

            if (d[nxt] == -1 || d[nxt] > d[cur] + w) {
                d[nxt] = d[cur] + w;
                pq.push(pli(d[nxt], nxt));
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("dhaka.inp", "r", stdin);
	freopen("dhaka.out", "w", stdout);

    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; i++) {
        int s; cin >> s;
        while (s--) {
            int a; cin >> a; a--;
            typeD[i] |= MASK(a);
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back(pii(v, w));
        adj[v].push_back(pii(u, w));
    }

    /* init id */ {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        for (int mask = 0, nMask = MASK(k); mask < nMask; mask++) {
            cnt++;
            id[i][mask] = cnt;
            sta[cnt] = pii(i, mask);
        }
    }

    dijsktra();

    ll res = INF;
    for (int mask = 0, nMask = MASK(k); mask < nMask; mask++)
    if (__builtin_popcount(mask) >= l) {
        int sta = id[n][mask];
        if (d[sta] != -1) res = min(res, d[sta]);
    }

    if (res != INF) cout << res;
    else cout << "-1";

	return 0;
}
