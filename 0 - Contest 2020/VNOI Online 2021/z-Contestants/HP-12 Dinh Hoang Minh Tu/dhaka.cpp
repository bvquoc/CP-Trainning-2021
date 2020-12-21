#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

using lli = long long;

#define bit(x, i) (x >> (i - 1) & 1ll)
#define on(x, i) (x | (1ll << (i - 1)))
#define off(x, i) (x & ~(1ll << (i - 1)))

const int N = 1e5 + 5;

int n, m, k, a[N], l;
vector<ii> adj[N];
lli f[N][35];

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  #define task "dhaka"
  freopen(task".inp", "r", stdin);
  freopen(task".out", "w", stdout);

  cin >> n >> m >> k >> l;
  for (int i = 1; i <= n; ++i) {
    int s; cin >> s;
    while(s--) {
      int x; cin >> x;
      a[i] = on(a[i], x);
    }
  }
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].eb(v, w);
    adj[v].eb(u, w);
  }
  memset(f, 0x3f, sizeof f);
  long long inf = f[0][0];
  f[1][a[1]] = 0;
  using arr3 = tuple<long long, int, int>;
  priority_queue<arr3, vector<arr3>, greater<arr3>> h;
  h.emplace(0, 1, a[1]);
  while(h.size()) {
    long long d;
    int u, tt;
    tie(d, u, tt) = h.top();
    h.pop();
    if(d != f[u][tt]) continue;
    for (auto &_ : adj[u]) {
      int v = _.fi;
      long long w = _.se;
      int new_tt = (tt | (a[v]));
      if(f[v][new_tt] > d + w) {
        f[v][new_tt] = d + w;
        h.emplace(f[v][new_tt], v, new_tt);
      }
    }
  }
  lli ans = inf;
  for (int mask = 0; mask < (1ll << k); ++mask) {
    if(__builtin_popcount(mask) >= l) {
      ans = min(ans, f[n][mask]);
    }
  }
  if(ans >= inf) ans = -1;
  cout << ans << '\n';
}
