#include <bits/stdc++.h>

using namespace std;

int main() {
#if ONLINE_JUDGE || THEMIS
  freopen("tigersugar2.inp", "r", stdin);
  freopen("tigersugar2.out", "w", stdout);
#else
  freopen("local.in", "r", stdin);
  freopen("local.out", "w", stdout);
#endif
  int n, k;
  scanf("%d%d", &n, &k);
  vector<pair<int, int>> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    x[i] = {a, i};
    y[i] = {b, i};
  }
  auto process = [&](vector<pair<int, int>>& x) {
    auto optimize = [&](int& x, int& y) {
      int d = min(k, abs(x - y));
      k -= d;
      x += x < y ? d : -d;
    };
    sort(x.begin(), x.end());
    for (int i = 0; i + 1 < n; ++i) {
      if (i == 0) {
        optimize(x[i].first, x[i + 1].first);
      } else {
        optimize(x[i + 1].first, x[i].first);
      }
    }
  };
  process(x);
  process(y);
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    a[x[i].second].first = x[i].first;
    a[y[i].second].second = y[i].first;
  }
  long long sum_dist = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      sum_dist += abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
    }
  }
  printf("%lld\n", sum_dist);
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", a[i].first, a[i].second);
  }
  return 0;
}
