#include <bits/stdc++.h>
#define maxn 500005
#define maxm 30005
#define fw(a, b, c) for (ll c = a; c <= b; c++)
#define bw(a, b, c) for (ll c = a; c >= b; c--)
#define fileIO(TASK)                  \
	freopen(TASK ".inp", "r", stdin); \
	freopen(TASK ".out", "w", stdout);
#define effective            \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
#define newbieCoder main()
#define timing cerr << "Executed in " << clock() * 1000 / CLOCKS_PER_SEC << " ms";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll oo = 1e9 + 7;
typedef string str;

str s;
int n, m, k, T = 0;
pii d[maxn];

void convert(str s) {
	int l = s.length() - 1, i = 0;
	while (i <= l) {
		int cnt = 0, r = i;
		if (s[i] == '0') {
			while (s[i] == '0') {
				cnt--;
				i++;
			}
		} else {
			while (s[i] == '1') {
				cnt++;
				i++;
			}
		}
		d[++T] = pii(r + 1, cnt);
	}
}

namespace sub1 {
	void solve() {
		convert(s);
		pii res = {1, 0};
		fw(1, T, i)
			if (res.second < d[i].second)
				res = d[i];
		cout << res.first << ' ' << res.second;
	}
}

namespace sub2 {
	void solve() {
		pii res = {1, 0};
		convert(s);
		fw(1, T, i) {
			if (d[i].second > 0) {
				int K = k, cnt = d[i].second;
				fw(i + 1, T, j) {
					if (d[j].second > 0)
						continue;
					if (d[j].second + K >= 0) {
						K += d[j].second;
						cnt += abs(d[j].second);
					} else if (d[j].second + K < 0) {
						cnt += K;
						K += d[j].second;
					}
					if (K <= 0)
						break;
					if (j == T && K > 0)
						cnt += min(abs(d[j].second), K);
				}
				if (res.second < cnt)
					res = pii(d[i].first, cnt);
			}
			//cout << d[i] << ' ';
		}
		cout << res.first << ' ' << res.second;
	}
}

newbieCoder {
	effective;
  	fileIO("DECOR");
	cin >> n >> m >> k >> s;
	if (m == 0 && k == 0)
		sub1::solve();
	else if (m == 0)
		sub2::solve();
}