#include<bits/stdc++.h>

#define M 1000000007
#define maxn 200005

using namespace std;
typedef long long ll;

int norm(int a) {
  return a < 0 ? a + M : (a >= M ? a - M : a);
}

int mul(int a, int b) {
  return int(1ll * a * b % M);
}

int n;
int a[maxn], b[maxn];
int d[maxn], gt[maxn];

int f[maxn];

void update(int i) {
  for (; i <= n; i += (i & -i))
    f[i] ++;
}

int get(int i) {
  int ret = 0;

  for (; i; i -= (i & -i))
    ret += f[i];

  return ret;
}

int cost(int i) {
  if (i&1) return mul(i, (i - 1) / 2);
  return mul(i / 2, i - 1);
}

void run_dp() {
  d[0] = 0;
  gt[0] = 1;

  for (int i = 1; i <= n; ++i) {
    gt[i] = mul(gt[i - 1], i);
    d[i] = norm(mul(d[i - 1], i) + mul(cost(i), gt[i - 1]));
  }
}

int calc(int a[]) {
  fill(f, f + n + 1, 0);

  int ans = 0, cnt = 0;

  for (int i = 1; i <= n; ++i) {
    int x = a[i] - get(a[i]);

    ans = norm(ans + norm(mul(cost(x - 1), gt[n - i]) + mul(x - 1, d[n - i])));

    ans = norm(ans + mul(cnt, mul(x - 1, gt[n - i])));

    update(a[i]);

    cnt = norm(cnt + a[i] - get(a[i]));
  }

  return norm(ans + cnt);
}

int main() {
  #define TASK "PERMEOW"

  if (fopen(TASK".INP", "r")) {
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
  }

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;

  run_dp();

  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  for (int i = 1; i <= n; ++i)
    cin >> b[i];

  if (!prev_permutation(a + 1, a + n + 1))
    cout << calc(b);
  else
    cout << norm(calc(b) - calc(a));

  return 0;
}
