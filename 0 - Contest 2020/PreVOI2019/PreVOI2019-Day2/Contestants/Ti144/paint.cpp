#include <bits/stdc++.h>

using namespace std;

template<typename T>
void read(T& x) {
  char c = getchar();
  for (x = 0; !isdigit(c); c = getchar());
  for (; isdigit(c); x = x * 10 + c - '0', c = getchar());
}

char read_char() {
  char c = getchar();
  for (; !(c >= 'a' && c <= 'z'); c = getchar());
  return c;
}

const int N = 1e6 + 7;

int n;
char ans[N];

void sub1() {
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    int t;
    char a, b, c;
    read(t);
    if (t == 1) {
      ans[++cnt] = read_char();
    } else {
      a = read_char();
      b = read_char();
      if (a == b) continue;
      for (int j = 1; j <= cnt; ++j) {
        if (ans[j] == a) {
          ans[j] = b;
        }
      }
    }
  }
  for (int i = 1; i <= cnt; ++i) {
    putchar(ans[i]);
  }
}


int q[N];
char x[N], y[N], mem[30];
void sub2() {
  for (int i = 0; i <= 28; ++i) {
    mem[i] = '*';
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    read(q[i]);
    if (q[i] == 1) {
      x[i] = read_char();
      ++cnt;
    } else {
      x[i] = read_char();
      y[i] = read_char();
    }
  }
  int np = cnt;
  for (int i = n; i; --i) {
    if (q[i] == 1) {
      if (mem[x[i] - 'a'] == '*') {
        ans[cnt] = x[i];
      } else {
        ans[cnt] = mem[x[i] - 'a'];
      }
      --cnt;
    } else {
      if (mem[y[i] - 'a'] == '*') {
        mem[x[i] - 'a'] = y[i];
      } else {
        mem[x[i] - 'a'] = mem[y[i] - 'a'];
      }
    }
  }
  for (int i = 1; i <= np; ++i) {
    putchar(ans[i]);
  }
}

void run() {
  read(n);
  if (n <= 10000) {
    sub1();
  } else {
    sub2();
  }
}

int main() {
  freopen("paint.inp", "r", stdin);
  freopen("paint.out", "w", stdout);
  run();
  return 0;
}
