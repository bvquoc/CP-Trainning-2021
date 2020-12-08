#include <bits/stdc++.h>

using namespace std;

class fenwick_tree {
  int n;
  vector<int> tree;
  vector<int> vals;
  stack<pair<int, int>> ops;

public:
  fenwick_tree(const vector<int>& v)
  : vals(v) {
    n = v.size() / 5;
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    tree.resize(vals.size());
  }

  inline int index(int v) {
    return lower_bound(vals.begin(), vals.end(), v) - vals.begin();
  }

  void update(int v, int d) {
    v = index(v);
    while (v < vals.size()) {
      tree[v] += d;
      v |= v + 1;
    }
  }

  int query_lower(int v) {
    v = index(v) - 1;
    int res = 0;
    while (v >= 0) {
      res += tree[v];
      v = (v & v + 1) - 1;
    }
    return res;
  }

  int query_upper(int v) {
    v = index(v);
    int res = n;
    while (v >= 0) {
      res -= tree[v];
      v = (v & v + 1) - 1;
    }
    return res;
  }

  int change(int v, int d, bool flag = true) {
    if (flag) {
      ops.push({v + d, -d});
    }
    int l = query_lower(v);
    int u = query_upper(v);
    update(v, -1);
    update(v + d, 1);
    return (l - u) * d + n - (l + u + 1);
  }

  void rollback() {
    while (ops.size()) {
      change(ops.top().first, ops.top().second, false);
      ops.pop();
    }
  }
};

const long long inf = 2e18;

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
  auto calc = [&](vector<pair<int, int>>& x) {
    long long sum_dist = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
      sum_dist += (long long)i * x[i].first - sum;
      sum += x[i].first;
    }
    return sum_dist;
  };
  auto solve = [&](vector<pair<int, int>>& x) {
    sort(x.begin(), x.end());
    vector<pair<long long, vector<pair<int, int>>>> res(k + 1);
    vector<int> vals;
    vals.reserve(n * 5);
    for (auto& i : x) {
      for (int j = -2; j <= 2; ++j) {
        vals.push_back(i.first + j);
      }
    }
    fenwick_tree ft(vals);
    for (auto& i : x) {
      ft.update(i.first, 1);
    }
    long long sum_dist = res[0].first = calc(res[0].second = x);
    if (k >= 1) {
      long long best_sum_dist = inf;
      pair<int, int> best_change;
      for (int i = 0; i < n; ++i) {
        for (int d : {-1, 1}) {
          long long new_sum_dist = sum_dist + ft.change(x[i].first, d);
          if (new_sum_dist < best_sum_dist) {
            best_sum_dist = new_sum_dist;
            best_change = {i, d};
          }
          ft.rollback();

        }
      }
      res[1].first = best_sum_dist;
      res[1].second = x;
      res[1].second[best_change.first].first += best_change.second;
    }
    if (k == 2) {
      long long best_sum_dist = inf;
      pair<int, int> best_change[2];
      for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
          for (int di : {-1, 1}) {
            for (int dj : {-1, 1}) {
              long long new_sum_dist = sum_dist + ft.change(x[i].first, di);
              x[i].first += di;
              new_sum_dist += ft.change(x[j].first, dj);
              if (new_sum_dist < best_sum_dist) {
                best_sum_dist = new_sum_dist;
                best_change[0] = {i, di};
                best_change[1] = {j, dj};
              }
              x[i].first -= di;
              ft.rollback();
            }
          }
        }
      }
      res[2].first = best_sum_dist;
      res[2].second = x;
      for (int i = 0; i < 2; ++i) {
        res[2].second[best_change[i].first].first += best_change[i].second;
      }
    }
    return res;
  };
  auto sx = solve(x);
  auto sy = solve(y);
  long long debug = 0;
  vector<pair<int, int>> u, v;
  long long ans = inf;
  for (int s = 0; s <= k; ++s) {
    for (int i = 0; i <= s; ++i) {
      if (ans > sx[i].first + sy[s - i].first) {
        ans = sx[i].first + sy[s - i].first;
        u = sx[i].second;
        v = sy[s - i].second;
      }
    }
  }
  printf("%lld\n", ans);
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    a[u[i].second].first = u[i].first;
    a[v[i].second].second = v[i].first;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", a[i].first, a[i].second);
  }
  return 0;
}
