/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORD(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, rootB) for (__typeof((rootB).begin()) i = (rootB).begin(); i != (rootB).end(); ++i)
#define ALL(rootB) (rootB).begin(), (rootB).end()
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
    vector <bool> haveStore;
    void assign(int sz) {
        n = sz;
        par.assign(n+7, 0);
        height.assign(n+7, 0);
        haveStore.assign(n+7, 0);
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
        
        if (haveStore[rootA]) {
            haveStore[rootB] = true;
            haveStore[A] = haveStore[B] = true;
        }
        if (haveStore[rootB]) {
            haveStore[rootA] = true;
            haveStore[A] = haveStore[B] = true;
        }

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

ll res = LLONG_MAX;
vector <int> ans1, ans2;
bool x[20], mark[N], isStore[N];
vector <int> tplt[N];

bool check() {
    DSU.assign(n);
    FOR(i,1,n) {
        mark[i] = false;
        tplt[i].clear();
    }

    signed u, v;
    FOR(i,1,m) if (x[i]) {
        u = e1[i].u, v = e1[i].v;
        if (DSU.join(u, v)) {
            mark[u] = true;
            mark[v] = true;
        } else return false;
    }
    FOR(i,m+1,m+p) if (!x[i]) {
        u = e2[i-m].u, v = e2[i-m].v; 
        if (DSU.join(u, v)) {
            mark[u] = true;
            mark[v] = true;
        } else return false;
    }

    FOR(i,1,n) {
        if (!mark[i]) return false;
        tplt[DSU.find(i)].emplace_back(i);
    }

    int sz = 0;
    FOR(i,1,n) {
        if (tplt[i].empty()) continue;
        sz++;
        int cnt = 0;
        for (int x: tplt[i]) if (isStore[x]) cnt++;
        if (cnt != 1) return false;
    }

    return (sz > 0);
}

void Try(int i) {
    if (i > m + p) {
        int cnt = 0;
        FOR(j,1,m) if (x[j]) cnt++;
        FOR(j,m+1,m+p) if (!x[j]) cnt++;
        if (cnt > (n-1)) return;

        cnt = 0;
        FOR(j,1,m) if (!x[j]) cnt += t * e1[j].w;
        FOR(j,m+1,m+p) if (!x[j]) cnt += t * e2[j-m].w;
        // cout << cnt << endl;

        if (cnt > res) return;

        if (check() && minimize(res, cnt)) {
            ans1.clear(); ans2.clear();
            FOR(j,1,m) if (!x[j]) ans1.emplace_back(j);
            FOR(j,m+1,m+p) if (!x[j]) ans2.emplace_back(j-m);
        }

        return;
    }
    REP(j,2) {
        x[i] = j;
        Try(i+1);
    }
}

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

    #define subtask_1 (n <= 17 && m + p <= 17)
    #define subtask_2 (k == 1 && m == 0)
    #define subtask_3 (p == 0)

    if (subtask_2) {
        sort(e2 + 1, e2 + p + 1, [](const Edge &A, const Edge &B){
            return (A.w < B.w || (A.w == B.w && A.id < B.id));
        });

        ll res = 0;
        vector <int> ans;
        
        DSU.assign(n);
        FOR(i,1,p) {
            if (DSU.join(e2[i].u, e2[i].v)) {
                res += t * e2[i].w;
                ans.emplace_back(e2[i].id);
            }
        }
        sort(ALL(ans));

        Write(res); putchar(endl);
        putchar('0'); putchar(endl); putchar(endl);
        Write(ans.size()); putchar(endl);
        for (int x: ans) {
            Write(x);
            putchar(' ');
        }
        exit(0);
    }
    
    if (subtask_1) {
        Try(1);
        sort(ALL(ans1)); sort(ALL(ans2));

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
        exit(0);
    }

    if (subtask_3) {
        sort(e1 + 1, e1 + m + 1, [](const Edge &A, const Edge &B) {
            if ((isStore[B.u] || isStore[B.v]) && (isStore[A.u] || isStore[A.v])) return (A.w > B.w || (A.w == B.w && A.id > B.id));
            if (isStore[A.u] || isStore[A.v]) return true;
            if (isStore[B.u] || isStore[B.v]) return false;
            return (A.w > B.w || (A.w == B.w && A.id > B.id));
        });

        DSU.assign(n);
        for (int x: MojiStore) DSU.haveStore[x] = true;

        FOR(i,1,m) {
            signed u = e1[i].u, v = e1[i].w;
            signed r_u = DSU.find(u), r_v = DSU.find(v);
            if (r_u == r_v) continue;
            if (DSU.haveStore[r_u] && DSU.haveStore[r_v]) continue;

            DSU.join(u, v);
            mark[i] = true;
        }

        res = 0;
        FOR(i,1,m) if (!mark[i]) {
            ans1.emplace_back(e1[i].id);
            res += e1[i].w * t;
        }

        sort(ALL(ans1));

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
    }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}