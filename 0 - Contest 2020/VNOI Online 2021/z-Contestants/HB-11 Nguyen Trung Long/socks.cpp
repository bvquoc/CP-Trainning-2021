#include <bits/stdc++.h>

const int N = 5e5 + 1;

std::vector<int> G[N];
int color[N], group[N];
int n, q, c;

void sub1 () {
  int k = 0;
  for (int i = 1; i <= n; i++) k += color[i];
  std::cout << (k > 0) << '\n';
  for (int i = 0, pos; i < q; i++) {
    std::cin >> pos;
    if (color[pos]) k--, color[pos] = 0;
    else k++, color[pos] = 1;
    std::cout << (k > 0) << '\n';
  }
}

void dfs (int u, int p) {
  group[u] = c;
  for (int v: G[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
}

void sub2 () {
  for (int i = 1; i <= n; i++)
  if (G[i].size() == 3) {
    for (int v: G[i]) dfs(v, i), ++c;
  }

  int numColor[3];
  memset(numColor, 0, sizeof(numColor));
  for (int i = 1; i <= n; i++) {
    numColor[group[i]] += color[i];
  }
  int tmp = 0;
  for (int i = 0; i < 3; i++) tmp += numColor[i] > 0;
  if (!tmp) std::cout << 0 << '\n';
  else if (tmp <= 2) std::cout << 1 << '\n';
  else std::cout << 2 << '\n';

  for (int i = 0, pos; i < q; i++) {
    std::cin >> pos;
    if (color[pos]) {
      color[pos] = 0;
      numColor[group[pos]]--;
    }
    else {
      color[pos] = 1;
      numColor[group[pos]]++;
    }
    int tmp = 0;
    for (int i = 0; i < 3; i++) tmp += numColor[i] > 0;
    if (!tmp) std::cout << 0 << '\n';
    else if (tmp <= 2) std::cout << 1 << '\n';
    else std::cout << 2 << '\n';
  }
}

int main () {
  freopen("socks.inp", "r", stdin);
  freopen("socks.out", "w", stdout);

  std::cin >> n >> q;
  for (int i = 0; i < n; i++) {
    std::cin >> color[i + 1];
  }
  for (int i = 1, u, v; i < n; i++) {
    std::cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  // Check for sub
  int deg2 = 0, deg3 = 0;
  for (int i = 1; i <= n; i++) {
    deg2 += G[i].size() == 2;
    deg3 += G[i].size() == 3;
  }

  if (deg2 == n - 2) sub1();
  else if (deg2 == n - 4 && deg3 == 1) sub2();
}
