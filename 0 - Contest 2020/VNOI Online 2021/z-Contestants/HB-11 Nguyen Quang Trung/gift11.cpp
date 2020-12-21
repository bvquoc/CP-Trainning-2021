#include <bits/stdc++.h>
#define pii pair<int,int>
#define int long long
#define fi first
#define sc second
using namespace std;
const int MOD = 998244353;
int t,n,cnt = 0; string a[2001];
pii lc[2001]; bool s2 = true;
void backtrack(string xet, int rn, int vis[2001]){
    if (rn == n){
      int sl = 0, sc = 0;
      for (int i = 0; i < (int)xet.size(); i++){
        if (i % 2 == 0) sl += xet[i] - '0';
        else sc += xet[i] - '0';
      }
      int k = sl - sc;
      if (k % 11 == 0) cnt++;
      if (cnt >= MOD) cnt -= MOD;
      return;
    }
    for (int i = 1; i <= n; i++){
      if (vis[i] == 1) continue;
      string tmp = xet + a[i];
      vis[i] = 1;
      backtrack(tmp, rn+1, vis);
      vis[i] = 0;
    }
}
void sub1(){
  for (int i = 1; i <= n; i++) {
    int vis[2001] = {0};
    vis[i] = 1;
    int cnt = 1;
    backtrack(a[i],cnt,vis);
  }
  cout << cnt << '\n';
  cnt = 0;
}
void sub2(){
  int sol  = 0, soc = 0;
  int res = 1;
  for (int i = 1; i <= n; i++) sol += lc[i].fi, soc += lc[i].sc;
  if ((sol - soc) % 11 != 0) cout << 0 << '\n';
  else for (int i = 1; i <= n; i++) res = ((res%MOD)*(i%MOD))%MOD;
  cout << res << '\n';
}
main(){
  ios_base::sync_with_stdio();
  cin.tie(0);
  cout.tie(0);
  freopen("gift11.inp", "r", stdin);
  freopen("gift11.out", "w", stdout);
  cin >> t;
  while (t--){
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      lc[i].fi = lc[i].sc = 0;
      if (a[i].size() % 2 != 0) s2 = false;
      for (int j = 0; j < a[i].size(); j++)
        if (j % 2 == 0) lc[i].fi += a[i][j] - '0';
        else lc[i].sc += a[i][j] - '0';
    }
    if (n < 12) sub1();
    else if (s2 == true) sub2();
  }
}
