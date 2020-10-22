#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const string INP=".INP", OUT=".OUT";
const string FILENAME="CNTSOLS";
const int MOD = 1000000007;

int pw(int a, int b, int mod) {
	if(b == 0) return 1 % mod;
	int x = pw(a, b/2, mod);
	x = (x*x) % mod;
	if (b&1) x = (x*a) % mod;
	return x;
}

int U, d, m, n;
int cnt[50];

signed main() {
	FastIO;
	freopen((FILENAME+INP).c_str(),"r",stdin);
	freopen((FILENAME+OUT).c_str(),"w",stdout);
	int T; cin >> T;
	while(T--) {
		cin >> U >> d >> m >> n;
		memset(cnt, 0, sizeof(cnt));
		//count how many i are there so that, i^d % n
		FOR(i,0,n-1) {
			int cur = pw(i, d, n);
			if(i <= U)
				cnt[cur] += (U - i)/n + 1;
		}

		//You have the counts.. now check if x^d + y^d + z^d = m % n.
		//It can be done in O(n^2) as well.
		int res = 0;
		FOR(i,0,n-1) FOR(j,0,n-1) FOR(k,0,n-1) {
			if ((i + j + k)%n == m%n) {
				res += (cnt[i]*((cnt[j]*cnt[k])%MOD))%MOD;
				res %= MOD;
			}
		}

		printf("%d\n", res);
	}
	return 0;
}