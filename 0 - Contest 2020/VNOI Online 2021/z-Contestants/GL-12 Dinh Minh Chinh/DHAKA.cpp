#include <bits/stdc++.h>
#define long long long
#define FOR(i, st, en) for (int i = st, _en = (en); i <= _en; ++i)
#define REP(i, en) for (int i = 0, _en = (en); i < _en; ++i)
#define FORD(i, st, en) for (int i = st, _en = (en); i >= _en; --i)
#define FORE(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define MASK(n) (1 << (n))
#define BIT(x, i) (((x)>>(i)) & 1)
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define taskname "DHAKA"
#define file                              \
	freopen(taskname".INP", "r", stdin); \
	freopen(taskname".OUT", "w", stdout)
using namespace std;
template<class T> bool minimize(T& x, const T& y) {
	if (x > y) {x = y; return true;}
	return false;
}
template<class T> bool maximize(T& x, const T& y) {
	if (x < y) {x = y; return true;}
	return false;
}
// ----------------------------------------------------------------------------------
typedef pair<int, int> ii;
const long inf = 1e18;
const int mod = 1e9+7;
#define maxn 100005

int n, m, k, l;
struct Node {
    long first; int second, mask;
    bool operator < (const Node &other) const {
        return first > other.first;
    }
};
vector<Node> adj[maxn];
long dist[maxn][1<<5];
bool vis[maxn][1<<5];
int now[maxn];
// ----------------------------------------------------------------------------------
void test_case() {
    cin >> n >> m >> k >> l;
    FOR(i, 1, n) {
        int s; cin >> s; while (s--) {
            int x; cin >> x; x--;
            now[i] |= MASK(x);
        }
    }
    FOR(i, 1, m) {
        int u, v; long c; cin >> u >> v >> c;
        adj[u].push_back({c, v, now[v]});
        adj[v].push_back({c, u, now[u]});
    }

    FOR(i, 1, n) REP(mask, MASK(k)) dist[i][mask] = inf; dist[1][now[1]] = 0;
    priority_queue<Node> heap; heap.push({dist[1][now[1]], 1, now[1]});
    while (!heap.empty()) {
        Node top = heap.top(); heap.pop();
        long cur = top.first; int u = top.second, mask = top.mask;

        if (cur > dist[u][mask]) continue;
        if (u == n && __builtin_popcount(mask) >= l) break;

        for (Node it : adj[u]) {
            long len = it.first; int v = it.second, nwmask = it.mask|mask;
            if (minimize(dist[v][nwmask], cur + len))
                heap.push({dist[v][nwmask], v, nwmask});
        }
    }

    long res = inf;
    REP(mask, MASK(k)) if (__builtin_popcount(mask) >= l)
        minimize(res, dist[n][mask]);
    if (res == inf) res = -1;
    cout << res << endl;
}

int main() {
	fastio;
	file;

	test_case();
	return 0;
}

/*
(\_/)
( •_•)
/>(:3)<
Mlem Mlem */

