#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std; typedef long long ll;
const int MAXN = 10 + 2e5;
const ll oo = 1 + 1e18, mod = 7 + 1e9;

int n, m, l, k, a[MAXN];
long long d[MAXN][50];
#define ii pair < long long , long long >
#define iii pair < long long , ii >
vector < ii > g[MAXN];

void dijkstra(){
  for (int i = 1; i <= n; i++)
    for (int mask = 0; mask < (1 << k); mask++)
      d[i][mask] = oo;

  d[1][ a[1] ] = 0;

  priority_queue < iii , vector < iii > , greater < iii > > q;
  q.push({ 0, {1, 0} });

  while (!q.empty()){
    long long du = q.top().fi;
    int u = q.top().se.fi, mask = q.top().se.se;
    q.pop();
    if (d[u][mask] != du) continue;
    for (auto x : g[u]){
      long long v = x.fi, l = x.se;
      if (d[v][mask | a[v]] > d[u][mask] + l){
        d[v][mask | a[v]] = du + l;
        q.push( {du + l , { v, (mask | a[v]) } });
      }
    }
  }
}

int main(){
  #define TASK "DHAKA"
  freopen(TASK".inp","r",stdin),freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);

  cin >> n >> m >> l >> k;

  for (int i = 1; i <= n; i++){
    int sl; cin >> sl;
    for (int j = 1; j <= sl; j++){
      int x; cin >> x;
      a[i] |= (1 << (x - 1));
    }
  }

  for (int i = 1; i <= m; i++){
    int u, v; long long l;
    cin >> u >> v >> l;
    g[u].push_back({v, l});
    g[v].push_back({u, l});
  }

  dijkstra();

  long long ans = oo;

  for (int mask = 1; mask < (1 << k); mask++){
    if (__builtin_popcount(mask) >= l) ans = min (ans, d[n][mask]);
  }

  cout << (ans == oo ? -1 : ans);

  return 0;
}
