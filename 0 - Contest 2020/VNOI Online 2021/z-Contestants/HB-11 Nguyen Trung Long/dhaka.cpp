#include <bits/stdc++.h>
#define int long long
#define vec std::vector

struct state {
  int u, color;
  state (int _u = 0, int _color = 0) {
    u = _u, color = _color;
  }
};
bool operator < (state a, state b) {
  return a.u < b.u;
}
#define pii std::pair<int, state>

const int N = 1e5 + 1;
const int INF = 1e18;
int n, m, l, k;
vec<std::pair<int, int>> G[N];
vec<int> d[N];
int color[N];

void dijkstra (int s) {
  for (int i = 0; i <= n; i++) {
    d[i] = vec<int>(32, INF);
  }
  std::priority_queue<pii, vec<pii>, std::greater<pii>> Q;
  d[s][color[s]] = 0;
  Q.push({0, state(s, color[s])});

  while (Q.size()) {
    int u = Q.top().second.u;
    int du = Q.top().first;
    int ucolor = Q.top().second.color;

    Q.pop();
    if (du != d[u][ucolor]) continue;

    for (auto p: G[u]) {
      int v = p.first;
      int w = p.second;
      int c = ucolor | color[v];

      if (d[v][c] > d[u][ucolor] + w) {
        d[v][c] = d[u][ucolor] + w;
        Q.push({d[v][c], state(v, c)});
      }
    }
  }
}

int countOne (int n) {
  int res = 0;
  for (; n; n >>= 1) res += n % 2;
  return res;
}

main () {
  freopen("dhaka.inp", "r", stdin);
  freopen("dhaka.out", "w", stdout);

  std::cin >> n >> m >> k >> l;
  for (int i = 1, tmp; i <= n; i++) {
    std::cin >> tmp;
    for (int j = 0, p; j < tmp; j++) {
      std::cin >> p;
      color[i] |= (1 << (p - 1));
    }
  }

  for (int i = 0, u, v, w; i < m; i++) {
    std::cin >> u >> v >> w;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }

  dijkstra(1);

  int ans = INF;

  for (int i = 0; i < 1 << k; i++) {
    if (countOne(i) >= l) ans = std::min(ans, d[n][i]);
  }

  if (ans == INF) std::cout << -1;
  else std::cout << ans;
}
