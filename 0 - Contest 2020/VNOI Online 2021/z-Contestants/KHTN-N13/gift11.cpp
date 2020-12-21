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

const int oo = 1e18 + 7, mod = 998244353;

const int N = 2005;

// rem[i] => sum of odd pos - sum of even pos
int t, n, dp1[N][N][11], dp2[N][N][11], rem[N], fac[N], invfac[N];
vector<int> odd, even;

int inv(int base){
	int pw = mod - 2, ans = 1;
	while(pw){
		if(pw & 1) ans = (ans * base) % mod;
		base = (base * base) % mod;
		pw >>= 1;
	}
	return ans;
}

void init(int od, int ev){
	for(int i = 0; i <= od; i++){
		for(int j = 0; j <= i; j++){
			for(int k = 0; k < 11; k++) dp1[i][j][k] = 0;
		}
	}
	for(int i = 0; i <= ev; i++){
		for(int j = 0; j <= i; j++){
			for(int k = 0; k < 11; k++) dp2[i][j][k] = 0;
		}
	}
}

int num_dig(int x){
	int cnt = 0;
	while(x){
		cnt++;
		x /= 10;
	}
	return cnt;
}

int remain(int x){
	int cnt = 0, ans = 0;
	while(x){
		if(!cnt) ans += (x % 10);
		else ans -= (x % 10);
		cnt ^= 1;
		x /= 10;
	}
	return ans;
}

void cal_fac(){
	fac[0] = 1;
	for(int i = 1; i <= 2000; i++) fac[i] = (fac[i - 1] * i) % mod;
	invfac[0] = 1;
	for(int i = 1; i <= 2000; i++) invfac[i] = inv(fac[i]);
}

void solve(){
	cin >> n;
	odd.clear();
	even.clear();
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(num_dig(x) & 1) odd.pb(i);
		else even.pb(i);
		rem[i] = (remain(x) + 110) % 11;
	}
	init(odd.size(), even.size());
	if(!odd.size()){
		int sum = 0;
		for(int i = 1; i <= n; i++) sum += rem[i];
		sum %= 11;
		if(!sum) cout << fac[n];
		else cout << 0;
		cout << "\n";
		return;
	}
	dp1[0][0][0] = 1;
	for(int i = 1; i <= odd.size(); i++){
		for(int j = 0; j <= i; j++){
			for(int k = 0; k < 11; k++){
				if(j) dp1[i][j][k] += dp1[i - 1][j - 1][(k + rem[odd[i - 1]]) % 11];
				dp1[i][j][k] += dp1[i - 1][j][(k - rem[odd[i - 1]] + 11) % 11];
				if(dp1[i][j][k] >= mod) dp1[i][j][k] -= mod;
			}
		}
	}
	dp2[0][0][0] = 1;
	for(int i = 1; i <= even.size(); i++){
		//cout << rem[even[i - 1]] << "\n";
		for(int j = 0; j <= i; j++){
			for(int k = 0; k < 11; k++){
				if(j) dp2[i][j][k] += dp2[i - 1][j - 1][(k + rem[even[i - 1]]) % 11];
				dp2[i][j][k] += dp2[i - 1][j][(k - rem[even[i - 1]] + 11) % 11];
				if(dp2[i][j][k] >= mod) dp2[i][j][k] -= mod;
			}
		}
	}
	int answer = 0;
	for(int i = 0; i < 11; i++){
		int sum = 0;
		for(int j = 0; j <= even.size(); j++){
			int temp = dp2[even.size()][j][i];
			//cout << temp << " " << j << " ";
			if(!(odd.size() & 1)){
				temp = (temp * fac[(odd.size()) / 2 + j]) % mod;
				temp = (temp * invfac[(odd.size()) / 2]) % mod;
				temp = (temp * fac[(odd.size() - 1) / 2 + (even.size() - j)]) % mod;
				temp = (temp * invfac[(odd.size() - 1) / 2]) % mod;
			}
			else{
				temp = (temp * fac[(odd.size() - 1) / 2 + j]) % mod;
				temp = (temp * invfac[(odd.size() - 1) / 2]) % mod;
				temp = (temp * fac[(odd.size() - 1) / 2 + (even.size() - j)]) % mod;
				temp = (temp * invfac[(odd.size() - 1) / 2]) % mod;
			}
			//cout << temp << "\n";
			sum = (sum + temp) % mod;
			//cout << j << " " << sum << " " << even.size() << "\n";
			//cout << i << " " << j << " " << dp2[even.size()][j][i] << "\n";
		}
		//cout << sum << " " << dp1[odd.size()][odd.size() / 2][(11 - i) % 11] << "\n";
		sum = (sum * dp1[odd.size()][odd.size() / 2][(11 - i) % 11]) % mod;
		sum = (sum * fac[odd.size() / 2]) % mod;
		sum = (sum * fac[odd.size() - (odd.size() / 2)]) % mod;
		answer += sum;
		//cout << sum << " " << dp1[odd.size()][odd.size() / 2][(11 - i) % 11] << "\n";
		//cout << answer << "\n";
		answer %= mod;
	}
	cout << answer << "\n";
}

signed main(){
	freopen("gift11.inp", "r", stdin);
	freopen("gift11.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cal_fac();
	cin >> t;
	while(t--) solve();
}


