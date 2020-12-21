#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 2e5 + 10;

const int M = 1e9 + 7;

int n;

int a[maxn], b[maxn];

namespace subtask1 {

void run() {
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (a[i] > a[j]) ++ans;
	cout << ans << '\n';
}

}

namespace subtask2 {

ll fpow(int n, int k) {
	if (k == 0) return 1;
  ll v = fpow(n, k / 2);
  if (k % 2) return v * v % M * n % M;
  return v * v % M;
}

ll gt[maxn];

void run() {
	gt[0] = 1;
  for (int i = 1; i <= n; ++i) {
		gt[i] = gt[i - 1] * i;
		gt[i] %= M;
  }

  ll ans;
  ans = 1ll * n * (n - 1) * gt[n] % M * fpow(4, M - 2) % M;

	cout << ans << '\n';
}

}
int main(){
    #define Task "PERMEOW"
    if (fopen(Task".inp", "r")) {
      freopen(Task".inp", "r", stdin); freopen(Task".out", "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
      cin >> a[i];

    for (int i = 1; i <= n; ++i)
      cin >> b[i];

    bool flag = 1;

    for (int i = 1; i <= n; ++i)
      if (a[i] != b[i]) flag = 0;

    if (flag) {
      subtask1::run();
      return 0;
    }

    flag = 1;

    for (int i = 1; i <= n; ++i)
      if (a[i] != i) flag = 0;

    for (int i = 1; i <= n; ++i)
      if (b[i] != n - i + 1) flag = 0;

    if (flag) {
      subtask2::run();
      return 0;
    }

    cout << 0;

    return 0;
}
