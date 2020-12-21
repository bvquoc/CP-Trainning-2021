#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std; typedef long long ll;
const int MAXN = 10 + 5e5;
const ll oo = 1 + 1e18, mod = 7 + 1e9;

int n, m, k; string s;
vector < int > g[MAXN];

namespace subtask1{
  int pre[MAXN];

  bool check (int len, int &l, int &r){
    for (int i = 1; i + len - 1 <= n; i++){
      if (pre[i + len - 1] - pre[i - 1] + k >= len){
        l = i, r = i + len - 1;
        return 1;
      }
    }
    return 0;
  }

  void solve(){
    for (int i = 1; i <= n; i++){
      pre[i] = pre[i - 1] + (s[i] == '1');
    }

    int l, r;

    int lo = 0, hi = n;
    while (lo < hi){
      int mid = (lo + hi + 1) / 2;
      if (check (mid, l, r))
        lo = mid;
      else
        hi = mid - 1;
    }
    if (lo == 0) cout << -1 << '\n';
    else cout << l << ' ' << r << '\n';
  }
}

namespace subtask3{
  void solve(){

  }
}

int main(){
  #define TASK "DECOR"
  freopen(TASK".inp","r",stdin),freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);

  cin >> n >> m >> k >> s; s = ' ' + s;

  for (int i = 1; i <= m; i++){
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }

  if (m == 0){
    subtask1::solve();
  }

  else subtask3::solve();

  return 0;
}
