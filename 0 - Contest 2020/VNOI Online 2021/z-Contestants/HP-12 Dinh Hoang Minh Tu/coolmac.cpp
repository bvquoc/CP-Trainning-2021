#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

const int N = 1e5 + 5;
const int inf = 1e9;
int n, m, a[N], mi[N];
vector<int> in[N];
ii seg[N];
int it[N << 2];

void modify(int i, int l, int r, int pos, int val) {
  if(pos < l || pos > r) return;
  if(l == r) {
    it[i] = val;
    return;
  }
  int mid = l + (r - l) / 2;
  modify(i << 1, l, mid, pos, val);
  modify(i << 1 | 1,  mid + 1, r, pos, val);
  it[i] = min(it[i << 1], it[i << 1 | 1]);
}
int que(int i, int l, int r, int u, int v) {
  if(v < l || u > r || u > v) return inf;
  if(u <= l && r <= v) return it[i];
  int mid = l + (r - l) / 2;
  return min(que(i << 1, l, mid, u, v), que(i << 1 | 1, mid + 1, r, u, v));
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  #define task "coolmac"
  freopen(task".inp", "r", stdin);
  freopen(task".out", "w", stdout);

  cin >> m;
  for (int i = 1; i <= m; ++i) {
    int l, r;
    cin >> l >> r;
    seg[i] = {l, r};
    in[r].eb(l);
  }
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int lef = *min_element(a + 1, a + n + 1);
  for (int i = 1; i < 4 * N; ++i) it[i] = inf;
  for (int i = 0; i < lef; ++i) {
    modify(1, 0, 1e5, i, 0);
  }
  for (int i = lef; i <= 1e5; ++i) {
    int cur = inf;
    for (int &v : in[i]) {
      if(v == lef) {
        cur = min(cur, que(1, 0, 1e5, 0, i));
      } else {
        cur = min(cur, que(1, 0, 1e5, v, i));
      }
    }
    modify(1, 0, 1e5, i, cur + 1);
  }
  int ans = que(1, 0, 1e5, 1e5, 1e5);
  if(ans == inf) ans = -1;
  cout << ans << '\n';
}
