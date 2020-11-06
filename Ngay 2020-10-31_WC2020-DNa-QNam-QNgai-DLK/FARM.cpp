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
    } else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    } else return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int oo = 1e9;
const int maxN = 10004;

int n, k, Q, P, a[maxN];

int** cache;
int solve(int i, int q) {
	if (i < 1) return 0;
	
	int& res = cache[i][q];
	if (res != -1) return res;
	
	res = solve(i - 1, q);
	int qty = min(q, P);
	res = max(res, solve(i - k, q - qty) + qty * a[i]);
	
	qty = q % P;
	res = max(res, solve(i - k, q - qty) + qty * a[i]);
	return res;
}

signed main(void) {
    FastIO;
    freopen("FARM.INP","r",stdin);
    freopen("FARM.OUT","w",stdout);
    cin >> n >> k >> Q >> P;
	FOR(i,1,n) cin >> a[i];
    cache = new int*[n + 1];
    FOR(i,0,n) {
        cache[i] = new int[Q + 1];
        for (int q = 0; q <= Q; q++) cache[i][q] = -1;	
    }
    cout << solve(n, Q);
    return 0;
}