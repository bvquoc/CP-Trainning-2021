#include <bits/stdc++.h>
#define tkn "DHAKA"
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n, m, k, l;
const int N = 1e5 + 7;
vector<int> wml[N];
vector<pii> adj[N];
ll f[N][67];
void input() {
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; i++) {
        int s, u;
        cin >> s;
        while (s--) {
            cin >> u;
            wml[i].pb(--u);
        }
    }
    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
}
void init() {
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 64; j++)
            f[i][j] = 1e18;
}
bool check(int state) {
    int res = 0;
    for (int i = 0; i < k; i++)
        res += (state >> i) % 2;
    return res >= l;
}
struct cmp {
    bool operator() (pair<ll, pii> c1, pair<ll, pii> c2) {
        return c1.fi > c2.fi;
    }
};
priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, cmp> heap;
void solve() {
    int state = 0;
    for (auto p : wml[1])
        state |= (1 << p);
    f[1][state] = 0;
    heap.push({0, {1, state}});
    int u, v, nsta;
    ll fu, fv;
    while (!heap.empty()) {
        fu = heap.top().fi;
        u = heap.top().se.fi;
        state = heap.top().se.se;
        heap.pop();
        if (f[u][state] != fu) continue;
        if (u == n) {
            if (check(state)) {
                cout << fu;
                exit(0);
            }
        }
        for (auto p : adj[u]) {
            v = p.fi;
            fv = fu + p.se;
            nsta = state;
            for (auto rd : wml[v])
                nsta |= (1 << rd);
            if (f[v][nsta] > fv) {
                f[v][nsta] = fv;
                heap.push({fv, {v, nsta}});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    freopen(tkn".inp", "r", stdin);
    freopen(tkn".out", "w", stdout);
    cin.tie(0);  cout.tie(0);

    input();
    init();
    solve();

    cout << -1;

    return 0;
}
