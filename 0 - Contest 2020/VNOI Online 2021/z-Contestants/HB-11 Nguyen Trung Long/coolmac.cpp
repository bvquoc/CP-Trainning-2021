#include <bits/stdc++.h>
#define pii std::pair<int, int>

int main () {
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::ios_base::sync_with_stdio(0);
  freopen("coolmac.inp", "r", stdin);
  freopen("coolmac.out", "w", stdout);

  int n, m, res = 0;
  std::cin >> m;
  std::vector<pii> range(m);
  for (int i = 0; i < m; i++)
    std::cin >> range[i].first >> range[i].second;

  std::cin >> n;
  int lowerbound = 1e5, upperbound = 1e5;
  for (int i = 0, tmp; i < n; i++) {
    std::cin >> tmp;
    lowerbound = std::min(lowerbound, tmp);
  }
  std::sort(range.begin(), range.end());
  lowerbound--;
  for (int i = 0; lowerbound < upperbound && i < m; res++) {
    int next = 0;
    while (i < m && range[i].first <= lowerbound + 1) {
      next = std::max(next, range[i].second);
      i++;
    }
    if (!next) {
      std::cout << -1;
      return 0;
    }
    lowerbound = next;
  }
  if (lowerbound < upperbound) std::cout << -1;
  else std::cout << res;
}
