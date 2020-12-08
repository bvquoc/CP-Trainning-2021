#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int n, m;
int u[N], v[N];
char s[N], c[N], t[1003][1003];

template<typename T>
void read(T& x) {
  char c = getchar();
  for (x = 0; !isdigit(c); c = getchar());
  for (; isdigit(c); x = x * 10 + c - '0', c = getchar());
}

template<typename T>
void write(T x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}

char read_char() {
  char e = getchar();
  for (; (e != 'C') && (e != 'Q') && (e != 'U'); e = getchar());
  return e;
}

void sub1() {
  for (int i = 1; i <= n; ++i) {
    t[0][i] = s[i];
  }
  for (int i = 1; i <= m; ++i) {
    if (c[i] == 'C') {
      for (int j = 1; j <= n; ++j) {
        t[i][j] = t[i - 1][j];
      }
      if (t[i][u[i]] == '(') {
        t[i][u[i]] = ')';
      } else {
        t[i][u[i]] = '(';
      }
    } else if (c[i] == 'Q') {
      for (int j = 1; j <= n; ++j) {
        t[i][j] = t[i - 1][j];
      }
      int cur = 0;
      int ans = 0;
      for (int j = u[i]; j <= v[i]; ++j) {
        if (t[i][j] == '(') {
          cur++;
        } else {
          cur--;
        }
        if (cur < 0) {
          ++ans;
          cur = 0;
        }
      }
      ans += cur;
      write(ans);
      putchar('\n');
    } else {
      for (int j = 1; j <= n; ++j) {
        t[i][j] = t[u[i] - 1][j];
      }
    }
  }
}

int lzmin[N << 2], lzmax[N << 2], f[N];
pair<int, int> stmax[N << 2], stmin[N << 2];

void build(int k, int l, int r) {
  if (l == r) {
    stmin[k] = {f[l], l};
    stmax[k] = {f[l], l};
    return;
  }
  int mid = (l + r) / 2;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  stmin[k] = min(stmin[k << 1], stmin[k << 1 | 1]);
  stmax[k] = max(stmax[k << 1], stmax[k << 1 | 1]);
}

void downmin(int k) {
  if (lzmin[k]) {
    stmin[k << 1].first += lzmin[k];
    stmin[k << 1 | 1].first += lzmin[k];
    lzmin[k << 1] += lzmin[k];
    lzmin[k << 1 | 1] += lzmin[k];
    lzmin[k] = 0;
  }
}

void downmax(int k) {
  if (lzmax[k]) {
    stmax[k << 1].first += lzmax[k];
    stmax[k << 1 | 1].first += lzmax[k];
    lzmax[k << 1] += lzmax[k];
    lzmax[k << 1 | 1] += lzmax[k];
    lzmax[k] = 0;
  }
}

void upmin(int k, int l, int r, int u, int v, int val) {
  if (u > r || v < l) return;
  if (u <= l && v >= r) {
    stmin[k].first += val;
    lzmin[k] += val;
    return;
  }
  downmin(k);
  int mid = (l + r) / 2;
  upmin(k << 1, l, mid, u, v, val);
  upmin(k << 1 | 1, mid + 1, r, u, v, val);
  stmin[k] = min(stmin[k << 1], stmin[k << 1 | 1]);
}

pair<int, int> getmin(int k, int l, int r, int u, int v) {
  if (u > r || v < l) return make_pair(1e9, 1e9);
  if (u <= l && v >= r) return stmin[k];
  downmin(k);
  int mid = (l + r) / 2;
  return min(getmin(k << 1, l, mid, u, v), getmin(k << 1 | 1, mid + 1, r, u, v));
}

void upmax(int k, int l, int r, int u, int v, int val) {
  if (u > r || v < l) return;
  if (u <= l && v >= r) {
    stmax[k].first += val;
    lzmax[k] += val;
    return;
  }
  downmax(k);
  int mid = (l + r) / 2;
  upmax(k << 1, l, mid, u, v, val);
  upmax(k << 1 | 1, mid + 1, r, u, v, val);
  stmax[k] = max(stmax[k << 1], stmax[k << 1 | 1]);
}

pair<int, int> getmax(int k, int l, int r, int u, int v) {
  if (u > r || v < l) return make_pair(-1e9, -1e9);
  if (u <= l && v >= r) return stmax[k];
  downmax(k);
  int mid = (l + r) / 2;
  return max(getmax(k << 1, l, mid, u, v), getmax(k << 1 | 1, mid + 1, r, u, v));
}

void sub2() {
  f[0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '(') {
      f[i] = f[i - 1] + 1;
    } else {
      f[i] = f[i - 1] - 1;
    }
  }
  build(1, 1, n);
  for (int i = 1; i <= m; ++i) {
    if (c[i] == 'C') {
      if (s[u[i]] == ')') {
        s[u[i]] = '(';
        upmin(1, 1, n, u[i], n, +2);
        upmax(1, 1, n, u[i], n, +2);
      } else {
        s[u[i]] = ')';
        upmin(1, 1, n, u[i], n, -2);
        upmax(1, 1, n, u[i], n, -2);
      }
    } else if (c[i] == 'Q') {
      int ans = 0, t1, t2;
      pair<int, int> f1 = getmin(1, 1, n, u[i], v[i]);
      if (u[i] == 1) t1 = 0;
      else t1 = getmax(1, 1, n, u[i] - 1, u[i] - 1).first;
      if (f1.first <= t1) ans += abs(f1.first - t1);
      t2 = getmin(1, 1, n, v[i], v[i]).first;
      if (f1.first <= t1) ans += abs(t2 - f1.first);
      else ans += t2;
      write(ans);
      putchar('\n');
    }
  }
}

void run() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    c[i] = read_char();
    if (c[i] == 'C') {
      read(u[i]);
    } else if (c[i] == 'Q') {
      read(u[i]);
      read(v[i]);
    } else {
      read(u[i]);
    }
  }
  if (m <= 1000 && n <= 1000) {
    sub1();
  } else {
    sub2();
  }
}

int main() {
  freopen("fixstr.inp", "r", stdin);
  freopen("fixstr.out", "w", stdout);
  run();
  return 0;
}
