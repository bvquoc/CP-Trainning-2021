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
  scanf("%*d"); // T = 3
  int n, q;
  scanf("%d%d", &n, &q);
  int a;
  scanf("%d", &a);
  for (int i = 1; i < n; ++i) {
    scanf("%*d");
  }
  while (q--) {
    int x, l, r;
    scanf("%d%d%d", &x, &l, &r);
    int c = r - l + 1;
    if (x < 0) {
      x = abs(x - a), c--;
    }
    if (a == 0) {
      printf("%d\n", x);
      continue;
    }
    int d = min(c, x / a);
    x -= a * d, c -= d;
    if (c % 2) {
      x = a - x;
    }
    printf("%d\n", x);
  }
  return 0;
}
