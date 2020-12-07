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

const int N = 300005, INF = 1e9 + 7;
int n, q_sz, a[N];
pair <int, ii> q[N];



#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("RATING.INP","r",stdin);
    freopen("RATING.OUT","w",stdout);
    #endif

    /* Read INPUT */
    int T; Read(T);
    Read(n); Read(q_sz);
    FOR(i,1,n) Read(a[i]);
    FOR(i,1,q_sz) {
        Read(q[i].first);
        Read(q[i].second.first);
        Read(q[i].second.second);
    }
    
    #define EXIT exit(0)
    #define ENDL putchar('\n')

    if (T == 1) {
        ll x;
        FOR(idx,1,q_sz) {
            x = q[idx].first;
            FOR(i, q[idx].second.first,q[idx].second.second) x = Abs(x - a[i]);
            Write(x);
            ENDL;
        }
        EXIT;
    }

    if (T == 2) {
        FOR(i,2,n) a[i] += a[i-1];
        FOR(i,1,q_sz) {
            int l = q[i].second.first, r = q[i].second.second;
            ll x = q[i].first - (a[r] - a[l-1]);
            Write(x);
            ENDL;
        }
        EXIT;
    }

    if (T == 3) {
        auto getAns = [&](int &x, int &cnt) {
            if (x > a[1] * cnt) return x - a[1] * cnt;

            int res = 0, k = a[1];
            int lo = 0, hi = cnt, mi;
            while (lo <= hi) {
                mi = (lo + hi) >> 1;
                if (x > mi * k) {
                    res = mi;
                    lo = mi + 1;
                } else hi = mi - 1;
            }

            cnt -= res;
            x -= res * k;
            res = x;
            if (cnt & 1) res = k - x;
            
            return res;
        };

        int l, r, x, cnt;
        FOR(i,1,q_sz) {
            x = q[i].first;
            l = q[i].second.first, r = q[i].second.second;
            cnt = r - l + 1;
            Write(getAns(x, cnt));
            ENDL;
        }
    }

    /* Subtask 4 */ 
    ll x;
    FOR(idx,1,q_sz) {
        x = q[idx].first;
        FOR(i, q[idx].second.first,q[idx].second.second) x = Abs(x - a[i]);
        Write(x);
        ENDL;
    }
    
    return 0;
}



// struct Sum_ST {
//     int n;
//     vector<int> st;
//     vector<int> lazy;

//     Sum_ST(int _n = 0) {
//         n = _n;
//         st.assign(4 * n + 7, 0);
//         lazy.assign(4 * n + 7, 0);
//     }

//     void pushDown(int i) {
//         FOR(j, 2 * i, 2 * i + 1) {
//             st[j] += lazy[i];
//             lazy[j] += lazy[i];
//         }
//         lazy[i] = 0;
//     }

//     void update(int i, int l, int r, int u, int v, int c) {
//         if (l > v || r < u || l > r || v < u) return;
//         if (u <= l && r <= v) {
//             st[i] += c;
//             lazy[i] += c;
//             return;
//         }
//         pushDown(i);
//         int m = (l + r) >> 1, lf = i << 1, rt = lf + 1;
//         update(lf, l, m, u, v, c);
//         update(rt, m + 1, r, u, v, c);
//         st[i] = st[lf] + st[rt];
//     }
//     int getSum(int i, int l, int r, int u, int v) {
//         if (l > v || r < u || l > r || v < u) return 0;

//         if (u <= l && r <= v) return st[i];
//         pushDown(i);

//         int m = (l + r) >> 1, lf = i << 1, rt = lf + 1;
//         int L = getSum(lf, l, m, u, v);
//         int R = getSum(rt, m + 1, r, u, v);
//         return max(L, R);
//     }

//     void update(int u, int v, int c) { update(1, 1, n, u, v, c); }
//     int getSum(int u, int v) { return getSum(1, 1, n, u, v); }
// };