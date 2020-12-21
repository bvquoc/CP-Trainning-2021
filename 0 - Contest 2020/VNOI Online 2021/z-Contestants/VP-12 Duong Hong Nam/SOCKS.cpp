#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 5e5 + 10;

int n, q;
int col[maxn], deg[maxn], dem[maxn];

vector< int > g[maxn];

namespace subtask1 {

void run() {
  set< int > s;
  for (int i = 1; i <= n; ++i) {
    if (col[i]) s.insert(i);
  }

  ++q;
  bool flag = 1;

  while (q--) {
    int u; cin >> u;
    if (!flag) {
      col[u] = col[u] ^ 1;

      if (col[u]) s.insert(u);
      else
        s.erase(u);
    }

    flag = 0;

    if (s.size() > 1) cout << 1 << '\n';
    else
      cout << 0 << '\n';
  }
}

}

namespace subtask2 {

int root;

int mark[maxn];
int ncc = 0;

void dfs(int u, int par) {
  mark[u] = ncc;

  for (int id = 0; id < g[u].size(); ++id) {
    int v = g[u][id];

    if (v == par) continue;

    dfs(v, u);
  }

}

set< int > s[3];

void run() {
  for (int u = 1; u <= n; ++u) {
    if (deg[u] == 3) root = u;
  }
  for (int id = 0; id < g[root].size(); ++id) {
    int v = g[root][id];
    dfs(v, root);
    ++ncc;
  }

  for (int u = 1; u <= n; ++u) {
    if (root == u) continue;
    if (col[u]) s[mark[u]].insert(u);
  }

  ++q;
  bool flag = 1;

  while (q--) {
    int u; cin >> u;

    if (!flag) {
      col[u] = 1 ^ col[u];

      if (u != root) {
        if (col[u]) s[mark[u]].insert(u);
        else
          s[mark[u]].erase(u);
      }
    }

    flag = 0;

    int cnt = 0;

    if (s[0].size() > 0) ++cnt;
    if (s[1].size() > 0) ++cnt;
    if (s[2].size() > 0) ++cnt;

    if (col[root]) {
      if (cnt == 3) cout << 2 << '\n';
      else
        if (cnt == 2) cout << 1 << '\n';
      else
        if (cnt == 1) cout << 1 << '\n';
      else
        if (cnt == 0) cout << 0 << '\n';
    } else {
      if (cnt == 3) cout << 2 << '\n';
      else
        if (cnt == 2) cout << 1 << '\n';
      else
        if (cnt == 1) {
          int id;
          if (s[0].size() > 0) id = 0;
          if (s[1].size() > 0) id = 1;
          if (s[2].size() > 0) id = 2;

          if (s[id].size() > 1) cout << 1 << '\n';
          else
            cout << 0 << '\n';
        }
      else
        if (cnt == 0)
          cout << 0 << '\n';
    }
  }

}

}

int main(){
    #define Task "SOCKS"
    if (fopen(Task".inp", "r")) {
      freopen(Task".inp", "r", stdin); freopen(Task".out", "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
      cin >> col[i];

    for (int i = 1; i < n; ++i) {
      int u, v; cin >> u >> v;
      g[u].push_back(v); g[v].push_back(v);
      ++deg[u]; ++deg[v];
    }

    int Max = 0;

    for (int u = 1; u <= n; ++u) {
      dem[deg[u]]++;
      Max = max(Max, deg[u]);
    }

    if (Max == 2) {
      subtask1::run();
      return 0;
    }

    if (Max == 3 && dem[3] == 1) {
      subtask2::run();
      return 0;
    }

    return 0;
}
