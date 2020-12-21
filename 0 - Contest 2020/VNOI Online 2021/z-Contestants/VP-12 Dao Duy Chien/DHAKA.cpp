#include<bits/stdc++.h>

#define oo ll(1e16)
#define MP(u, v) make_pair(u, v)

#define maxn 100005

using namespace std;
typedef long long ll;

int n, m, k, l;
vector < pair < int, int > > g[maxn];

ll d[maxn][40];
int a[maxn];

void dijkstra() {
  for (int i = 1; i <= n; ++i)
    for (int mask = 0; mask < (1 << k); ++mask)
      d[i][mask] = oo;

  d[1][a[1]] = 0;

  priority_queue < pair < ll, pair < int, int > > > q;

  q.push(MP(0, MP(1, a[1])));

  while (!q.empty()) {
    int u = q.top().second.first, mask = q.top().second.second; q.pop();

    for (auto i : g[u]) {
      int v = i.first, w = i.second;
      int newmask = mask | a[v];

      if (d[v][newmask] > d[u][mask] + w) {
        d[v][newmask] = d[u][mask] + w;
        q.push(MP(-d[v][newmask], MP(v, newmask)));
      }
    }
  }
}

int main() {
  #define TASK "DHAKA"

  if (fopen(TASK".INP", "r")) {
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
  }

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m >> k >> l;

  for (int i = 1; i <= n; ++i) {
    int t;
    cin >> t;

    while (t--) {
      int x;
      cin >> x;
      a[i] |= (1 << x - 1);
    }
  }

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;

    g[u].push_back(MP(v, w));
    g[v].push_back(MP(u, w));
  }

  dijkstra();

  ll ans = oo;

  for (int mask = 0; mask < (1 << k); ++mask)
    if (__builtin_popcount(mask) >= l)
      ans = min(ans, d[n][mask]);

  if (ans == oo) ans = -1;
  cout << ans;

  return 0;
}
