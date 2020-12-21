#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

const int N = 5e5 + 5;
int n, q;
int a[N];
vector<int> ad[N];
int pd[N][22], dep[N], tin[N], tout[N];

void dfs(int u, int par) {
  static int id = 0;
  tin[u] = ++id;
  for (int i = 1; i <= 20; ++i)
    pd[u][i] = pd[pd[u][i - 1]][i - 1];
  for (int &v : ad[u]) {
    if(v == par) continue;
    pd[v][0] = u;
    dep[v] = dep[u] + 1;
    dfs(v, u);
  }
  tout[u] = id;
}
int lca(int u, int v) {
  if(dep[u] < dep[v]) swap(u, v);
  int diff = dep[u] - dep[v];
  for (int i = 20; i >= 0; --i)
    if(diff >> i & 1)
      u = pd[u][i];
  if(u == v) return u;
  for (int i = 20; i >= 0; --i)
    if(pd[u][i] != pd[v][i])
      u = pd[u][i], v = pd[v][i];
  return pd[u][0];
}
bool anc(int u, int v) {
  return tin[u] <= tin[v] && tout[v] <= tout[u];
}
bool cmp(int u, int v) {
  return make_pair(tin[u], tout[u]) < make_pair(tin[v], tout[v]);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  #define task "socks"
  freopen(task".inp", "r", stdin);
  freopen(task".out", "w", stdout);

  cin >> n >> q;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    ad[u].pb(v); ad[v].pb(u);
  }

  dfs(1, 0);

  if(n <= 1000 && q <= 1000) {
    for (int _ = 0; _ <= q; ++_) {
      if(_) {
        int x; cin >> x;
        a[x] ^= 1;
      }
      vector<int> nodes;
      for (int i = 1; i <= n; ++i) {
        if(a[i]) nodes.pb(i);
      }
      sort(begin(nodes), end(nodes), cmp);
      int uu = nodes.size();
      for (int i = 1; i < uu; ++i) {
        nodes.pb(lca(nodes[i], nodes[i - 1]));
      }
      sort(begin(nodes), end(nodes));
      nodes.erase(unique(begin(nodes), end(nodes)), end(nodes));
      sort(begin(nodes), end(nodes), cmp);
      //for (int &v : nodes) cerr << v << ' '; cerr << '\n';
      vector<int> deg(n + 5, 0);
      stack<int> st;
      for (int &v : nodes) {
        while(st.size() && !anc(st.top(), v)) st.pop();
        if(st.size()) {
          deg[v]++;
          deg[st.top()]++;
        }
        st.push(v);
      }
      int res = 0;
      for (int i = 1; i <= n; ++i) res += (deg[i] == 1);
      cout << (res + 1) / 2 << '\n';
    }
  } else {
    bool ok = 1;
    for (int i = 1; i <= n; ++i) {
      if(ad[i].size() > 1) {
        ok = false;
        break;
      }
    }
    if(ok) {
      int tot = 0;
      for (int i = 1; i <= n; ++i) tot += a[i];
      if(tot >= 2) cout << 1 << '\n';
      else cout << 0 << '\n';
      while(q--) {
        int x; cin >> x;
        if(a[x]) {
          tot--;
        } else tot++;
        a[x] ^= 1;
        if(tot >= 2) cout << 1 << '\n';
        else cout << 0 << '\n';
      }
    }
  }
}
