#include <bits/stdc++.h>

using namespace std;

const int mod = 1000003;
const int N = 4e5 + 7;

int n, m, a[N], x[N], d[N], mem[N];

stack<int> s;

void sub1() {
  for (int i = 1, j = 1; i <= 2 * n; i += 2, ++j) {
    x[i] = j;
    x[i + 1] = j;
  }
  int ans = 0;
  int cnt = 0;
  do {
    ++cnt;
    if (x[1] != 1) break;
    while (!s.empty()) s.pop();
    s.push(1);
    mem[1] = cnt;
    mem[0] = cnt;
    d[1] = a[1];
    for (int i = 2; i <= 2 * n; ++i) {
      if (mem[x[i] - 1] != cnt) {
        goto NEX;
      }
      if (mem[x[i]] == cnt) {
        if (s.top() == x[i] && a[i] - d[x[i]] <= m) {
          s.pop();
          continue;
        } else {
          goto NEX;
        }
      }
      if (mem[x[i]] != cnt) {
        mem[x[i]] = cnt;
        s.push(x[i]);
        d[x[i]] = a[i];
      }
    }
    ++ans;
    NEX:;
  } while (next_permutation(x + 1, x + 1 + 2 * n));
  printf("%d", ans);
}

void run() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= 2 * n; ++i) {
    scanf("%d", &a[i]);
  }
  sub1();
}

int main() {
  freopen("mine.inp", "r", stdin);
  freopen("mine.out", "w", stdout);
  run();
  return 0;
}
