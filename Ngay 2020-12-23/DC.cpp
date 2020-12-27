/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define sz(a) (signed(a.size()))
#define BIT(a, i) (((a) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(a, i) ((a) | MASK(i))
#define turnOFF(a, i) ((a) & (~MASK(i)))
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
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

const int MAX = 100005;
ll res = 0;
int n, m, T, B;
int a[MAX], busStop[MAX];

int pos_near_L(const int &L, const int &R) {
    int p = -1;
    int lo = 0, hi = m, mi;
    while (lo <= hi) {
        int mi = (lo + hi) >> 1LL;
        if (busStop[mi] >= L) {
            if (busStop[mi] == L) return L;
            p = busStop[mi];
            hi = mi - 1;
        } else lo = mi + 1;
    }

    if (p > R) p = -1;
    return p;
}
int pos_near_R(const int &L, const int &R) {
    int p = -1;
    int lo = 0, hi = m, mi;
    while (lo <= hi) {
        int mi = (lo + hi) >> 1LL;
        if (busStop[mi] <= R) {
            if (busStop[mi] == R) return R;
            p = busStop[mi];
            lo = mi + 1;
        } else hi = mi - 1;
    }

    if (p < L) p = -1;
    return p;
}

int max_less(const int &X) {
    int p = -1;
    int lo = 0, hi = m, mi;
    while (lo <= hi) {
        int mi = (lo + hi) >> 1LL;
        if (busStop[mi] < X) {
            p = busStop[mi];
            lo = mi + 1;
        } else hi = mi - 1;
    }
    return p;
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("DC.INP","r",stdin);
    freopen("DC.OUT","w",stdout);
    #endif
    
    cin >> a[0] >> n >> m >> T >> B;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,m) cin >> busStop[i];

    a[++n] = a[0];
    a[0] = 1;
    busStop[0] = 1;
    busStop[++m] = a[n];
    sort(a, a + 1 + n);
    sort(busStop, busStop + 1 + m);

    FOR(i, 1, n) {
        ll cur = 1LL * (a[i] - a[i-1]) * T;
        
        /* Case 1 */ {
            int p1 = pos_near_L(a[i-1], a[i]);
            int p2 = pos_near_R(a[i-1], a[i]);
            if (p1 != p2) {
                ll d1 = 1LL * max(0LL, p1 - a[i-1]) * T;
                ll d2 = 1LL * max(0LL, a[i] - p2) * T;
                minimize(cur, d1 + d2 + B);
            }
        }
        

        /* Case 2 */ {
            int p1 = pos_near_L(a[i-1], a[i]);
            if (p1 != -1) {
                ll d1 = 1LL * max(0LL, p1 - a[i-1]) * T;
                int p2 = upper_bound(busStop, busStop + 1 + m, a[i]) - busStop;
                if (p2 <= m) {
                    p2 = busStop[p2];
                    ll d2 = 1LL * (p2 - a[i]) * T;
                    minimize(cur, d1 + d2 + B);
                }
            }
        }

        /* Case 3 */ {
            int p = max_less(a[i-1]);
            if (p != -1) {
                int d1 = 1LL * (a[i-1] - p) * T;
                int p2 = pos_near_R(a[i-1], a[i]);
                if (p2 != -1) {
                    ll d2 = 1LL * max(0LL, a[i] - p2) * T;
                    minimize(cur, d1 + d2 + B);
                }

                p2 = upper_bound(busStop, busStop + 1 + m, a[i]) - busStop;
                if (p2 <= m) {
                    p2 = busStop[p2];
                    ll d2 = 1LL * (p2 - a[i]) * T;
                    minimize(cur, d1 + d2 + B);
                }
            }
        }

        res += cur;
    }
    cout << res;
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}