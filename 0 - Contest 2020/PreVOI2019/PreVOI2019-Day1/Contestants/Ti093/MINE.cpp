#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e6 + 3;
const int BIG = 1e9 + 555;
const int maxN = 2e5 + 55;

ll m;
int n;
int a[2 * maxN];

ll Try(int l, int r){
	if(r + 1 == l){
		return 1;
	}
	
	ll ans = 0;
	for(int k = l + 1; k <= r; k += 2){
		if(a[k] - a[l] <= m){
			ans = (ans + ((Try(l + 1, k - 1) * Try(k + 1, r)) % MOD)) % MOD;
		}
	}

	return ans;
}

ll memo[405][405];
bool calc[405][405];

ll dp(int lf, int rt){
	if(rt + 1 == lf){
		return 1;
	}

	if(calc[lf][rt]){
		return memo[lf][rt];
	}

	ll ans = 0;

	for(int k = lf + 1; k <= rt; k += 2){
		if(a[k] - a[lf] <= m){
			ans = (ans + ((dp(lf + 1, k - 1) * dp(k + 1, rt)) % MOD)) % MOD;
		}
	}

	calc[lf][rt] = true;
	return (memo[lf][rt] = ans);
}

ll fact[4 * maxN], rfact[4 * maxN];

ll quickPow(ll x, ll y){
	if(y == 0){
		return 1;
	}

	ll tmp = quickPow(x, y / 2);
	if(y % 2){
		return (((tmp * tmp) % MOD) * (x % MOD)) % MOD;
	}
	
	return (tmp * tmp) % MOD;
}

ll nCk(ll x, ll y){
	ll ans = fact[x];
	ans = (ans * rfact[x - y]) % MOD;
	ans = (ans * rfact[y]) % MOD;

	return ans;
}

void sub3(){
	fact[0] = 1;
	for(ll i = 1; i <= 4 * n; i++){
		fact[i] = (fact[i - 1] * i) % MOD;
	}

	for(ll i = 0; i <= 4 * n; i++){
		rfact[i] = quickPow(fact[i], MOD - 2);
	}	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("MINE.INP", "r", stdin);
	freopen("MINE.OUT", "w", stdout);

	cin >> n >> m;

	for(int i = 0; i < 2 * n; i++){
		cin >> a[i];
	}
	
	if(n <= 10){
		cout << Try(0, 2 * n - 1) << '\n';
		return 0;
	}
	
	if(n <= 200){
		cout << dp(0, 2 * n - 1) << '\n';
		return 0;
	}
	
	cout << "0\n";

	//Catalan number or sth :V
	//if((n <= 200000) && (m == 1000000)){
	//	sub3();
	//	return 0;
	//}

	return 0;
}