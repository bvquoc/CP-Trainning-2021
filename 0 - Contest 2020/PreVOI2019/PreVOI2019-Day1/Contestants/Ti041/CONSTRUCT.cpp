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
typedef long long ll;
typedef pair<ll, int> ii;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 1e5 + 5;
int n, m, leBound[N];
ll a[N], del[N];
void proc() {
	cin >> n >> m;
	fw (i, 0, n) cin >> a[i];
	//MN * logN solution: Sort segment aL to aR, and then simulate the cuts.
	while (m--) {
		int type, l, r, k;
		cin >> type >> l >> r;
		l--, r--;
		if (type == 1) {
			cin >> k;
			fw (i, l, r + 1) a[i] += k;
		} else {
			vector<ii> v;
			fw (i, l, r + 1) v.pb(ii(a[i], i));
			sort(v.begin(), v.end());
			set<int> s;
			leBound[r] = l;
			del[r] = 0;
			s.insert(r);
			ll ans = 0;
			fw (i, 0, v.size()) {
				int pos = v[i].se;
				ll val = v[i].fi;
				//Delete position i.
				int ri = *s.lower_bound(pos);
				s.erase(ri);
				int le = leBound[ri];
				ans += val - del[ri];
				if (le <= pos - 1) {
					s.insert(pos - 1);
					leBound[pos - 1] = le;
					del[pos - 1] = val;
				}
				if (pos + 1 <= ri) {
					s.insert(ri);
					leBound[ri] = pos + 1;
					del[ri] = val;
				}
			}
			cout << ans << "\n";
		}
	}
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#else
	inout("construct", "inp", "out");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) proc();
	return 0;
}

