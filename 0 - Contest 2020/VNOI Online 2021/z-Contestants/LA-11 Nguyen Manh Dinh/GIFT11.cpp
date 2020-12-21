#include <bits/stdc++.h>
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;

const ll N = 2002;
const ll mod = 50000;
const ll oo = 1e9+2;

ll t, n;
vector<ll> a;
vector<ii> f;
vector<pair<ii, ll>> s;

void sub1() {
	ll res = 0;ll t = 0;
	sort(all(a));
	vector<ii> aa;
	aa.resize(n);
	for(int i = 0; i < n; ++i)
		aa[i] = {a[i], i};
	do {
		vector<ii> b = aa;
		ll x[2] = {0, 0};
		for(int i = (ll)b.size() - 1, j = 0; i >= 0; --i) {
			while(b[i].F) {
				++j;
				x[j%2] += b[i].F%10;
				b[i].F /= 10;
			}
		}
		if ((abs(x[0] - x[1]))%11 == 0) res++;
	}while(next_permutation(all(aa)));
	cout << res << '\n';
}

void sub2() {
	ll x[2] = {0, 0};
	ll gt = 1;
	for(int i = (ll)a.size() - 1, j = 0; i >= 0; --i) {
		while(a[i]) {
			++j;
			x[j%2] = a[i]%10;
			a[i] /= 10;
		}
		gt *= i + 1;
	}
	if (abs(x[0] - x[1])%11 == 0) cout << gt << '\n';
	else cout << 0 << '\n';
}

ll dp[2001][2001][12];

ll DP(ll i, ll j, ll du) {
	if (j < 0) return 0;
	if (i == n) return !j && !du;
	ll &res = dp[i][j][du];
	if (~res) return res;
	res = DP(i + 1, j - 1, (du + f[i].F - f[i].S + 11)%11)
		+ DP(i + 1, j, (du + f[i].S - f[i].F + 11)%11);
	return res;
}

void sub3() {
	f.resize(n);
	for(int i = 0; i < n; ++i) {
		ll j = 1;
		f[i] = {0, 0};
		while(a[i]) {
			if (j%2 == 1) f[i].F += a[i]%10;
			else f[i].S += a[i]%10;
			a[i] /= 10;
			++j;
		}
	}
	memset(dp, -1, sizeof dp);
	ll tmp = DP(0, (n+1)/2, 0);
	ll even = 1, odd = 1;
	for(int i = 1; i <= (n+1)/2; ++i)
		even *= i;
	for(int i = 1; i <= n/2; ++i)
		odd *= i;
	cout << tmp * even * odd << '\n';
}

void solve() {
	cin >> n;
	a.resize(n);
	bool check = 1;
	for(int i = 0; i < n; ++i)
		cin >> a[i], check &= a[i]%2 == 1;
	if (n <= 8) sub1();
	else if (check) sub2();
	else sub3();
}

int main()
{
	freopen("GIFT11.INP", "r", stdin);
	freopen("GIFT11.OUT", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int t;
    cin >> t;
    while(t--)
    solve();
    // cout << "\n\nTime: " << clock()/1000.0 << 's';
    return 0;
}
