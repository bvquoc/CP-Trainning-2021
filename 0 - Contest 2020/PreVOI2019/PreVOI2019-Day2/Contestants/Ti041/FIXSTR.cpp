#include <bits/stdc++.h>
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 1e6 + 5;
string s;
int n, q, val[N], preVal[N];
struct BIT {
	int t[N], n;
	void init(int _n) {
		n = _n;
		memset(t, 0, sizeof t);
	}
	void upd(int pos, int val) {
		pos++;
		for (; pos <= n; pos += (pos & (-pos))) t[pos] += val;
	}
	int get1(int pos) {
		pos++;
		int ans = 0;
		for (; pos > 0; pos -= (pos & (-pos))) ans += t[pos];
		return ans;
	}
	int get(int l, int r) {
		return get1(r) - (l ? get1(l - 1) : 0);
	}
} bit;
class SegTree {
private:
	int t[N << 2], lazy[N << 2];
	void build(int l, int r, int x) {
		if (l == r) {
			t[x] = preVal[l];
			lazy[x] = 0;
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, x << 1), build(m + 1, r, x << 1 | 1);
		t[x] = min(t[x << 1], t[x << 1 | 1]);
		lazy[x] = 0;
	}
	void push(int l, int r, int x) {
		if (lazy[x]) {
			t[x] += lazy[x];
			lazy[x << 1] += lazy[x];
			lazy[x << 1 | 1] += lazy[x];
			lazy[x] = 0;
		}
	}
	void upd(int l, int r, int s, int e, int x, int val) {
		push(l, r, x);
		if (l > e || r < s) return;
		if (s <= l && r <= e) {
			lazy[x] += val;
			push(l, r, x);
			return;
		}
		int m = (l + r) >> 1;
		upd(l, m, s, e, x << 1, val), upd(m + 1, r, s, e, x << 1 | 1, val);
		t[x] = min(t[x << 1], t[x << 1 | 1]);
	}
	int get(int l, int r, int s, int e, int x) {
		push(l, r, x);
		if (l > e || r < s) return inf;
		if (s <= l && r <= e) return t[x];
		int m = (l + r) >> 1;
		return min(get(l, m, s, e, x << 1), get(m + 1, r, s, e, x << 1 | 1));
	}
public:
	int n;
	void init(int _n) {
		n = _n;
		build(0, n - 1, 1);
	}
	void upd(int l, int r, int val) {
		upd(0, n - 1, l, r, 1, val);
	}
	int get(int l, int r) {
		return get(0, n - 1, l, r, 1);
	}
} st;
typedef pair<int, int> ii;
vector<ii> segs[N];
vector<ii> ogSegs;
char type[N];
int l[N], r[N], ans[N];
void solve(int le, int ri) {
	//Segment contains no U. After solving revert the state.
	fw (i, le, ri + 1) {
		if (type[i] == 'C') {
			int change = 2;
			if (val[l[i]] == 1) change = -2;
			val[l[i]] = -val[l[i]];
			bit.upd(l[i], change);
			st.upd(l[i], n - 1, change);
		} else {
			int atL = 0;
			if (l[i]) atL = st.get(l[i] - 1, l[i] - 1);
			int mn = min(0, st.get(l[i], r[i]) - atL);
			int sum = bit.get(l[i], r[i]);
			ans[i] = abs(mn) + abs(abs(mn) + sum);
//			cout << "mn = " << mn << " sum = " << sum << "\n";
		}
		fa (j, segs[i]) {
			solve(j.fi, j.se);
		}
	}
	bw (i, ri + 1, le) {
		if (type[i] == 'C') {
			int change = 2;
			if (val[l[i]] == 1) change = -2;
			val[l[i]] = -val[l[i]];
			bit.upd(l[i], change);
			st.upd(l[i], n - 1, change);
		}
	}
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	out("ans1.out");
	#else
	inout("FIXSTR", "INP", "OUT");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	n = s.length();
	fw (i, 0, n) {
		if (s[i] == '(') val[i] = 1;
		else val[i] = -1;
		preVal[i] = (i ? preVal[i - 1] : 0) + val[i];
	}
	st.init(n);
	bit.init(n);
	fw (i, 0, n) bit.upd(i, val[i]);
	cin >> q;
	fw (i, 0, q) {
		cin >> type[i] >> l[i];
		l[i]--;
		if (type[i] == 'Q') {
			cin >> r[i];
			r[i]--;
		}
		if (type[i] == 'U') {
			l[i]--;
			if (l[i] >= 0 && type[l[i]] == 'U') l[i] = l[l[i]];
		}
	}
	int nxtU = q;
	bw (i, q, 0) {
		if (type[i] == 'U') {
			if (i + 1 <= nxtU - 1) {
				if (l[i] >= 0) segs[l[i]].pb(ii(i + 1, nxtU - 1));
				else ogSegs.pb(ii(i + 1, nxtU - 1));
			}
			nxtU = i;
		}
	}
	if (nxtU >= 1) ogSegs.pb(ii(0, nxtU - 1));
	fa (i, ogSegs) solve(i.fi, i.se);
	fw (i, 0, q) if (type[i] == 'Q') cout << ans[i] << "\n";
	return 0;
}
/*
((()))
10
C 1
Q 2 5
C 5
Q 1 6
U 3
C 4
Q 3 6
U 5
C 1
Q 1 5
*/
