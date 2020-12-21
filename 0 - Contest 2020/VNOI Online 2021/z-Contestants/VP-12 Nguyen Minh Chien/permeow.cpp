///link:
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define all(x) x.begin(), x.end()
#define ll long long
const int maxn = 1 + 1e6;
const ll mod = 1e9 + 7;
const int inf = (1 << 30);

int n, a[maxn], b[maxn];
bool ok1 = 1, ok2 = 1;

namespace sub1 {

void run() {
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i] > a[j]) ++ans;
	cout << ans << '\n';
}

}

namespace sub2 {

ll Pow (int n, int k) {
	if (k == 0) return 1;
  ll v = Pow(n, k / 2);
  if (k % 2) return v * v % mod * n % mod;
  return v * v % mod;
}

ll gt[maxn];

void run() {
	gt[0] = 1;
  for (int i = 1; i <= n; ++i) {
		gt[i] = gt[i - 1] * i;
		gt[i] %= mod;
  }

  ll ans;
  ans = 1ll * n * (n - 1) * gt[n] % mod * Pow(4, mod - 2) % mod;

	cout << ans << '\n';
}

}

int main()
{
	#define Task "permeow"
	if (fopen(Task".inp", "r"))
	freopen(Task".inp", "r", stdin), freopen(Task".out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] != i + 1) ok2 = 0;
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		if (a[i] != b[i]) {
			ok1 = 0;
		}
		if (b[i] != n - i) ok2 = 0;
	}

	if (ok1) {
		sub1::run();
	}
	else if (ok2) {
    sub2::run();
	}

   return 0;
}
