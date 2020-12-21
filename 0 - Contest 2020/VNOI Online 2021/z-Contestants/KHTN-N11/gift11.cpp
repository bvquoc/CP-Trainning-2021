#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int mod = 998244353; 

int test; 
vector<vector<int> > a; 

bool ok(const vector<int> &a) {
	int tot_odd = 0, tot_even = 0, cur = 0; 
	for(int i = (int)a.size() - 1; i >= 0; i--) {
		int num = a[i];
		int odd = 0; 
		int even = 0;  
		int len = 0; 
		for(int j = 0; num > 0; j++) {
			len++; 
			int dig = num % 10; 
			if(j & 1) {
				odd = (odd + dig) % 11; 
			} 
			else even = (even + dig) % 11; 
			num /= 10; 
		}
		if(cur & 1) {
			tot_even += even;
			tot_odd += odd; 
		}
		else {
			tot_even += odd; 
			tot_odd += even; 
		}
		tot_even %= 11; 
		tot_odd %= 11;
		cur += len; 
	}
	return tot_even == tot_odd; 
}

int ans; 
bool vis[2005];
vector<int> tmp; 

void backtrack(const vector<int> &a, int n) {
	if(!n) {
		ans += ok(tmp); 
	}
	for(int i = 0; i < (int)a.size(); i++) {
		if(!vis[i]) {
			vis[i] = true; 
			tmp.pb(a[i]); 
			backtrack(a, n - 1); 
			tmp.pop_back(); 
			vis[i] = false; 
		}
	}
}

void sub1() {
	for(int i = 0; i < test; i++) {
		ans = 0; 
		backtrack(a[i], a[i].size()); 
		cout << ans << '\n'; 
	}
}

void sub2() {
	for(int i = 0; i < test; i++) {
		int tot_odd = 0, tot_even = 0; 
		for(auto x : a[i]) {
			int odd = 0, even = 0; 
			for(int j = 0; x > 0; j++) {
				int dig = x % 10; 
				if(j & 1) odd = (odd + dig) % 11; 
				else even = (even + dig) % 11; 
				tot_odd = (tot_odd + odd) % 11; 
				tot_even = (tot_even + even) % 11; 
				x /= 10; 
			}
		}
		if(tot_odd == tot_even) {
			int ans = 1; 
			for(int i = 1; i <= (int)a[i].size(); i++) ans = ans * i % mod; 
			cout << ans; 	
		}
		else cout << 0 << '\n'; 
	}
}

signed main() {
	freopen("gift11.inp", "r", stdin); 
	freopen("gift11.out", "w", stdout); 
	cin >> test; 
	a.resize(test); 
	int sum_n = 0, n; 
	for(int t = 0; t < test; t++) {
		cin >> n; 
		sum_n += n; 
		for(int i = 1; i <= n; i++) {
			int x; 
			cin >> x; 
			a[t].pb(x); 
		}
	}
	sub1(); 
	return 0; 
	if(sum_n <= 30) sub1(); 
	else {
		sub2(); 
	}
}