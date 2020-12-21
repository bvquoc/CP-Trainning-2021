#include <bits/stdc++.h>
#define N 500001
using namespace std;
int n,q,a[N], bac[N] = {0};
vector<int> G[N];
int tco; bool ok = false;
vector<int> vis;
void dfs(int u){
  vis[u] = 1;
  if (a[u] == 1) ok = true;
  for (int i = 0; i < G[u].size(); i++){
    int v = G[u][i];
    if (vis[v] == 0) dfs(v);
  }
}
void output_sub1(){
  bool check = false;
  for (int i = 1; i <= n; i++) if (a[i] == 1) check = true;
  if (check == false) cout << 0 << '\n';
  else cout << 1 << '\n';
}
void output_sub2(){
  bool check = false;
  for (int i = 1; i <= n; i++) if (a[i] == 1) check = true;
  if (check == false) {cout << 0 << '\n'; return;}
  int cnt = 0;
  vis.assign(n+1,0);
  vis[tco] = 1;
  for (int i = 0; i < G[tco].size(); i++){
    ok = false;
    int v = G[tco][i];
    dfs(v);
    if (ok == true) cnt++;
  }
  if (cnt <= 2) cout << 1 << '\n';
  else cout << 2 << '\n';
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("socks.inp", "r", stdin);
  freopen("socks.out", "w", stdout);
  cin >> n >> q;
  int smax = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n-1; i++) {
    int u,v; cin >> u >> v;
    bac[u]++; smax = max(smax,bac[u]);
    if (smax == 3) tco = u;
    bac[v]++; smax = max(smax,bac[v]);
    if (smax == 3) tco = v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  if (smax == 2){
    output_sub1();
    for (int i = 1; i <= q; i++){
      int k; cin >> k;
      if (a[k] == 0) a[k] = 1;
      else a[k] = 0;
      output_sub1();
    }
  }
  if (smax == 3) {
    output_sub2();
    for (int i = 1; i <= q; i++){
      int k; cin >> k;
      if (a[k] == 0) a[k] = 1;
      else a[k] = 0;
      output_sub2();
    }
  }
}
