#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std; typedef long long ll;
const int MAXN = 10 + 1e6;
const ll oo = 1 + 1e18, mod = 7 + 1e9;

int n, a[MAXN], b[MAXN];

namespace subtask1 {
  void solve(){
    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (a[i] > a[j]) ++ans;
    cout << ans << '\n';
  }
}

namespace subtask2{
  long long gt[MAXN];

  long long Pow (int n, int k) {
    if (k == 0) return 1;
    long long v = Pow(n, k / 2);
    if (k % 2) return v * v % mod * n % mod;
    return v * v % mod;
  }

  void solve (){
    gt[0] = 1;
    for (int i = 1; i <= n; ++i){
      gt[i] = gt[i - 1] * i;
      gt[i] %= mod;
    }

    long long ans = 1ll * n * (n - 1) * gt[n] % mod * Pow(4, mod - 2) % mod;

    cout << ans << '\n';
  }
}

int main(){
  #define TASK "PERMEOW"
  freopen(TASK".inp","r",stdin),freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];

  int ok = 0;
  for (int i = 1; i <= n; i++){
    if (a[i] != b[i]){
      ok = 1; break;
    }
  }

  if (!ok) subtask1::solve();
  else subtask2::solve();


  return 0;
}
