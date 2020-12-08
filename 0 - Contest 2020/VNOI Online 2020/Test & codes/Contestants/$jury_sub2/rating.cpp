#include <bits/stdc++.h>

using namespace std;

int main() {
#if ONLINE_JUDGE || THEMIS
  freopen("rating.inp", "r", stdin);
  freopen("rating.out", "w", stdout);
#else
  freopen("local.in", "r", stdin);
  freopen("local.out", "w", stdout);
#endif
  scanf("%*d"); // T = 2
  int n, q;
  scanf("%d%d", &n, &q);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    a[i] += a[i - 1];
  }
  while (q--) {
    int x, l, r;
    scanf("%d%d%d", &x, &l, &r);
    printf("%d\n", x - (a[r] - a[l - 1]));
  }
  return 0;
}
