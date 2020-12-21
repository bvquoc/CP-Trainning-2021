#include <bits/stdc++.h>
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;

const ll N = 100004;
const ll mod = 50000;
const ll oo = 1e9+2;

ll m, n, tmin = oo;
ll st[4*N];

void update(ll pos, ll val, ll p = 1, ll b = 1, ll e = N-4) {
	if (pos < b || e < pos) return;
	if (b == e) st[p] = max(st[p], val);
	else {
		ll mid = (b + e) >> 1;
		update(pos, val, 2*p, b, mid);
		update(pos, val, 2*p + 1, mid + 1, e);
		st[p] = max(st[2*p], st[2*p + 1]);
	}
}

ll getmax(ll pos, ll p = 1, ll b = 1, ll e = N - 4) {
	if (pos < b) return -1;
	if (e <= pos) return st[p];
	ll mid = (b + e) >> 1;
	ll tmp1 = getmax(pos, 2*p, b, mid);
	ll tmp2 = getmax(pos, 2*p + 1, mid + 1, e);
	return max(tmp1, tmp2);
}

void solve() {
	memset(st, 0, sizeof st);
	cin >> m;
	for(int i = 1; i <= m; ++i) {
		ll l, r;
		cin >> l >> r;
		update(l, r);
	}
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		ll t; cin >> t;
		tmin = min(t, tmin);
	}
	ll res = 0, tmax = tmin;
	while(tmax != N-4) {
		ll tmp = getmax(tmax);
		if (tmp == tmax) {cout << -1;return;}
		tmax = tmp;
		res++;
	}
	cout << res;
}

int main()
{
	// freopen("COOLMAC.INP", "r", stdin);
	// freopen("COOLMAC.OUT", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    solve();
    // cout << "\n\nTime: " << clock()/1000.0 << 's';
    return 0;
}
