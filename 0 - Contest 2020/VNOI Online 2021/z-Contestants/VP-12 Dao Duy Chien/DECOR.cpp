#include<bits/stdc++.h>

#define maxn 500005

using namespace std;
typedef long long ll;

int n, m, k;

int d[maxn], sz[maxn], cnt[maxn];

int cur = 0;

int root(int u) {
  return u == d[u] ? u : d[u] = root(d[u]);
}

void add(int u, int ok) {
  u = root(u);
  cur -= (cnt[u] - min(cnt[u], sz[u]));
  cnt[u] += ok;
  cur += (cnt[u] - min(cnt[u], sz[u]));
}

int main() {
  #define TASK "DECOR"

  if (fopen(TASK".INP", "r")) {
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
  }

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m >> k;

  for (int i = 1; i <= n; ++i) {
    char c;
    cin >> c;

    d[i] = i;
    sz[i] = (c == '1' ? 1 : 0);
  }

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;

    u = root(u);
    v = root(v);

    if (u == v) continue;

    d[u] = v;
    sz[v] += sz[u];
  }

  int l = -1, r = -2;

  for (int i = 1, j = 1; i <= n; ++i) {
    while (j <= n && cur <= k) {
      add(j, 1);
      if (cur > k) {
        add(j, -1);
        break;
      }
      j++;
    }

    if (r - l < j - i - 1) {
      l = i;
      r = j - 1;
    }

    add(i, -1);
  }

  cout << l;
  if (l != -1) cout << ' ' << r;

  return 0;
}
