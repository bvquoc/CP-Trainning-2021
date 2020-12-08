#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define testBit(n, bit) (((n) >> (bit)) & 1)
#define flipBit(n, bit) ((n) ^ (1ll << (bit)))
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)
#define sqr(x) ((x)*(x))
#define endl '\n'
// #define int long long
using namespace std;

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x > y + eps) {
        x = y;
        return true;
    }
    return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    }
    return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

/*
(\_/)
( •_•)
/ >?? */

int const MOD = 1000003;

int invmod(int x, int y = MOD){
	int a = x, b = y, ax = 1, bx = 0;
	while(b) {
		int q = a / b;
		a %= b;
		ax -= q * bx;
		swap(a, b);
		swap(ax, bx);
	}
	assert(a == 1);
	if(ax < MOD) ax += MOD;
	return ax;
}

vector<int> fact;

int binom(int a, int b) {
	if(b < 0 or b > a) return 0;
	return fact[a] * (int64_t) invmod(fact[b] * (int64_t) fact[a-b] % MOD, MOD) % MOD;
}

int cat(int n) {
	return (binom(2*n,n)+MOD-binom(2*n,n-1))%MOD;
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen ("mine.inp","r",stdin);
	freopen ("mine.out","w",stdout);
    #endif
	int npair, maxspan;
    cin >> npair >> maxspan;
	vector<int> a(npair*2);
    for(int& x:a) cin >> x;

	fact.resize(npair*2+1); // TODO 
	fact[0] = 1;

	for(unsigned i = 1; i < fact.size(); ++i) // complexity: npair log npair
		fact[i] = (int64_t) i * fact[i-1] % MOD;

	vector<int> dp(npair+1);
	dp[0] = 1;
	for(int i = 1, j = 0; i <= npair; ++i){
		while(j < i and a[2*i-1]-a[2*j] > maxspan) ++j;
		int dpi = 0;
		if(j==0)dpi=cat(i);
		else {
			for(int k = j; k < i; ++k)
				dpi = (dpi + dp[k] * (int64_t)cat(i-k-1)) % MOD;
		}
		dp[i] = dpi;
	} // complexity: min(npair,maxspan) * npair
	cout << dp.back();
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}