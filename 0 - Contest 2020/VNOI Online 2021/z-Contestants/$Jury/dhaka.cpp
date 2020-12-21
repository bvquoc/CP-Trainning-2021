#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
const int maxm = 1<<5;

int n, m, k, l;
int fruitMask[maxn];
vector<pair<int, int>> adj[maxn];

long long f[maxn][maxm];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TASK "DHAKA"
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);

  cin >> n >> m >> k >> l;

  for(int i = 0; i < n; ++i) {
    int sz; cin >> sz;
    for(int j = 0; j < sz; ++j) {
      int x; cin >> x;
      fruitMask[i] |= (1 << (x - 1));
    }
  }

  for(int i = 0; i < m; ++i) {
    int u, v, w; cin >> u >> v >> w;
    --u; --v;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  memset(f, 60, sizeof f);
  set<tuple<long long, int, int>> que;

  que.emplace(f[0][fruitMask[0]] = 0, 0, fruitMask[0]);
  while(!que.empty()) {
    auto [w, v, mask] = *que.begin(); que.erase(que.begin());
    if(f[v][mask] < w) continue;

    for(auto e : adj[v]) {
      int s = e.first, w = e.second;
      int newMask = mask | fruitMask[s];
      if(f[s][newMask] > f[v][mask] + w) {
        f[s][newMask] = f[v][mask] + w;
        que.emplace(f[s][newMask], s, newMask);
      }
    }
  }

  long long ans = f[n-1][(1 << k) - 1];

  for(int mask = 0; mask < (1 << k); ++mask) {
    if(__builtin_popcount(mask) >= l) ans = min(ans, f[n-1][mask]);
  }

  if(ans > 1e15) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}