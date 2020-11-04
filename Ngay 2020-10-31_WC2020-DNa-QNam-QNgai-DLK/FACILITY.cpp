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
#define int long long
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

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 1000006;
int n, K, res = 0; 
struct data { 
    int s, d, r; 
    bool operator < (const data &b) { return d < b.d; }
} a[N];

pair<int, ii> save[N]; int sz = 0;
void compress(){
	FOR(i, 1, n) {
        save[++sz] = {a[i].s, {i, 1}};
		save[++sz] = {a[i].d, {i, 2}};
    }

	sort(save + 1, save + 1 + sz);

	int tmp = 0;
	FOR(i, 1, sz){
		if (i == 1 || save[i].fi != save[i - 1].fi) tmp++;
		if (save[i].se.se == 1) a[save[i].se.fi].s = tmp;
		else a[save[i].se.fi].d = tmp;
	}
}

int bit[N];
void update(int idx, int num){
	while (idx < N) {
        bit[idx] = max(bit[idx], num);
        idx += idx & -idx;
    }
}
int get(int idx){
	int ans = 0;
	while (idx) {
        maximize(ans, bit[idx]);
        idx -= idx & -idx;
    }
	return ans;
}

signed main(void) {
    FastIO;
    freopen("FACILITY.INP","r",stdin);
    freopen("FACILITY.OUT","w",stdout);
    Read(n); Read(K);
    FOR(i,1,n) {
        Read(a[i].s); Read(a[i].d); Read(a[i].r);
        a[i].d += a[i].s + K;
    }
    
    if (n <= 10) {
        sort(a+1, a+1+n);
        REP(state,MASK(n)) {
            int cur_cost = 0, cur_time = 0;
            FOR(i,1,n) if (BIT(state, i-1)) {
                if (a[i].s >= cur_time) {
                    cur_cost += a[i].r;
                    cur_time = a[i].d;
                }
            }
            maximize(res, cur_cost);
        }
        Write(res);
        exit(0);
    }

    compress();
    sort(a+1, a+1+n);
    FOR(i,1,n) {
		int st = a[i].s, en = a[i].d, c = a[i].r;
		int cost = c + get(st);
        res = max(res, cost);
		update(en, cost);
	}
    Write(res);
    return 0;
}