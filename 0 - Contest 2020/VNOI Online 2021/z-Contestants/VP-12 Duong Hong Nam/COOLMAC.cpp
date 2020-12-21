#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 2e5 + 10;

int n, m;

#define ii pair<int, int>
#define l first
#define r second

ii a[maxn];

int main(){
    #define Task "COOLMAC"
    if (fopen(Task".inp", "r")) {
      freopen(Task".inp", "r", stdin); freopen(Task".out", "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
      cin >> a[i].l >> a[i].r;
    }

    sort(a + 1, a + n + 1);

    cin >> m;

    int Min = 1e9;

    for (int i = 1; i <= m; ++i) {
      int t; cin >> t;
      Min = min(Min, t);
    }

    int pos = Min;
    int ans = 0, i = 0;
    while (1) {
      int np = pos;
      while (i + 1 <= n && a[i + 1].l <= pos) {
        ++i; np = max(np, a[i].r);
      }
      if (np == pos) break;
      pos = np; ++ans;
    }

    if (pos < 100000) cout << -1;
    else
      cout << ans;

    return 0;
}
