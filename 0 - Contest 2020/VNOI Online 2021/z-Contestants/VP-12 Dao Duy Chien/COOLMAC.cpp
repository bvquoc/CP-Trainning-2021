#include<bits/stdc++.h>

#define maxn 100005
#define N 100000
#define oo 1000000000

using namespace std;
typedef long long ll;

int n, m;

pair < int, int > a[maxn];

int lim = 100000;
int d[maxn];

int f[maxn];

void update(int i, int v) {
  for (; i; i -= (i & -i))
    f[i] = min(f[i], v);
}

int get(int i) {
  int ret = oo;
  for (; i <= N; i += (i & -i))
    ret = min(ret, f[i]);
  return ret;
}

int main() {
  #define TASK "COOLMAC"

  if (fopen(TASK".INP", "r")) {
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
  }

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;

  for (int i = 1; i <= n; ++i)
    cin >> a[i].first >> a[i].second;

  sort(a + 1, a + n + 1, [](pair < int, int > x, pair < int, int > y){
    return x.second < y.second;
  });

  cin >> m;

  while (m--) {
    int x;
    cin >> x;
    lim = min(lim, x);
  }

  fill(d, d + n + 1, oo);
  fill(f, f + N + 1, oo);

  int ans = oo;

  for (int i = 1; i <= n; ++i) {
    int l = a[i].first, r = a[i].second;

    d[i] = min(d[i], get(l - 1) + 1);

    if (l <= lim) d[i] = 1;
    update(r, d[i]);

    if (r == N)
      ans = min(ans, d[i]);
  }

  cout << (ans == oo ? -1 : ans);

  return 0;
}
