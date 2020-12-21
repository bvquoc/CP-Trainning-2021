#include<bits/stdc++.h>
#define ll long long
//<(")
using namespace std;

typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;

const ll siz = 3e3 + 10;
const ll mod = 998244353;
const ll base = 32;
const ll MAXX = 1e5;
const ll maa = 1e18;
const ll off = 300;

void con_meo_ngoo() {
    //khong lam gi ca
}

ll n;
vector<ll> hold;
vector<ll> cnt;
vector<ll> num[2];

ll res[(1 << 15)][11][2];

ll dp(ll mask, ll rem, bool eve) {
	if (mask == ((1 << n) - 1)) {
		return (rem == 0);
	}
	ll &ans = res[mask][rem][eve];
	if (ans != -1) {
		return ans;
	}
	ans = 0;
	for (ll i = 0; i < n; i++) {
		if ((mask & (1 << i)) == 0) {
			ll nMask = mask | (1 << i);
			if (eve) {
				ll nVal = (rem + (num[0][i] - num[1][i] + 11 * 11) % 11) % 11;
				if (cnt[i] % 2 == 0) {
					ans = (ans + dp(nMask, nVal, 1)) % mod;
				}
				else {
					ans = (ans + dp(nMask, nVal, 0)) % mod;
				}
			}
			else {
				ll nVal = (rem + (num[1][i] - num[0][i] + 11 * 11) % 11) % 11;
				if (cnt[i] % 2 == 0) {
					ans = (ans + dp(nMask, nVal, 0)) % mod;
				}
				else {
					ans = (ans + dp(nMask, nVal, 1)) % mod;
				}
			}
		}
	}
	return ans;
}

void sub1() {
	num[1].resize(n); num[0].resize(n);
	cnt.resize(n);
	for (ll i = 0; i < n; i++) {
		num[1][i] = num[0][i] = 0;
		cnt[i] = 0;
	}
	for (ll i = 0; i < n; i++) {
		bool cur = 1;
		ll sub = hold[i];
		while (sub) {
			num[cur][i] += (sub % 10);
			cnt[i]++;
			cur = !cur;
			sub /= 10;
		}
	}
	// for (ll i = 0; i < n; i++) {
       // cerr << cnt[i] << '\n';
       // cerr << num[0][i] << ' ' << num[1][i] << '\n';
    // }
    // cerr << '\n';
	for (ll i = 0; i < (1 << n); i++) {
		for (ll j = 0; j < 11; j++) {
			res[i][j][0] = res[i][j][1] = -1;
		}
	}
	cout << dp(0, 0, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("GIFT11.INP", "r", stdin);
    freopen("GIFT11.OUT", "w", stdout);
    con_meo_ngoo();
    ll t;
	cin >> t;
	while (t--) {
		cin >> n;
		hold.resize(n);
		for (ll i = 0; i < n; i++) {
			cin >> hold[i];
		}
		if (n <= 15) {
			sub1();
			continue;
		}
		cout << 0 << '\n';
	}
    return 0;
}
