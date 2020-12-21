#include<bits/stdc++.h>

#define MP(u, v) make_pair(u, v)
#define maxn 500005

using namespace std;
typedef long long ll;

int n, m;

struct fenwick{
  int f[maxn];

  void update(int i, int x = 1) {
    for (; i <= n; i += (i & -i))
      f[i] += x;
  }

  int get(int i) {
    int ret = 0;

    for (; i; i -= (i & -i))
      ret += f[i];

    return ret;
  }

  int get(int i, int j) {
    return get(j) - get(i - 1);
  }
} up, down;

int ok[maxn], a[maxn];
int st[maxn], en[maxn];

int h[maxn], pa[maxn][20];

vector < int > g[maxn];

void dfs(int u, int du) {
  int static nnode = 0;

  st[u] = ++nnode;

  for (auto v : g[u])
    if (v != du) {
      h[v] = h[u] + 1;
      pa[v][0] = u;

      for (int i = 1; i < 20; ++i)
        pa[v][i] = pa[pa[v][i - 1]][i - 1];

      dfs(v, u);
    }

  en[u] = nnode;
}

int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);

  for (int i = 19; i >= 0; --i)
    if (h[pa[u][i]] >= h[v])
      u = pa[u][i];

  if (u == v) return u;

  for (int i = 19; i >= 0; --i)
    if (pa[u][i] != pa[v][i]) {
      u = pa[u][i];
      v = pa[v][i];
    }

  return pa[u][0];
}

int find_parent(int u, int c) {
  int x = u;

  for (int i = 19; i >= 0; --i)
    if (up.get(st[pa[u][i]]) + c == up.get(st[x]))
      u = pa[u][i];

  return u;
}

set < pair < int, int > > s;

void addset(int u, int ok) {
  if (s.find(MP(st[u], u)) != s.end() && !ok) s.erase(MP(st[u], u));
  if (ok) s.insert(MP(st[u], u));
}

void add(int u) {
  int sign = (ok[u] ? 1 : -1);
  up.update(st[u], -sign);
  up.update(en[u] + 1, sign);

  down.update(st[u], -sign);

  ok[u] = 1 - ok[u];

  if (ok[u]) {
    if (down.get(st[u], en[u]) > 1) return;

    int p = find_parent(u, 1);
  //  cerr << u << ' ' << p << '\n';
    if (p) addset(p, 0);
    addset(u, 1);
  }
  else {
    if (down.get(st[u], en[u]) > 0) return;

    addset(u, 0);
    int p = find_parent(u, 0);

   // cerr << u << ' ' << p << '\n';

    if (p) {
      if (down.get(st[p], en[p]) > 1) return;
      addset(p, 1);
    }
  }
}

int calc() {
  int ret = s.size();

  //cerr << ret << '\n';

  if (s.empty()) return 0;

  int c = lca(s.begin() -> second, prev(s.end()) -> second);

 // cerr << c << '\n';

  if (up.get(st[pa[c][0]])) ret++;

  if (ret == 1) return 0;

  return (ret + 1) / 2;
}

int main() {
  #define TASK "SOCKS"

  if (fopen(TASK".INP", "r")) {
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
  }

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;

    g[u].push_back(v);
    g[v].push_back(u);
  }

  h[1] = 1;
  dfs(1, 1);

  for (int i = 1; i <= n; ++i)
    if (a[i])
      add(i);

  cout << calc() << '\n';

  while (m--) {
    int x;
    cin >> x;

    add(x);

    cout << calc() << '\n';
  }


  return 0;
}
