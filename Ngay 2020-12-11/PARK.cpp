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

const int numD = 4;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

/*
(\_/)
( •_•)
/ >?? */

const int N = 502, INF = 2e9, MOD = 1000000009;
int n, m, min_path = INF;
char a[N][N];

struct State { int u, v; ll d; };
bool operator < (const State &A, const State &B) { return A.d < B.d; }
map <State, ll> f;

ll res = 0;
int d[N][N];
bool mark[N][N];
ii T[N][N];

const ii NA = ii(-1, -1);

ll calc(const int &u, const int &v) {
    int cnt = 0;
    REP(i, numD) {
        int x = u + dx[i], y = v + dy[i];
        if (a[x][y] != 'X' && a[x][y] != '#' && !mark[x][y]) cnt++;
    }
    return cnt;
}

void dfs(const int &u, const int &v, const int &d) {
    if (a[u][v] == 'X') {
        if (d != min_path + 2) return;
        res++;
        if (res >= MOD) res -= MOD;
        return;
    }

    if (d >= min_path + 2) return;

    REP(i, numD) {
        int x = u + dx[i], y = v + dy[i];
        if (a[x][y] != '#' && !mark[x][y]) {
            T[x][y] = ii(u, v);
            mark[u][v] = true;
            dfs(x, y, d + 1);
            mark[u][v] = false;
        }
    }
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("PARK.INP","r",stdin);
    freopen("PARK.OUT","w",stdout);
    #endif

    ii START = ii(0,0), END = ii(0,0);
    cin >> n >> m;
    FOR(i,0,n+1) FOR(j,0,m+1) a[i][j] = '#';
    FOR(i,1,n) FOR(j,1,m) {
        cin >> a[i][j];
        if (a[i][j] == 'E') START = ii(i, j);
        if (a[i][j] == 'X') END = ii(i, j);
    }

    /* solve min_path */ {
        queue <ii> q;
        d[START.first][START.second] = 0;
        T[START.first][START.second] = ii(-1, -1);
        q.push(START);
        while (q.size()) {
            int u = q.front().first, v = q.front().second;
            q.pop(); mark[u][v] = true;

            if (a[u][v] == 'X') {
                min_path = d[u][v];
                break;
            }

            REP(i, numD) {
                int x = u + dx[i], y = v + dy[i];
                if (a[x][y] != '#' && !mark[x][y]) {
                    d[x][y] = d[u][v] + 1;
                    T[x][y] = ii(u, v);
                    q.push(ii(x, y));
                }
            }
        }
        if (min_path == INF) {
            putchar('0');
            exit(0);
        }
    }

    // FOR(i,1,n) FOR(j,1,m) mark[i][j] = false;
    // /* trace & calc */ {
    //     int x = T[END.first][END.second].first, y = T[END.first][END.second].second;
    //     while (ii(x, y) != NA) {
    //         cout << x << ' ' << y << endl;
    //         cout << calc(x, y) << endl;
    //         mark[x][y] = true;
    //         res = (res + calc(x, y)) % MOD;
    //         ii tmp = T[x][y];
    //         x = tmp.first;
    //         y = tmp.second;
    //     }
    // }

    FOR(i,1,n) FOR(j,1,m) mark[i][j] = false;
    mark[START.first][START.second] = true;
    T[START.first][START.second] = NA;

    dfs(START.first, START.second, 0);
    cout << res;
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}