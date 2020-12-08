/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORD(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define sz(a) (signed(a.size()))
#define BIT(a, i) (((a) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(a, i) ((a) | MASK(i))
#define turnOFF(a, i) ((a) & (~MASK(i)))
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
        x = (x << 3) + (x << 1) + (c - '0');
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

const int N = 500005;
int n, a[N];
ll x, y;
ll res = LLONG_MAX;

int ch[20], b[20];
void Try(int id) {
    if (id > n) {
        vector <int> pos_del;
        FOR(i,1,n) if (ch[i] == 3) pos_del.push_back(i);
        if (sz(pos_del) > 1) FOR(i, pos_del[0], pos_del.back()) ch[i] = 3;

        ll cur_cost = 0;
        FOR(i,1,n) {
            if (ch[i] == 0) {
                b[i] = a[i];
                continue;
            }
            if (ch[i] < 3) {
                if (ch[i] == 1) b[i] = a[i] - 1;
                else b[i] = a[i] + 1;
                cur_cost += y;
                continue;
            }

            b[i] = 0;
            cur_cost += x;
        }

        int gcd = b[1];
        FOR(i,2,n) gcd = __gcd(gcd, b[i]);
        if (gcd > 1) minimize(res, cur_cost);
        // FOR(i,1,n) cout << ch[i] << ' '; cout << endl;
        // cout << cur_cost << ' ' << gcd << endl;
        return;
    }
    REP(i,4) {
        ch[id] = i;
        Try(id + 1);
    }
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("HSGS.INP","r",stdin);
    freopen("HSGS.OUT","w",stdout);
    #endif
    
    int T; Read(T);
    Read(n); Read(x); Read(y);
    FOR(i,1,n) Read(a[i]);

    #define EXIT exit(0)
    #define ENDL putchar('\n')

    // if (T == 2) {
    //     EXIT;
    // }
    if (T <= 4) {
        Try(1);
        if (res == LLONG_MAX) res = -1;
        Write(res);
        EXIT;
    }

    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}