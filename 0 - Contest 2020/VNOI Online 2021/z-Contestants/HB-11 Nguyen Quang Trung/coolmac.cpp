#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define N 100001
using namespace std;
int m,n, b[N],cnt = 0;
pii a[N];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("coolmac.inp", "r", stdin);
  freopen("coolmac.out", "w", stdout);
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> a[i].fi >> a[i].sc;
  cin >> n;
  int ctro1 = 1, ctro2 = 999999999;
  for (int i = 1; i <= n; i++) {cin >> b[i]; ctro2 = min(ctro2, b[i]);}
  sort(a+1, a+1+m);
  int smax = 0; bool ok = true;
  while (ctro2 <= 100000){
    if (ctro1 > m) break;
    while (a[ctro1].fi <= ctro2){
      smax = max(smax,a[ctro1].sc);
      ctro1++;
    }
    ctro1--;
    if (smax == 0) {ok = false; break;}
    ctro2 = smax+1;
    smax = 0;
    cnt++;
  }
  if (ok == false) cout << -1; else cout << cnt;
}
