#include <bits/stdc++.h>

using namespace std;

template<typename T>
void readIn(T& x) {
  char c = getchar();
  bool neg = 0;
  for (x = 0; !isdigit(c); neg = c == '-', c = getchar());
  for (; isdigit(c); x = x * 10 + c - '0', c = getchar());
  neg ? x = -x : false;
}

template<typename T>
void writeIn(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) writeIn(x / 10);
  putchar(x % 10 + '0');
}

const int N = 1e6 + 7;

int test, n, m;
int a[N], d[N], b[N];

void solve(int L, int R) {
  d[0] = 0;
  for (int i = 1; i <= n; ++i) {
    d[i] += d[i - 1];
    a[i] += d[i];
  }
  for (int i = 1; i <= n; ++i) {
    d[i] = 0;
  }
  int64_t cnt = 0;
  int var = 0;
  for (int i = L; i <= R; ++i) {
    if (a[i] >= var) {
      cnt += a[i] - var;
      var = a[i];
    } else {
      var = a[i];
    }
  }
  writeIn(cnt);
  putchar('\n');
}

void run() {
  readIn(test);
  while (test--) {
    readIn(n);
    readIn(m);
    for (int i = 1; i <= n; ++i) {
      readIn(a[i]);
    }
    for (int i = 1; i <= m; ++i) {
      int type, L, R, k;
      readIn(type);
      readIn(L);
      readIn(R);
      if (type == 1) {
        readIn(k);
        d[L] += k;
        d[R + 1] -= k;
      } else {
        solve(L, R);
      }
    }
  }
}

int main() {
  freopen("construct.inp", "r", stdin);
  freopen("construct.out", "w", stdout);
  run();
  return 0;
}
