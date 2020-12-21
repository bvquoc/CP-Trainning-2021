#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 5e5 + 10;

int n, m, k;

vector< int > g[maxn];
vector< int > st[maxn];

int id_ncc[maxn], delta[maxn], col[maxn];

int cur_l[maxn], cur_r[maxn];

int pos[maxn];

int ncc = 0;

void dfs(int u) {
  id_ncc[u] = ncc;

  for (int id = 0; id < g[u].size(); ++id) {
    int v = g[u][id];
    if (!id_ncc[v]) dfs(v);
  }

}

int ans = 0;

bool check(int mid) {
  int res = 0;

  for (int i = 1; i <= ncc; ++i) {
    cur_l[i] = 0; cur_r[i] = -1;
  }

  for (int i = 1; i <= mid; ++i) {
    int id = id_ncc[i];
    if (cur_l[id] > cur_r[id]) {
      res = res + min(delta[id], 1);
    } else {
      res = res - min(delta[id], cur_r[id] - cur_l[id] + 1);
      res = res + min(delta[id], cur_r[id] + 1 - cur_l[id] + 1);
    }
    ++cur_r[id];
  }

  if (res + k >= mid) {
    ans = 1; return 1;
  }

  int i = 1, j = mid;

  while (j + 1 <= n) {
    int id_i = id_ncc[i];
    res = res - min(delta[id_i], cur_r[id_i] - cur_l[id_i] + 1);

    cur_l[id_i]++;

    if (cur_l[id_i] <= cur_r[id_i])
      res = res + min(delta[id_i], cur_r[id_i] - cur_l[id_i] + 1);

    ++i;

    ++j;

    int id_j = id_ncc[j];

    if (cur_l[id_j] <= cur_r[id_j])
      res = res - min(delta[id_j], cur_r[id_j] - cur_l[id_j] + 1);

    cur_r[id_j]++;

    res = res + min(delta[id_j], cur_r[id_j] - cur_l[id_j] + 1);

    if (res + k >= mid) {
      ans = i; return 1;
    }
  }

  return 0;
}

int main(){
    #define Task "DECOR"
    if (fopen(Task".inp", "r")) {
      freopen(Task".inp", "r", stdin); freopen(Task".out", "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i) {
      char c; cin >> c;
      col[i] = c - '0';
    }

    for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v;
      g[u].push_back(v); g[v].push_back(u);
    }

    for (int u = 1; u <= n; ++u) {
      if (!id_ncc[u]) {
        ++ncc; dfs(u);
      }
    }

    for (int u = 1; u <= n; ++u) {
      st[id_ncc[u]].push_back(u);
      delta[id_ncc[u]] += col[u];
    }

    for (int i = 1; i <= ncc; ++i) {
      for (int id = 0; id < st[i].size(); ++id) {
        int u = st[i][id];
        pos[u] = id;
      }
    }

    int l = 1, r = n;

    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid)) l = mid + 1;
      else
        r = mid - 1;
    }

    if (l == 1) cout << -1;
    else
      cout << ans <<' '<< ans + l - 2;

    return 0;
}
