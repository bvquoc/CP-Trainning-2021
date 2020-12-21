#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define ins insert
#define er erase

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

const int oo = 1e18 + 7, mod = 1e9 + 7;

const int N = 2e5 + 5;

int fac[N];

int n, a[N], b[N], bit[N];

void refresh(){
	for(int i = 1; i <= n; i++) bit[i] = 0;
}

void upd(int pos, int val){
	for(; pos <= n; pos += pos & -pos) bit[pos] += val;
}

int get(int pos){
	int ans = 0;
	for(; pos; pos -= pos & -pos) ans += bit[pos];
	return ans;
}

int ans(int arr[]){
	if(arr[1] == 0) return 0;
	int answer = 0, tolinv = 0;
	refresh();
	for(int i = 1; i <= n; i++) upd(i, 1);
	for(int i = 1; i <= n; i++){
		int tmp = get(arr[i] - 1);
		//cout << arr[i] << " " << tmp << " " << tolinv << " " << answer << "\n";
		int temp = fac[n - i], temp2 = ((n - i) * (n - i - 1) / 2) % mod;
		temp = (temp * temp2) % mod;
		temp = (temp * tmp) % mod;
		temp = (temp * 500000004) % mod;
		//cout << temp << "\n";
		int temp3 = fac[n - i], temp4 = (tmp * (tmp - 1) / 2) % mod;
		temp3 = (temp3 * temp4) % mod;
		answer = (answer + temp) % mod;
		answer = (answer + temp3) % mod;
		int temp5 = (tolinv * fac[n - i]) % mod;
		if(i < n) temp5 = (temp5 * tmp) % mod;
		answer = (answer + temp5) % mod;
		tolinv += tmp;
		upd(arr[i], -1);
	}
	return answer;
}

signed main(){
	freopen("PERMEOW.inp", "r", stdin);
	freopen("PERMEOW.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	fac[0] = 1;
	for(int i = 1; i <= 200000; i++) fac[i] = (fac[i - 1] * i) % mod;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	bool ck = 0;
	for(int i = 1; i <= n; i++) ck |= (a[i] != i);
	if(!ck) a[1] = 0;
	else prev_permutation(a + 1, a + n + 1);
	//cout << ans(b) << "\n";
	//cout << ans(a) << "\n";
	cout << (ans(b) - ans(a) + mod) % mod;
}


