#include<bits/stdc++.h>
#define qwer "mine"

using namespace std;

const int mod = 1e6 + 3;

void add(int&a,int b)
{
	a += b;
	if (a >= mod ) a -= mod;
}

int mul(int a,int b)
{
	return 1ll * a * b % mod;
}

int inverse(int a)
{
	int b = mod,u = 0,v = 1;
	while (a) {
		int t = b / a;
		b -= a * t;swap(a,b);
		u -= v * t;swap(u,v);
	}
	assert(b == 1);
	if (u < 0) u += mod;
	return u;
}

int sub(int a,int b)
{
	a -= b;
	if (a < mod) a += mod;
}

int main()
{
	if (fopen(qwer".inp","r")) freopen(qwer".inp","r",stdin),freopen(qwer".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> f(2 * n + 1),rev(2 * n + 1);
	f[0] = 1;
	for (int i = 1;i <= n << 1;++i) f[i] = mul(f[i-1],i);
	rev[2 * n] = inverse(f[n<<1]);
	for (int i = 2 * n - 1;i >= 0;--i) rev[i] = mul(rev[i+1],i+1);
	auto C = [&](int k,int n)
	{
		return mul(f[n],mul(rev[k],rev[n-k]));	
	};
	vector<int> a(2 * n);
	for (int i = 0;i < 2 * n;++i) cin >> a[i];
	if (m >= a[2 * n - 1] - a[0]) {
		cout << sub(C(n,2 * n) , C(n-1,2 * n));
	}
	else {
		if (n <= 10) {
			int ans = 0;
			for (int i = 0;i < 1 << (n * 2);++i) {
				int dem = -n;
				for (int j = 0;j < 2 * n;++j) dem += (i >>j&1);
				if (!dem) {
					bool flag = true;
					stack<int> s;
					for (int j = 0;j < 2 * n;++j) {
						if (i>>j&1) {
							s.push(a[j]);
						}
						else {
							if (s.empty() || a[j] - s.top() > m) flag = false;
							else s.pop();
						}
						if (!flag) break;
					}
					ans += flag;
				}
			}
			cout << ans ;
		}
		else {
			vector<int> dp(2 * n+1);
			vector<int> bra(2 * n+1);
			for (int i = 1;i <= 2 * n;++i) {
				if (i&1) bra[i] = 0;else
				bra[i] = sub(C(i >> 1,i) , C(i/2-1,i));
			}
			dp[0] = 1;
			for (int i = 2;i <= 2 * n;i += 2) {
				for (int j = 1;j < i;j += 2) {
					if (a[i-1] - a[j-1] <= m) {
						int num = i-j+1;
						add(dp[i],mul(bra[num],dp[j-1]));	
					}
				}
			}
			cout << dp[2 * n];
		}
	}
}
