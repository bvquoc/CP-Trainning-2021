/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define X first
#define Y second
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
#define putENDL putchar(endl)
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

const int N = 500005;
int n, m, q[N];
bool isRed[N];
vector <int> adj[N];
ii e[N];

bool mark[N];
int d[N];
vector <int> child[N];

void DFS(const int &u, const int &p) {
    mark[u] = true;
    for (int v: adj[u]) if (!mark[v]) {
        DFS(v, u);
        child[u].push_back(v);
    }

    d[u] = child[u].size() + (p != -1);
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("SOCKS.INP","r",stdin);
    freopen("SOCKS.OUT","w",stdout);
    #endif
    
    Read(n); Read(q[0]);
    FOR(i,1,n) Read(isRed[i]);
    FOR(i,1,n-1) {
        Read(e[i].first);
        Read(e[i].second);
        adj[e[i].X].emplace_back(e[i].Y);
        adj[e[i].Y].emplace_back(e[i].X);
    }
    FOR(i,1,q[0]) Read(q[i]);

    DFS(1,-1);

    bool subtask_1 = *max_element(d + 1, d + 1 + n) <= 2;

    if (subtask_1) {
        int cnt_red = 0;
        FOR(i,1,n) if (isRed[i]) cnt_red++;

        putchar(cnt_red > 1 ? '1' : '0');
        putENDL;

        FOR(i,1,q[0]) {
            int u = q[i];
            if (isRed[u]) cnt_red--;
            else cnt_red++;
            isRed[u] = !isRed[u];

            putchar(cnt_red > 1 ? '1' : '0');
            putENDL;
        }

        exit(0);
    }

    bool subtask_2 = false;
    /* check subtask 2 */ {
        int cnt_3 = 0, cnt_less_2 = 0;
        FOR(i,1,n) if (d[i] == 3) cnt_3++;
        else if (d[i] <= 2) cnt_less_2++;
        if (cnt_3 + cnt_less_2 == n && cnt_3 == 1) subtask_2 = true;
    }

    if (subtask_2) {
        int root = 1;
        FOR(i,1,n) {
            mark[i] = false;
            if (d[i] == 3) root = i;
            child[i].clear();
        }
        DFS(root, -1);
        int x = -1, y = -1, z = -1;
        for (int i: child[root]) if (d[i] == 2) z = i;
        else {
            if (x == -1) x = 1;
            else y = i;
        }

        int cnt_red_lf = 0, cnt_red_rt = 0, cnt_red = 0;
        FOR(i,1,n) if (isRed[i]) {
            if (i == x) cnt_red_lf++;
            else if (i == y) cnt_red_rt++;
            else if (i != root) cnt_red++;
        }

        int res = 0;
        if (cnt_red_lf) {
            if (cnt_red_rt) res++;
            if (cnt_red) res++;
            if (!res && isRed) res = 1;
        } else if (cnt_red_rt) {
            if (isRed[root] || cnt_red) res = 1;
        } else {
            if ((int) cnt_red + isRed[root] > 1) res = 1;
        }
        Write(res);
        putENDL;

        FOR(i,1,q[0]) {
            int u = q[i];
            if (u == x) {
                if (isRed[u]) cnt_red_lf--;
                else cnt_red_lf++;
            } else if (u == y) {
                if (isRed[u]) cnt_red_rt--;
                else cnt_red_rt++;
            } else if (u != root) {
                if (isRed[u]) cnt_red--;
                else cnt_red++;
            }

            isRed[u] = !isRed[u];

            int res = 0;
            if (cnt_red_lf) {
                if (cnt_red_rt) res++;
                if (cnt_red) res++;
                if (!res && isRed) res = 1;
            } else if (cnt_red_rt) {
                if (isRed[root] || cnt_red) res = 1;
            } else {
                if ((int) cnt_red + isRed[root] > 1) res = 1;
            }
            Write(res);
            putENDL;
        }

        exit(0);
    }

    FOR(i,0,q[0]) {
        putchar('1');
        putENDL;
    }

    return 0;
}