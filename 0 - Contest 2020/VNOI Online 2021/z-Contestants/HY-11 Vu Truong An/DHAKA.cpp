#include <bits/stdc++.h>
#define Task "DHAKA"
#define F first
#define S second
#define pb push_back

using namespace std;

const int maxn = 100005;

int n, m, k, l;
int store[maxn], cnt[maxn];
vector<pair<int, int> > ke[maxn];
long long d[40][maxn];

namespace Full {

    void DIJK(int t) {
        priority_queue<pair<long long, int> > PQ;
        if(t == 0) {
            d[t][1] = 0;
            PQ.push({0, 1});
        } else {
            for(int i = 1; i <= n; ++ i) {
                if(d[t][i] != 1e18) PQ.push({-d[t][i], i});
            }
        }
        while(PQ.size()) {
            int u = PQ.top().S;
            long long l = - PQ.top().F;
            PQ.pop();
            if(l > d[t][u]) continue;
            for(auto p : ke[u]) {
                int v = p.F;
                long long w = p.S;;
                if(d[t | store[v]][v] > d[t][u] + w) {
                    d[t | store[v]][v] = d[t][u] + w;
                    PQ.push({-d[t | store[v]][v], v});
                }
            }
        }
    }

    void Solve() {
        for(int i = 0; i < (1 << k); ++ i) {
            for(int j = 1; j <= n; ++ j) d[i][j] = 1e18;
        }
        for(int mask = 0; mask < (1 << k); ++ mask) {
            DIJK(mask);
        }
        long long ans = 1e18;
        for(int mask = 0; mask < (1 << k); ++ mask) {
            int x = __builtin_popcount(mask);
            if(x >= l) ans = min(ans, d[mask][n]);
        }
        if(ans == 1e18) ans = -1;
        cout << ans;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; ++ i) {
        int s; cin >> s;
        for(int j = 1; j <= s; ++ j) {
            int x; cin >> x;
            store[i] |= (1 << (x - 1));
        }
    }
    for(int i = 1; i <= m; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        ke[u].pb({v, w});
        ke[v].pb({u, w});
    }
    Full::Solve();
}
