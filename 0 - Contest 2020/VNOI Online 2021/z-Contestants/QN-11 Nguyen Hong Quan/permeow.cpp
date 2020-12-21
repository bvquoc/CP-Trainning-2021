#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const ll mod = 1000000007;
const ll nmax = 200001;

ll n;
ll a[nmax];
ll b[nmax];
ll c[nmax];
ll d[nmax];

ll eval() {
	ll res = 0;

	for (ll i = 1; i <= n; ++ i)
		c[i] = d[i];

	for (ll i = 1; i <= n; ++ i) {
		bool ok = false;

		for (ll j = 1; j < n; ++ j) {
			if (c[j] > c[j + 1]) {
				++ res;
				swap (c[j], c[j + 1]);
				ok = true;
			}
		}

		if (!ok)
			return res;
	}

	return res;
}

void sub1() {
	for (ll i = 1; i <= n; ++ i)
		d[i] = a[i];

	cout << eval() << "\n";
	return;
}

void checking_purpose() {
	for (ll i = 1; i <= n; ++ i)
		d[i] = i;

	ll res = 0;

	do {
		for (ll i = 1; i <= n; ++ i) {
			cout << d[i] << " ";
		}
		ll temp = eval();
		res += temp;
		cout << "\nthis cost " << temp << "\n\n";
	} while (next_permutation (d + 1, d + n + 1));

	cerr << n << " " << res << "\n";
	exit (0);
}

void sub2() {
    if (n == 1) {
		cout << 0;
		return;
    }
    if (n == 2) {
		cout << 1;
		return;
    }
    ll res = 1;
    ll fac = 2;
    ll sum = 3;
    for (ll i = 3; i <= n; ++ i) {
		res = (res * i + sum * fac) % mod;
		sum = (sum + i) % mod;
		fac = (fac * i) % mod;
    }
    cout << res << "\n";
    return ;
}

int main() {
	if (fopen ("permeow.inp", "r")) {
		freopen ("permeow.inp", "r", stdin);
		freopen ("permeow.out", "w", stdout);
	}

	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	cin >> n;
	bool request_sub1 = true;
	bool request_sub2 = true;

	for (ll i = 1; i <= n; ++ i) {
		cin >> a[i];
		if (a[i] != i) request_sub2 = false;
	}

	for (ll i = 1; i <= n; ++ i) {
		cin >> b[i];

		if (a[i] != b[i])
			request_sub1 = false;
		if (b[i] != n - i + 1) {
			request_sub2 = false;
		}
	}

	if (request_sub1) {
		sub1();
		return 0;
	}
//	checking_purpose();
	if (request_sub2) {
		sub2();
		return 0;
	}

	for (ll i = 1; i <= n; ++ i)
		d[i] = a[i];

	ll res = 0;

	do {
		ll temp = eval();
		res += temp;
		bool stop_time = true;

		for (ll i = 1; i <= n; ++ i) {
			if (d[i] != b[i]) {
				stop_time = false;
				break;
			}
		}

		if (stop_time)
			break;

	} while (next_permutation (d + 1, d + n + 1));

	cout << res;
	return 0;
}
