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
const i32 MOD32 = 998244353;
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
void   write() { return;       } template<typename T, typename... Args> void   write(T &a, Args &...args) { cout << a << ' ';   write(args...); }
void writeln() { cout << '\n'; } template<typename T, typename... Args> void writeln(T &a, Args &...args) { cout << a << ' '; writeln(args...); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
	size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }
};

#pragma endregion

void firstSetup() {
    freopen("gift11.INP", "r", stdin);
    freopen("gift11.OUT", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cout << fixed << setprecision(2);
}



/* ----------------- living room ----------------- */
// constant
const i32 N = 2000;

// input
i64 n;
str s;
pair<i64, bool> a[N];

// supporter
i64 ind[N];
i64 fact[N + 1];
i64 sum;
bool isAllEven;

// answer
i64 ans;

// function
void query(i32 nTest);



i32 main() {
	_______14112019_______
	// do something
	fact[0] = 1;
	for (i32 i : range(1, N + 1))
		fact[i] = fact[i - 1] * i % MOD32;
	for (i32 t = gi32(), i = 1; i <= t; query(i++));

	_______06072020_______
}



/* ------------------- basement ------------------ */
void query(i32 nTest) {
	cin >> n; isAllEven = true;
	for (i32 i : range(n)) {
		cin >> s; a[i].x = 0;
		for (i32 j : range(s.size()))
			if (j % 2 == 1)
				a[i].x += s[j] - '0';
			else
				a[i].x -= s[j] - '0';
		a[i].y = s.size() % 2;
		isAllEven &= a[i].y == 0;
		ind[i] = i;
	}
	if (isAllEven) {
		sum = 0;
		for (i32 i : range(n))
			sum += a[i].x;
		if (sum % 11 == 0)
			cout << fact[n] << '\n';
		else
			cout << "0\n";
	} else if (n <= 9) {
		ans = 0;
		do {
			sum = 0;
			bool sign = 0;
			for (i32 i : range(n)) {
				if (sign == 0)
					sum += a[ind[i]].x;
				else
					sum -= a[ind[i]].x;
				sign ^= a[ind[i]].y;
			}
			ans += (sum%11 == 0);
		} while (next_permutation(ind, ind + n));
		cout << ans << '\n';
	}
}



/*

-----------------
input:          |

-----------------
output:         |

-----------------

*/