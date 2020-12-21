#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std; typedef long long ll;
const int MAXN = 10 + 5e5;
const ll oo = 1 + 1e18, mod = 7 + 1e9;

int n, q, color[MAXN], cnt[MAXN], deg[MAXN], mx = 0;
vector < int > g[MAXN];

namespace subtask1{
  int d[2];
  void solve(){
    for (int i = 1; i <= n; i++) d[color[i]]++;

    if (d[0] == n) cout << 0 << '\n';
    else cout << 1 << '\n';

    while (q--){
      int i; cin >> i;
      d[color[i]]--;
      color[i] = 1 - color[i];
      d[color[i]]++;
      if (d[0] == n) cout << 0 << '\n';
      else cout << 1 << '\n';
    }
  }
}

namespace subtask2{
  int d[3][2], sz[3], id[MAXN];

  void dfs(int u, int du, int r){
    sz[r]++; id[u] = r;
    for (auto v : g[u]){
      if (v != du) dfs(v, u, r);
    }
  }

  void solve(){
    int root;
    for (int i = 1; i <= n; i++) if (deg[i] == 3) root = i;
    for (int i = 0; i < 3; i++){
      dfs(g[root][i], root, i);
    }
    for (int i = 1; i <= n; i++){
      if (i != root)
        d[id[i]][color[i]]++;
    }

    int ok = 0;
    for (int c = 0; c < 3; c++){
      ok += (d[c][0] == sz[c]);
    }

    if (ok == 3 && color[root] == 0) cout << 0 << "\n";
    else if (ok == 0) cout << 2 << '\n';
    else cout << 1 << '\n';

    while (q--){
      int i; cin >> i;
      int pos = id[i];
      if (i != root) d[pos][color[i]]--;
      color[i] = 1 - color[i];
      if (i != root) d[pos][color[i]]++;
      int ok = 0;
      for (int c = 0; c < 3; c++){
        ok += (d[c][0] == sz[c]);
      }
      if (ok == 3 && color[root] == 0) cout << 0 << "\n";
      else if (ok == 0) cout << 2 << '\n';
      else cout << 1 << '\n';
    }
  }
}

namespace subtask3{
  int qr[MAXN], dp[MAXN][2][2];

  void dfs (int u, int du){
    vector < int > child;
    for (auto v : g[u]){
      if (v != du){
        child.push_back(v);
        dfs(v, u);
      }
    }
    if (child.size() == 0){
      dp[u][1][1] = 1;
      if (color[u] == 0) dp[u][0][0] = 0;
      else dp[u][0][0] = dp[u][0][1] = 1e9;
      return;
    }
    for (auto v : child){
      dp[u][1][1] = min (dp[v][0][0] + 1, dp[u][1][1]);
      dp[u][1][1] = min (dp[v][0][1] + 1, dp[u][1][1]);
      dp[u][1][1] = min (dp[u][1][1], dp[v][1][0]);
      dp[u][1][1] = min (dp[u][1][1], dp[v][1][1]);
      if (color[u] == 0){
        dp[u][1][0] = min (dp[u][1][0], dp[v][0][0]);
        dp[u][1][0] = min (dp[u][1][0], dp[v][0][1]);
      }
      else {
        dp[u][1][0] = 1e9;
      }
    }
  }

  void solve(){
    for (int i = 1; i <= q; i++) cin >> qr[i];
    for (int k = 0; k <= q; k++){
      int i = qr[k];
      color[i] = 1 - color[i];
      dfs(1, 0);
    //  for (int i = 1; i <= n; i++) cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
      cout << min ({dp[1][0][1], dp[1][0][0], dp[1][1][0], dp[1][1][1]}) << '\n';
    }
  }
}

int main(){
  #define TASK "SOCKS"
  freopen(TASK".inp","r",stdin),freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++){
    cin >> color[i];
  }

  for (int i = 1; i < n; i++){
    int u, v; cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
    deg[u]++, deg[v]++;
    cnt[deg[u]]++, cnt[deg[v]]++;
    mx = max ({mx, deg[u], deg[v]});
  }

  if (mx <= 2){
    subtask1::solve();
  }

  else if (mx == 3 && cnt[3] == 1){
    subtask2::solve();
  }

  else subtask3::solve();

  return 0;
}
