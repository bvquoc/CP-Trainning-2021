#include<bits/stdc++.h>

#define maxn 2005
#define M 998244353

using namespace std;
typedef long long ll;

int norm(int a) {
  return a < 0 ? a + M : (a >= M ? a - M : a);
}

int mul(int a, int b) {
  return int(1ll * a * b % M);
}

int add(int &a, int b) {
  a = norm(a + b);
}

int n, m;
int a[maxn];
int b[maxn];

int d[maxn][maxn][11];
int f[maxn][maxn][11];

int gt[maxn * 2], igt[maxn * 2];

int power(int a, int b) {
  if (b == 0) return 1;

  if (b&1) return mul(power(a, b - 1), a);

  int mid = power(a, b / 2);

  return mul(mid, mid);
}

void precalc() {
  int n = 4000;
  gt[0] = 1;
  for (int i = 1; i <= n; ++i)
    gt[i] = mul(gt[i - 1], i);

  igt[n] = power(gt[n], M - 2);

  for (int i = n - 1; i >= 0; --i)
    igt[i] = mul(igt[i + 1], i + 1);
}

int C(int n, int k) {
  return mul(gt[n], mul(igt[n - k], igt[k]));
}

int calc(int n, int k) {
  if (k == 0) return n == 0;
  return C(n + k - 1, k - 1);
}

int get(int x) {
  int sum = 0, sign = -1;

  while (x) {
    sum = (sum + sign * (x % 10) + 11) % 11;
    x /= 10;
    sign = -sign;
  }

  if (sign == -1)
    return sum;

  sum = (11 - sum) % 11;
  if (sum == 0) sum = 11;
  sum = -sum;
  return sum;
}

void run_dp(int d[][maxn][11], int a[], int n) {
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      for (int c = 0; c < 11; ++c)
        d[i][j][c] = 0;

  d[0][0][0] = 1;

  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      for (int c = 0; c < 11; ++c) {
        add(d[i][j][c], d[i - 1][j][(c - a[i] + 11) % 11]);
        if (j)
          add(d[i][j][c], d[i - 1][j - 1][(c + a[i]) % 11]);
      }
}

void solve() {
  int nnum;

  n = 0;
  m = 0;

  cin >> nnum;

  while (nnum--) {
    int x;

    cin >> x;

    int res = get(x);

    if (res >= 0)
      a[++n] = res;
    else
      b[++m] = abs(res) % M;
  }

  run_dp(d, a, n);
  run_dp(f, b, m);

  int ans = 0;

  for (int c = 0; c < 11; ++c) {
    int ic = (11 - c) % 11;

    int res = mul(f[m][(m + 1) / 2][ic], mul(gt[(m + 1) / 2], gt[m / 2]));

    int cnt = 0;

    for (int i = 0; i <= n; ++i) {
      int cur = mul(d[n][i][c], mul(gt[i], gt[n - i]));

      cur = mul(cur, calc(i, (m + 2) / 2));
      cur = mul(cur, calc(n - i, (m + 1) / 2));

      cnt = norm(cnt + cur);
    }

    ans = norm(ans + mul(cnt, res));
  }

  cout << ans << '\n';
}

int main() {
  #define TASK "GIFT11"

  if (fopen(TASK".INP", "r")) {
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
  }

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  precalc();

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
