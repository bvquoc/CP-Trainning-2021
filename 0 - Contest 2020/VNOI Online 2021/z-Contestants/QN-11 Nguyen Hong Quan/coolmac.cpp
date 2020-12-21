#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const ll nmax = 100001;

ll n, m, lmin = nmax - 1;

struct Coat {
	ll l, r;
} a[nmax];


int main() {
	if (fopen("coolmac.inp", "r")) {
		freopen("coolmac.inp", "r", stdin);
		freopen("coolmac.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (ll i = 1; i <= n; ++ i) {
		cin >> a[i].l >> a[i].r;
	}
	cin >> m;
	for (ll i = 1; i <= m; ++ i) {
		ll temp; cin >> temp;
		lmin = min(lmin, temp);
	}
    for (ll i = 1; i <= n; ++ i) {
		a[i].l = max(a[i].l, lmin);
    }
    sort(a + 1, a + n + 1, [](const Coat& lhs, const Coat& rhs) -> bool {
		if (lhs.l == rhs.l) return lhs.r > rhs.r;
		return lhs.l < rhs.l;
	});
	ll st = 1;
	for (; st <= n && a[st].l > a[st].r; ++ st);
    if (st > n) {
		cout << -1;
		return 0;
    }
    if (a[st].l != lmin) {
		cout << -1;
		return 0;
    }
    ll nowr = a[st].r;
    ll best_r = a[st].r;
    ll res = 1;
    bool ok = false;
    for (ll i = st + 1; i <= n; ++ i) {
		if (a[i].l <= nowr + 1) {
			best_r = max(best_r, a[i].r);
			ok = true;
		} else {
			if (!ok) {
				cout << -1;
				return 0;
			}
			++ res;
            nowr = max(nowr, best_r);
            best_r = nowr;
            ok = false;
            if (a[i].l <= nowr + 1) {
				best_r = max(best_r, a[i].r);
				ok = true;
			}
		}
    }
    if (nowr < 100000) {
        ++ res;
		nowr = max(nowr, best_r);
    }
    if (nowr < 100000) {
		cout << -1;
		return 0;
    }
    cout << res;
	return 0;
}
