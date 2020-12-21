#include <bits/stdc++.h>
/// kitsune
using namespace std;

#define int long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define yn(x) ((x) ? "YES" : "NO")

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef array <int, 3> ar3;

template <typename _Tp, typename _Up> bool maximize(_Tp &__a, _Up __b) { if (__a < __b) { __a = __b; return true; } return false; }
template <typename _Tp, typename _Up> bool minimize(_Tp &__a, _Up __b) { if (__a > __b) { __a = __b; return true; } return false; }

const int siz = 1e5 + 2;
const int SIZ = 1e6 + 2;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e18;
const string file = "DHAKA";

int k, l;
int a[siz];
vector <vector <ii> > adj_list;
int dist[siz][1 << 5]; bool done[siz][1 << 5];

int Dijkstra(int s, int t) {
    priority_queue <iii, vector <iii>, greater <iii> > pq;
    memset(dist, 0x3f, sizeof(dist));
    pq.push(iii(dist[s][a[s]] = 0, ii(s, a[s])));

    while (!pq.empty()) {
        int u = pq.top().se.fi, cur_mask = pq.top().se.se;
        pq.pop();

        if (done[u][cur_mask]) {
            continue;
        }
        done[u][cur_mask] = true;

        for (auto x : adj_list[u]) {
            int v = x.fi, w = x.se;
            int nxt_mask = cur_mask | a[v];

            if (minimize(dist[v][nxt_mask], dist[u][cur_mask] + w)) {
                pq.push(iii(dist[v][nxt_mask], ii(v, nxt_mask)));
            }
        }
    }

    int ans = MAXX;
    for (int mask = 1; mask < (1 << k); mask++) {
        if (__builtin_popcount(mask) >= l) {
            minimize(ans, dist[t][mask]);
        }
    }

    if (ans == MAXX) {
        ans = -1;
    }

    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen ((file + ".inp").c_str(), "r", stdin);
    freopen ((file + ".out").c_str(), "w", stdout);

    int n, m;
    cin >> n >> m >> k >> l;

    for (int u = 1; u <= n; u++) {
        int b;
        cin >> b;

        while (b--) {
            int x;
            cin >> x;

            a[u] |= (1 << (x - 1));
        }
    }

    adj_list.resize(n + 1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;

        adj_list[u].push_back(ii(v, w));
        adj_list[v].push_back(ii(u, w));
    }

    cout << Dijkstra(1, n) << "\n";

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";

    return 0;
}
