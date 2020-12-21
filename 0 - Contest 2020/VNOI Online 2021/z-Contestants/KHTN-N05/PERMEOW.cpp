#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 200005;
const ll mod = 1e9 + 7;

ll add(ll a, ll b) {
	return (a + b >= mod ? a + b - mod : a + b);
}
ll sub(ll a, ll b) {
	return (a - b < 0 ? a - b + mod : a - b);
}
ll mul(ll a, ll b) {
	return (a * b) % mod;
} 

int n;
vector<int> a, b;
ll fact[N], dp[N];
ll pref[N];

ll fen[N];
void upd(int id, ll x) {
	for (int i = id; i <= n; i += (i & -i)) {
		fen[i] += x;
	}
}
ll get(int id) {
	ll ans = 0;
	for (int i = id; i >= 1; i -= (i & -i)) {
		ans += fen[i];
	}
	return ans;
}

ll solve(vector<int> &a) {
	ll ans = 0, sum = 0;
	for (int i = 1; i <= n; i++) fen[i] = 0;
	for (int i = 1; i <= n; i++) upd(i, 1);
	for (int i = 1; i <= n; i++) {
		int tmp = get(a[i - 1]) - 1;
		if (tmp > 0) {
			ans = add(ans, add(mul(pref[tmp - 1], fact[n - i]), mul(dp[n - i], tmp)));
			ans = add(ans, mul(sum, mul(tmp, fact[n - i])));
		}
		sum = add(sum, get(a[i - 1] - 1)); 
		upd(a[i - 1], -1);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("PERMEOW.inp", "r", stdin);
	freopen("PERMEOW.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		a.push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		b.push_back(x);
	}
	
	fact[0] = 1; pref[0] = 0;
	for (int i = 1; i <= n; i++) {
		fact[i] = mul(fact[i - 1], i);
		pref[i] = add(pref[i - 1], i);
	}
	
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = add(mul(dp[i - 1], i), mul(pref[i - 1], fact[i - 1]));
	}
	
	ll ans = sub(solve(b), solve(a));
	for (int i = 1; i <= n; i++) fen[i] = 0;
	for (int i = 1; i <= n; i++) {
		ans = add(ans, sub(get(n), get(b[i - 1])));
		upd(b[i - 1], 1);
	}
	
	cout << ans;
}
