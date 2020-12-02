/* 𝙰𝚞𝚝𝚑𝚘𝚛: 𝙱𝚞𝚒 𝚅𝚒 𝚀𝚞𝚘𝚌 */
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
#define testBit(n, bit) (((n) >> (bit)) & 1LL)
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
#define sqr(x) ((x)*(x))
#define endl '\n'
#define int long long
using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}


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

/*
(\_/)
( •_•)
/ >?? */

const int N = 1000006;
const int mod = 1e9 + 7;

int n, k;
int a[N], b[N];

int bit[N];

void update(int x) {
	for (; x <= n; x += x & (-x))
		bit[x]++;
}

int query(int x) {
	int ans = 0;
	for (; x > 0; x -= x & (-x))
		ans += bit[x];
	return ans;	
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("inversion.inp","r",stdin);
    freopen("inversion.out","w",stdout);
    #endif
    int T; Read(T);
	while (T--) {
        Read(n); Read(k);
		FOR(i,1,n) {
			// we have n - i + 1 numbers left, compress it, then we have 1, 2, 3, ..., n - i + 1
			// if we choose a number x, then numbers of inv increase by a minimum value of (x - 1), and maximum value of (x - 1) + (n - i) * (n - i - 1)/2
			// Binary search to find the minimum x that satisfied total inv from is >= k (could find formula to find x in O(1), too lazy for now)
			int l = 1, r = n - i + 1, x = -1;
			while (l <= r) {
				int mi = (l + r) / 2;
				if (mi - 1 + (n - i) * (n - i - 1)/2 >= k) {
					x = mi;
					r = mi - 1;
				}
				else
					l = mi + 1;
			}
			k -= x - 1;
			a[i] = x;
		}

		// FOR(i, 1, n) cerr << a[i] << ' ';
		// cerr << endl;

		// Now we can see that, a[i] is actually the a[i]th numbers of out permutation after deleted i - 1 previous numbers
		// For example: a = {1, 1, 1, 2, 1}
		// That means the permutation can be get by: b = {1, 2, 3, 5, 4}

		// Now we use binary search and bit to find b (could be improved, lol too lazy)
		FOR(i, 1, n) bit[i] = 0;
		FOR(i, 1, n) {
			int l = 1, r = n, x = -1;
			while (l <= r) {
				int mi = (l + r)/2;
				if (mi - query(mi) >= a[i]) {
					x = mi;
					r = mi - 1;
				}
				else l = mi + 1;
			}
			b[i] = x;
			update(b[i]);
		}

		// FOR(i, 1, n) cerr << b[i] << ' ';
		// cerr << endl;

		int ans = 0, cur = 1;
		FOR(i, 1, n) {
			(ans += b[i] * cur % mod) %= mod;
			(cur *= 2) %= mod;
		}
        Write(ans); putchar(endl);
	}
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}