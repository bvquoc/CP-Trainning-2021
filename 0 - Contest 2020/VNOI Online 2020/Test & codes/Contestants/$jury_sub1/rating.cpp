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
  scanf("%*d"); // T = 1, co lam thi moi co an
  int n, q;
  scanf("%d%d", &n, &q);
  vector<int> a(n);
  for (int& x : a) {
    scanf("%d", &x);
  }
  while (q--) {
    int x, l, r;
    scanf("%d%d%d", &x, &l, &r), l--;
    for (int i = l; i < r; ++i) {
      x = abs(x - a[i]);
    }
    printf("%d\n", x);
  }
  return 0;
}
