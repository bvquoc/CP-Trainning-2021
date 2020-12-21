#include <bits/stdc++.h>
using namespace std;

/* -------------------- attic -------------------- */
#pragma region
using str = string;         using db  = double;            using i32 = int;            using i64 = long long;
using v32 = vector<i32>;    using p32 = pair<i32, i32>;    using v64 = vector<i64>;    using p64 = pair<i64, i64>;
template<typename T>using heapmax = priority_queue<T>;
template<typename T>using heapmin = priority_queue<T, vector<T>, greater<T>>;
#define x first
#define y second
#define _______14112019_______ firstSetup();
#define _______06072020_______ return 0;

const i32 MAX32 = 1   << 30;
const i64 MAX64 = 1ll << 60;
const i32 MOD32 = 1e9 + 7;
const db  PI    = acos(-1);

template<typename T1, typename T2>i64 gcd(T1 a, T2 b) { while (b != 0) swap(b, a %= b); return a; }
template<typename T1, typename T2>i64 lcm(T1 a, T2 b) { return a/gcd(a, b)*b; }
template<typename T1, typename T2>void maximize(T1 &a, T2 b) { if (a < b) a = b; }
template<typename T1, typename T2>void minimize(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2>T1 pw(T1 a, T2 n, i64 MOD = 0) { if (n == 0) return T1(1); T1 ans = a; --n; for (T1 mult = a; n != 0; n >>= 1) { if (n&1) ans *= mult; mult *= mult; if (MOD != 0) ans %= MOD, mult %= MOD; } return ans; }
template<typename T>i64 sqr(T a) { return a*a; }
template<typename T>i64 log(T a) { return 31 - __builtin_clz(a); }
template<typename T>i64 htoi(T x) { return 9 * (x >> 6) + (x & 017); }

i64 gi64() { i64 x; return        cin >> x, x; }
i32 gi32() { i32 x; return        cin >> x, x; }
str gstr() { str x; return        cin >> x, x; }
str glne() { str x; return getline(cin, x), x; }

template<typename T> struct number_iterator : std::iterator<random_access_iterator_tag, T>{ T v; number_iterator(T _v) : v(_v) {} operator T&() { return v; } T operator *() const { return v; } };
template<typename T> struct number_range { T b, e; number_range(T b, T e) : b(b), e(e) {} number_iterator<T> begin() { return b; } number_iterator<T> end() { return max(b, e); } };
template<typename T> number_range<T> range(T e) { return number_range<T>(0, e); }
template<typename T> number_range<T> range(T b, T e) { return number_range<T>(b, e); }

void    read() { return;       } template<typename T, typename... Args> void    read(T &a, Args &...args) { cin >> a;            read(args...); }
void  readln() { cin.ignore(); } template<typename T, typename... Args> void  readln(T &a, Args &...args) { cin >> a;          readln(args...); }
void   write() { return;       } template<typename T, typename... Args> void   write(T  a, Args  ...args) { cout << a << ' ';   write(args...); }
void writeln() { cout << '\n'; } template<typename T, typename... Args> void writeln(T  a, Args  ...args) { cout << a << ' '; writeln(args...); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
	size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }
};

#pragma endregion

void firstSetup() {
    freopen("DECOR.INP", "r", stdin);
    freopen("DECOR.OUT", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cout << fixed << setprecision(2);
}



/* ----------------- living room ----------------- */
// constant
const i32 N = 1e5;

// input
i32 n, m, k;
str s;
i32 u, v;

// supporter
v32 adj[N];

// answer

// function
void sub12();



i32 main() {
	_______14112019_______
	// do something
	readln(n, m, k);
	readln(s);
	for (i32 i : range(m)) {
		readln(u, v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (m == 0) sub12();
	else return 404;
	
	_______06072020_______
}



/* ------------------- basement ------------------ */
void sub12() {
	i32 ansL = 0, ansR = -1;
	for (i32 l = 0, r = 0, cnt = 0; r < n; ++r) {
		if (s[r] == '0') {
			++cnt;
			while (cnt > k)
				if (s[l++] == '0')
					--cnt;
		}
		if (r - l > ansR - ansL)
			ansL = l, ansR = r;
	}
	write(ansL + 1, ansR + 1);
}



/*

-----------------
input:          |

-----------------
output:         |

-----------------

*/