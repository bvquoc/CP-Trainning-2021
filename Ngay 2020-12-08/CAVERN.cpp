/* Author: Bui Vi Quoc */
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
#define testBit(n, bit) (((n) >> (bit)) & 1LL)
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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

/*
(\_/)
( •_•)
/ >?? */

const int N = 3003;
int n, m, res = 0;
char a[N][N];
int b[N][N], psum[N][N];

bool isValid(const int &x, const int &y, const bool &checkInside) {
    if (x < 1 || x > n) return false;
    if (y < 1 || y > m) return false;
    if (checkInside) return true;
    return (a[x][y] == '.');
}

int sum(const int &x1, const int &y1, const int &x2, const int &y2) {
    if (!isValid(x1, y1, 1) || !isValid(x2, y2, 1)) return false;
    return psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1];
}

bool ok;

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("CAVERN.INP","r",stdin);
    freopen("CAVERN.OUT","w",stdout);
    #endif
    Read(n); Read(m);

    memset(a, '#', sizeof a);
    FOR(i,1,n) FOR(j,1,m) a[i][j] = '.';

    FOR(j,1,m) {
        int x; Read(x);
        FOR(i,1,x) a[i][j] = '#';
    }
    FOR(j,1,m) {
        int x; Read(x);
        FORD(i, n, n-x+1) a[i][j] = '#';
    }

    // FOR(i,0,n+1) {
    //     FOR(j,0,m+1) cout << a[i][j] << ' ';
    //     cout << endl;
    // }

    FOR(i,0,n+1) FOR(j,0,m+1) if (a[i][j] == '#') b[i][j] = 1;
    FOR(i,1,n) FOR(j,1,m) psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + b[i][j];
    
    // int lo = 1, hi = n;
    // while (lo <= hi) {
    //     int mi = lo + (hi - lo) / 2;
    //     ok = true;
    //     process(mi);
    //     if (ok) {
    //         lo = mi + 1;
    //     } else hi = mi - 1;
    // }

    res = INT_MAX;

    FOR(i,0,n+1) {
        FOR(j,0,m+1) cout << a[i][j] << ' ';
        cout << endl;
    }
    FOR(i,1,n) FOR(j,1,m) {
        int cur = 0;
        if (isValid(i, j, 0)) {
            FORD(u,n,i) {
                bool ok = false;
                FORD(v,m,j) if (isValid(u, v, 0)) {
                    if (sum(i,j,u,v) == 0) {
                        maximize(cur, (u - i + 1)*(v - j + 1));
                        cout << i << ' ' << j << ' ' << u << ' ' << v << endl;
                        cout << sum(i,j,u,v) << endl;
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
        }
        if (cur) minimize(res, cur);
    }
    cout << res;
    
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}