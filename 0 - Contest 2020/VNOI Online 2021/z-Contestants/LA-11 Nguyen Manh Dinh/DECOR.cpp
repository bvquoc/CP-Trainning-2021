#include <bits/stdc++.h>
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;

const ll N = 500004;
const ll mod = 50000;
const ll oo = 1e17+2;

ll n, m, prefix[N], k, len;
string s;
vector<ll> edge[N];

void sub2() {
	len = s.size();
	s = " " + s;
	prefix[0] = 0;
	for(int i = 1; i <= len; ++i)
		prefix[i] = prefix[i - 1] + s[i] == 0;
	ll res = -1, x, y;
	for(int i = 1; i <= n; ++i) {
		ll l = 1, r = i;
		while(l <= r) {
			ll mid = (l + r) >> 1;
			ll sum = prefix[i] - prefix[mid - 1];
			if (sum <= k) {
				if (res < i - mid + 1) {
					res = i - mid + 1;
					x = mid, y = i;
				}
				r = mid - 1;
			}
			else l = mid + 1;
		}cout << res << '\n';
	}
	if (~res) cout << x << ' ' << y;
	else cout << res;
}

void solve() {
	cin >> n >> m >> k >> s;
	for(int i = 1; i <= m; ++i) {
		ll u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	if (m == 0) sub2();
	else sub3();
}

int main()
{
	freopen("DECOR.inp", "r", stdin);
	freopen("DECOR.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    solve();
    // cout << "\n\nTime: " << clock()/1000.0 << 's';
    return 0;
}