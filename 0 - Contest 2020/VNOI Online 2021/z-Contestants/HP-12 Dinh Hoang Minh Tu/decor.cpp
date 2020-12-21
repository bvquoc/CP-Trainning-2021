#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

using lli = long long;

#define bit(x, i) (x >> (i - 1) & 1ll)
#define on(x, i) (x | (1ll << (i - 1)))
#define off(x, i) (x & ~(1ll << (i - 1)))

const int N = 5e5 + 5;
int n, m, k, s[N];
string a;
ii edges[N];
vector<int> adj[N];

void trys() {
  int ans = 0, l = 0, r = 0;
  for (int i = 1; i <= n; ++i) {
    int j = i;
    while(j <= n && a[i] == a[j]) {
      ++j;
    }
    --j;
    if(a[i] == '1') {
      if(ans < j - i + 1) {
        ans = j - i + 1;
        l = i, r = j;
      }
    }
    i = j;
  }
  if(l == 0 && r == 0) {
    cout << -1 << '\n';
  } else {
    cout << l << ' ' << r << '\n';
  }
}
void trys1() {
  for (int i = 1; i <= n; ++i) {
    s[i] = s[i - 1] + (a[i] == '0');
  }
  auto chk = [&](int val) {
    for (int i = 1; i <= n - val + 1; ++i) {
      int j = i + val - 1;
      if(s[j] - s[i - 1] <= k) {
        return true;
      }
    }
    return false;
  };
  int l = 1, r = n, ans = -1;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    if(chk(mid)) ans = mid, l = mid + 1;
    else r = mid - 1;
  }
  if(ans == -1) {
    cout << -1 << '\n';
    return;
  }
  int le = 0, ri = 0;
  for (int i = 1; i <= n - ans + 1; ++i) {
    int j = i + ans - 1;
    if(s[j] - s[i - 1] <= k) {
      le = i, ri = j;
      break;
    }
  }
  cout << le << ' ' << ri << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  #define task "decor"
  freopen(task".inp", "r", stdin);
  freopen(task".out", "w", stdout);

  cin >> n >> m >> k;
  cin >> a;
  a = ' ' + a;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[i] = {u, v};
    adj[u].eb(v); adj[v].eb(u);
  }
  if(m == 0 && k == 0) {
    trys();
  } else if(m == 0) trys1();
  else {
    int l = 1, r = n, ans = -1;

    struct dsu {
      vector<int> id;
      vector<int> sz;
      void init(int n) {
        id.assign(n + 5, -1);
        sz.assign(n + 5, 0);
        for (int i = 1; i <= n; ++i) {
          sz[i] = (a[i] == '1');
        }
      }
      int findset(int u) {
        if(id[u] < 0) return u;
        return id[u] = findset(id[u]);
      }
      void mergeset(int u, int v) {
        u = findset(u), v = findset(v);
        if(u == v) return;
        if(id[u] < id[v]) swap(u, v);
        sz[u] += sz[v];
        id[u] += id[v];
        id[v] = u;
      }
    };
    dsu pa;
    pa.init(n);
    for (int i = 1; i <= m; ++i) {
      pa.mergeset(edges[i].fi, edges[i].se);
    }

    auto chk = [&](int val) {
      for (int i = 1; i <= n - val + 1; ++i) {
        int j = i + val - 1;
        vector<int> root;
        for (int t = i; t <= j; ++t) {
          root.eb(pa.findset(t));
        }
        sort(begin(root), end(root));
        root.erase(unique(begin(root), end(root)), end(root));
        int tot = 0;
        for (int &v : root) {
          tot += pa.sz[v];
        }
        if(tot + k >= val) {
          return true;
        }
      }
      return false;
    };

    while(l <= r) {
      int mid = l + (r - l) / 2;
      if(chk(mid)) ans = mid, l = mid + 1;
      else r = mid - 1;
    }

    if(ans == -1) return cout << -1, 0;

    int lef = 0,  rig = 0;
    for (int i = 1; i <= n - ans + 1; ++i) {
      int j = i + ans - 1;
      vector<int> root;
      for (int t = i; t <= j; ++t) {
        root.eb(pa.findset(t));
      }
      sort(begin(root), end(root));
      root.erase(unique(begin(root), end(root)), end(root));
      int tot = 0;
      for (int &v : root) {
        tot += pa.sz[v];
      }
      if(tot + k >= ans) {
        lef = i, rig = j;
        break;
      }
    }
    cout << lef << ' ' << rig << '\n';
  }
}
