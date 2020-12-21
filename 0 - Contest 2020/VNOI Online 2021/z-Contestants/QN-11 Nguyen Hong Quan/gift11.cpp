#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const ll mod = 998244353;
const ll nmax = 2001;

ll n;
ll a[nmax];
ll d[nmax];
ll fac[nmax];

void sub1() {
	ll res = 0;
	for (ll i = 1; i <= n; ++ i) {
		d[i] = i;
	}
	do {
		ll now = 0;
		bool odd = false;
		for (ll i = 1; i <= n; ++ i) {
			ll xx = a[d[i]];
            for (; xx > 0; odd ^= 1, now += (odd ? -1 : 1) * xx % 10, xx /= 10);
		}
		if (now % 11 == 0) ++ res;
	} while (next_permutation(d + 1, d + n + 1));
	cout << res;
}

void sub2() {
	ll now = 0;
	bool odd = false;
    for (ll i = 1; i <= n; ++ i) {
		ll xx = a[i];
		for (; xx > 0; odd ^= 1, now += (odd ? -1 : 1) * xx % 10, xx /= 10);
    }
    if (now % 11) {
		cout << 0;
		return ;
    }
    cout << fac[n];
}

void sol() {
	bool even = true;
	cin >> n;
	for (ll i = 1; i <= n; ++ i) {
		cin >> a[i];
		ll tt = 0;
		ll xx = a[i];
		for (; xx > 0; ++ tt, xx /= 10);
		if (tt % 2) {
			even = false;
		}
	}
	if (n <= 11) {
		sub1();
		return ;
    }

    if (even) {
		sub2();
		return;
    }
}

int main(){
	if (fopen("gift11.inp", "r")) {
		freopen("gift11.inp", "r", stdin);
		freopen("gift11.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	fac[0] = 1;
	for (ll i = 1; i <= 2000; ++ i) {
		fac[i] = (fac[i - 1] * i) % mod;
	}
	ll t; cin >> t;
	for (; t-- > 0;) {
		sol();
		cout << "\n";
	}
	return 0;
}
