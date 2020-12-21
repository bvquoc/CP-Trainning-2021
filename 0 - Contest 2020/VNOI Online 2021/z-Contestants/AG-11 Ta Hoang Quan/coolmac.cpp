#include<bits/stdc++.h>
using namespace std;

#define forr(_a, _b, _c) for(_a = _b; _a <= _c; ++_a)
#define forf(_a, _b, _c) for(_a = _b; _a < _c; ++_a)
#define file "coolmac"
typedef long long ll;
const ll inf = ll(1e9) + 1;
#define fi first
#define se second
typedef pair<int,int> pa;
int m, i, n, mi = inf, k, dp[100002], j, ma, o;
pa a[100002];
bool tf;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen(file".inp","r",stdin); freopen(file".out","w",stdout);

	cin >> n;
	forr(i,1,n) cin >> a[i].fi >> a[i].se;
	sort(a + 1,a + 1 + n);
	a[n + 1].fi = 100000;
	cin >> m;
	while(m-- > 0) {
		cin >> k;
		mi = min(mi,k);
	}
	memset(dp,inf,sizeof(dp));
	forr(i,1,n)
		if(a[i].fi <= mi) dp[i] = 0;
		else break;
	if(n > 3000) {
		forr(i,1,n) forr(j,i + 1,n + 1)
			if(a[j].fi <= a[i].se) dp[j] = min(dp[j],dp[i] + 1);
		if(dp[n + 1] > n) cout << -1;
		else cout << dp[n + 1];
	} else {
		i = 1;
		++n;
		while(i <= n)
			if(a[i].fi <= mi) {
				tf = false;
				ma = max(ma,a[i].se);
				++i;
			} else {
				++o;
				mi = ma;
				ma = 0;
				if(tf) break;
				else tf = true;
			}
		if(mi < 100000) cout << -1;
		else cout << o;
	}

	return 0;
}