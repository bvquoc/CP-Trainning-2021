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
#define sz(a) (int(a.size()))
#define BIT(a, i) (((a) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(a, i) ((a) | MASK(i))
#define turnOFF(a, i) ((a) & (~MASK(i)))
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
#define sqr(x) ((x)*(x))
#define endl '\n'
// #define int long long
using namespace std;

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

struct Data {
    int n; 
    vector <string> a;
} T[10];

const int N = 2003;
const int MOD = 998244353;

void back_tracking(const Data &T) {
    ll res = 0; string s;
    vector <int> id;
    REP(x, T.n) id.push_back(x);
    do {
        s = "";
        for (int x: id) s += T.a[x];

        ll cur = 0;
        REP(i, s.size()) if (i & 1) cur -= s[i] - '0';
        else cur += s[i] - '0';

        if (cur % 11 == 0) {
            res++;
            if (res >= MOD) res -= MOD;
        }
    } while (next_permutation(ALL(id)));
    Write(res);
    putchar(endl);
}

ll fact[N];

void doSub2(const Data &T) {
    ll res = -1;
    int n = T.n;

    ll sum = 0;
    REP(id,n) {
        REP(i, T.a[id].size()) if (i & 1) sum -= T.a[id][i] - '0';
        else sum += T.a[id][i] - '0';
    }

    if (sum % 11 == 0) res = fact[n];

    Write(res);
    putchar(endl);
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("GIFT11.INP","r",stdin);
    freopen("GIFT11.OUT","w",stdout);
    #endif
    
    int nTests; cin >> nTests;
    int S = 0;
    REP(i, nTests) {
        cin >> T[i].n;
        T[i].a.resize(T[i].n);
        for (string &x: T[i].a) cin >> x;
        S += T[i].n;
    }

    #define subtask_1 (S <= 8)
    if (subtask_1) {
        REP(i, nTests) back_tracking(T[i]);
        exit(0);
    }

    fact[0] = 1;
    FOR(i, 1, N-1) fact[i] = ((ll) fact[i-1] * i) % MOD;

    REP(id, nTests) {
        bool subtask_2 = true;
        REP(i, T[id].n) if (T[id].a[i].size() & 1) {
            subtask_2 = false;
            break;
        }
        
        if (subtask_2) doSub2(T[id]);
        else {
            putchar('0');
            putchar(endl);
        }
    }
    return 0;
}