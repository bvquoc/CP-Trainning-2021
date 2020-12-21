#include<bits/stdc++.h>
#define fi first
#define se second
#define bitk(mask, k) (mask & (1 << k))
using namespace std; typedef long long ll;
const int MAXN = 10 + 1e6;
const ll oo = 1 + 1e18, mod = 998244353;

int n, a[MAXN], id[MAXN];

void add (int value, long long &ret){
  vector < int > p;
  while (value){
    int t = value % 10;
    p.push_back(t);
    value /= 10;
  }
  reverse(p.begin(), p.end());
  for (auto x : p) ret = ret * 10 + 1ll * x;
}

void solve(){
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; i++) id[i] = i;

  int ans = 0;

  do{
    long long value = 0;
    for (int i = 0; i < n; i++) add(a[id[i]], value);

    if (value % 11 == 0) ans++;
  } while (next_permutation (id, id + n));

  cout << ans << '\n';
}

int main(){
  #define TASK "GIFT11"
  freopen(TASK".inp","r",stdin),freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);

  int t;
  cin >> t;
  while (t--){
    solve();
  }

  return 0;
}
