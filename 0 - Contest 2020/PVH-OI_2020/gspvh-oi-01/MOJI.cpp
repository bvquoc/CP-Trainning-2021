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

/*
(\_/)
( •_•)
/ >?? */

struct Edge { int u, v, w, id; };
struct DisjoinSet {
    int n; vector <int> par, height;
    void assign(int sz) {
        n = sz;
        par.assign(n+7, 0);
        height.assign(n+7, 0);
        for (int i=1; i<=n; i++) par[i] = i;
    }
    DisjoinSet () { assign(0); }
    DisjoinSet (int sz) { assign(sz); }

    int find(int node) {
        if (par[node] != node) par[node] = find(par[node]);
        return par[node];
    }

    bool join(int A, int B) {
        int rootA = find(A);
        int rootB = find(B);
        if (rootA == rootB) return false;

        if (height[rootA] == height[rootB]) height[rootA]++;
        if (height[rootA] < height[rootB]) par[rootA] = rootB;
        else par[rootB] = rootA;

        return true;
    }
} DSU;

const int N = 300005;
int n, k, m, p, t;
Edge e1[N], e2[N];
vector <int> MojiStore;

ll res = 0;
vector <int> ans1, ans2;
bool isStore[N];

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("MOJI.INP","r",stdin);
    freopen("MOJI.OUT","w",stdout);
    #endif
    
    /* Read INPUT */ {
        Read(t);
        Read(n);
        Read(k);
        MojiStore.resize(k);
        for (int &x: MojiStore) {
            Read(x);
            isStore[x] = true;
        }
        Read(m);
        FOR(i,1,m) {
            Read(e1[i].u); Read(e1[i].v); Read(e1[i].w);
            e1[i].id = i;
        }
        Read(p);
        FOR(i,1,p) {
            Read(e2[i].u); Read(e2[i].v); Read(e2[i].w);
            e2[i].id = i;
        }
    }

    DSU.assign(n);
    REP(i, ll(MojiStore.size()) - 1) DSU.join(MojiStore[i], MojiStore[i+1]);

    sort(e1 + 1, e1 + 1 + m, [](const Edge &A, const Edge &B) {
        return A.w > B.w || (A.w == B.w && A.id > B.id);
    });
    FOR(i,1,m) {
        int u = e1[i].u, v = e1[i].v;
        if (!DSU.join(u, v)) {
            res += e1[i].w * t;
            ans1.emplace_back(e1[i].id);
        }
    }

    sort(e2 + 1, e2 + 1 + p, [](const Edge &A, const Edge &B) {
        return A.w < B.w || (A.w == B.w && A.id < B.id);
    });
    FOR(i,1,p) {
        int u = e2[i].u, v = e2[i].v;
        if (DSU.join(u, v)) {
            res += e2[i].w * t;
            ans2.emplace_back(e2[i].id);
        }
    }

    sort(ALL(ans1));
    sort(ALL(ans2));

    Write(res); putchar(endl);
    Write(ans1.size()); putchar(endl);
    for (int x: ans1) {
        Write(x);
        putchar(' ');
    }
    putchar(endl);
    Write(ans2.size()); putchar(endl);
    for (int x: ans2) {
        Write(x);
        putchar(' ');
    }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}