#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e5 + 10;

const ll inf = 1e18;

ll d[maxn][50];

int n, m, k, l;

vector< pair< int, int > > g[maxn];
vector< int > a[maxn];

struct ABC {
  ll du; int u, msk;
  ABC(ll _du = 0, int _u = 0, int _msk = 0) : du(_du), u(_u), msk(_msk) {}
  bool operator < (const ABC &op) const {
    return du > op.du;
  }
};

int main(){
    #define Task "DHAKA"
    if (fopen(Task".inp", "r")) {
      freopen(Task".inp", "r", stdin); freopen(Task".out", "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> l;

    for (int i = 1; i <= n; ++i) {
      int sz; cin >> sz;
      a[i].resize(sz);
      for (int j = 0; j < sz; ++j) {
        cin >> a[i][j];
        --a[i][j];
      }
    }

    for (int i = 0; i < m; ++i) {
      int u, v, l; cin >> u >> v >> l;
      g[u].push_back({v, l}); g[v].push_back({u, l});
    }

    for (int i = 1; i <= n; ++i)
    for (int j = 0; j < (1 << k); ++j)
      d[i][j] = inf;

    int cur = 0;

    for (int id = 0; id < a[1].size(); ++id) {
      int T = a[1][id];
      cur = cur | (1 << T);
    }

    d[1][cur] = 0;

    priority_queue< ABC > pq;

    pq.push(ABC(d[1][cur], 1, cur));

    while (!pq.empty()) {
      ll du = pq.top().du; int u = pq.top().u; int msk = pq.top().msk;
      pq.pop();

      if (du > d[u][msk]) continue;

      for (int id = 0; id < g[u].size(); ++id) {
        int v = g[u][id].first, l = g[u][id].second;

        int nmsk = msk;
        for (int j = 0; j < a[v].size(); ++j) {
          nmsk = nmsk | (1 << a[v][j]);
        }

        if (d[v][nmsk] > du + l) {
          d[v][nmsk] = du + l;
          pq.push(ABC(d[v][nmsk], v, nmsk));
        }

      }
    }

    ll ans = inf;

    for (int msk = 0; msk < (1 << k); ++msk) {
      if (__builtin_popcount(msk) >= l) ans = min(ans, d[n][msk]);
    }

    if (ans >= inf) cout << -1;
    else
      cout << ans;

    return 0;
}
