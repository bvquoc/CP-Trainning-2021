#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

using lli = long long;

#define bit(x, i) (x >> (i - 1) & 1ll)
#define on(x, i) (x | (1ll << (i - 1)))
#define off(x, i) (x & ~(1ll << (i - 1)))

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n, a[N], b[N];

int pw(int x, int i) {
  int b = 1;
  for (; i; i >>= 1, x = x * x % mod)
    if(i & 1) b = b * x % mod;
  return b;
}

void solve1() {
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans = ans * i % mod;
  }
  ans = ans * n % mod * (n - 1) % mod * pw(4, mod - 2) % mod;
  cout << ans << '\n';
}
void solve2() {
  int inv = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      inv += (a[i] > a[j]);
    }
  }
  inv %= mod;
  cout << inv << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  #define task "permeow"
  freopen(task".inp", "r", stdin);
  freopen(task".out", "w", stdout);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i)
    cin >> b[i];

  bool ok1 = true, ok2 = (n <= 2000);
  for (int i = 1; i <= n; ++i) {
    ok1 &= (a[i] == i && b[i] == (n - i + 1));
    ok2 &= (a[i] == b[i]);
  }
  if(ok1) solve1();
  else if(ok2) solve2();
  else {
    if(n <= 8) {
      vector<int> cur(a + 1, a + n + 1);
      vector<int> now(b + 1, b + n + 1);
      int ans = 0;
      do {
        int inv = 0;
        for (int i = 0; i < n; ++i) {
          for (int j = i + 1; j < n; ++j) {
            inv += (cur[i] > cur[j]);
          }
        }
        ans += inv;
        if(cur == now) break;
      } while(next_permutation(begin(cur), end(cur)));
      ans %= mod;
      cout << ans << '\n';
    }
  }
}
