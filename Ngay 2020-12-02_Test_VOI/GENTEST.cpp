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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

/*
(\_/)
( •_•)
/ >?? */

const int MAX = 100005;
const int N = 10000007;
int n, m, M, d[MAX];

int st[4 * N], child[4 * N][2];
int sz = 1;
int child_id(int idx, bool right) {
    if(child[idx][right] == 0) child[idx][right] = ++sz;
    return child[idx][right];
}

void update(int id, int l, int r, int pos, int val) {
    if(pos < l || r < pos) return;
    if(l == r) {
        st[id] = val;
        return ;
    }
    int mid = (l + r) / 2, lf = child_id(id, false), rt = child_id(id, true);
    update(lf, l, mid, pos, val);
    update(rt, mid + 1, r, pos, val);
    st[id] = st[lf] + st[rt];
}

int getPos(int id, int l, int r, int val) {
    if(l == r) return l;

    int mid = (l + r) >> 1LL;
    int lf = child_id(id, false), rt = child_id(id, true);

    if((mid - l + 1) + st[lf] < val) return getPos(rt, mid + 1, r, val - (mid - l + 1 + st[lf]));
    return getPos(lf, l, mid, val);
}

ii findComp(int pos) {
    int lo, hi, mi, u, v;

    lo = 1; hi = n - 1;
    while (lo <= hi) {
        mi = (lo + hi) >> 1;
        int k = n - mi;
        k = k * (k + 1) / 2;
        k = M - k;
        if (k < pos) {
            u = mi;
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    lo = u+1; hi = n;
    int k = (n - u); k = M - (k * (k + 1) / 2);
    while (lo <= hi) {
        mi = (lo + hi) / 2;
        if (mi - u + k == pos) {
            v = mi;
            break;
        }
        if (mi - u + k < pos) lo = mi + 1;
        else hi = mi - 1;
    }
    
    return ii(u, v);
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("GENTEST.INP","r",stdin);
    freopen("GENTEST.OUT","w",stdout);
    #endif
    Read(n); Read(m); M = (int) n * (n - 1) >> 1;
    FOR(i,1,m) Read(d[i]);

    int LIM = (int) n * n;
    FOR(i,1,m) {
        int k = getPos(1, 1, LIM, d[i]);
        ii p = findComp(k);
        Write(p.first); putchar(' ');
        Write(p.second); putchar(endl);
        update(1, 1, LIM, k, -1);
    }
    return 0;
}