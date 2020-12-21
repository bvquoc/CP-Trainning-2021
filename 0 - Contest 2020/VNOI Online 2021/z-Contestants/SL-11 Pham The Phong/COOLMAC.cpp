#include <bits/stdc++.h>
#define maxn 50005
#define maxk 25
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

struct jackets {
	int l, r, val;
} a[maxn];
int m, n, p[maxn], t;

bool srt(jackets a, jackets b) {
	if (a.r != b.r)
		return a.r > b.r;
	return a.l < b.l;
}

void enter() {
	cin >> m;
	fw(1, m, i) {
		cin >> a[i].l >> a[i].r;
		a[i].val = a[i].l - a[i].r;
	}
	cin >> n;
	fw(1, n, i)
		cin >> p[i];
	t = *min_element(p + 1, p + 1 + n);
}

void TsukasaSolve() {
	sort(a + 1, a + 1 + m, srt);
	//enter();
	int lft = 1e5, res = 0, MIN = oo;
	bool ok = 1;
	fw(1, m, i) {
		if (a[i].r >= lft)
			MIN = min(MIN, a[i].l);
		else if (MIN == oo) {
			ok = 0;
			break;
		} else {
			lft = MIN;
			MIN = oo;
			res++;
			if (lft <= t) break;
			i--;
		}
	}
	if (lft > t) {
		if (MIN == oo)
			ok = 0;
		else {
			lft = MIN;
			res++;
		}
	}
	if (lft > t) ok = 0;
	cout << (ok ? res : -1);
}

newbieCoder {
	effective;
  	fileIO("COOLMAC");
	enter();
	TsukasaSolve();
}