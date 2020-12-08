#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int q, x[55], t[55];
int b[20], f[N];
int a[] = {0, 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000, 0, 0};

void sub1() {
  for (int e = 1; e <= q; ++e) {
    for (int w = 1; w <= t[e]; ++w) {
      f[w] = 1e9;
    }
    f[0] = 0;
    a[16] = x[e];
    for (int w = 1; w <= t[e]; ++w) {
      for (int i = 1; i <= 16; ++i) {
        if (w >= a[i]) {
          f[w] = min(f[w], f[w - a[i]] + 1);
        }
      }
    }
    printf("%d\n", f[t[e]]);
  }
}

void run() {
  int xmax = 0, tmax = 0;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%d %d", &x[i], &t[i]);
    xmax = max(xmax, x[i]);
    tmax = max(tmax, t[i]);
  }
  sub1();
  return;
  if (xmax <= 20 && tmax <= 20) {
    sub1();
  }
}

int main() {
  freopen("oddcoin.inp", "r", stdin);
  freopen("oddcoin.out", "w", stdout);
  run();
  return 0;
}
