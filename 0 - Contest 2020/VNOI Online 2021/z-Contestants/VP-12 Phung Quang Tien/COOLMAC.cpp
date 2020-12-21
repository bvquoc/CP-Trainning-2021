#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std; typedef long long ll;
const int MAXN = 10 + 2e5, N = 1e5;
const ll oo = 1 + 1e18, mod = 7 + 1e9;

int n, k = 1e9, f[MAXN], tree[MAXN];

void update (int i, int value){
  for (; i <= N; i += i & -i) tree[i] = min (tree[i], value);
}

int get (int l, int r){
  int ret = 1e9;
  while (r >= l){
    if (r - (r & -r) >= l){
      ret = min (ret, tree[r]);
      r -= r & -r;
    }
    else {
      ret = min (ret, f[r]);
      r--;
    }
  }
  return ret;
}

vector < int > g[MAXN];

int main(){
  #define TASK "COOLMAC"
  freopen(TASK".inp","r",stdin),freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++){
    int u, v; cin >> u >> v;
    g[v].push_back(u);
  }

  int t;
  cin >> t;
  for (int i = 1; i <= t; i++){
    int x; cin >> x;
    k = min (k, x);
  }

  for (int i = 0; i <= N; i++) tree[i] = f[i] = 1e9;

  f[0] = f[k - 1] = 0;

  for (int i = 1; i <= N; i++){
    for (auto j : g[i]){
      f[i] = min (f[i], get (max (1, j - 1), i - 1) + 1);
    }
    update (i, f[i]);
  }

  cout << (f[N] == 1e9 ? -1 : f[N]);

  return 0;
}
