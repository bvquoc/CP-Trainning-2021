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

struct TQuery { int x, y, u, v, id; };

const int N = 100005, M = 5;
int m = 3, n, q_sz;
int a[M][N];
TQuery q[N];

int psum[M][N];
int sum(const int &row, const int &l, const int &r) {
    return psum[row][r] - psum[row][l-1];
}

int ans[N];
int d[M][N];
bool mark[M][N];

bool isValid(const int &x, const int &y) {
    if (x < 1 || x > m) return false;
    if (y < 1 || y > n) return false;
    return true;
}

void dfs(const int &u, const int &v, const int &MAX_LEN, const int &cur_d) {
    REP(i, 4) {
        int x = dx[i] + u, y = dy[i] + v;
        if (!isValid(x, y)) continue;
        if (!mark[x][y] && cur_d < MAX_LEN) {
            mark[x][y] = true;
            maximize(d[x][y], d[u][v] + a[x][y]);
            dfs(x, y, MAX_LEN, cur_d + 1);
            mark[x][y] = false;
        }
    }
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("BONUS3ROWS.INP","r",stdin);
    freopen("BONUS3ROWS.OUT","w",stdout);
    #endif
    
    Read(n); Read(q_sz);
    FOR(i,1,m) FOR(j,1,n) {
        Read(a[i][j]);
        psum[i][j] = psum[i][j-1] + a[i][j];
    }

    FOR(i,1,q_sz) {
        Read(q[i].x); Read(q[i].y);
        Read(q[i].u); Read(q[i].v);
        q[i].id = i;
        
        if (Abs(q[i].x - q[i].u) < 2) {
            if (q[i].x == q[i].u) {
                int l = q[i].y, r = q[i].v;
                if (l > r) swap(l, r); 
                ans[i] = sum(q[i].x, l, r);
            } else {
                if (q[i].x > q[i].u) {
                    swap(q[i].x, q[i].u);
                    swap(q[i].y, q[i].v);
                }
                continue;
            }
            q[i].x = q[i].u = m + 1;
            q[i].y = q[i].v = n + 1;
            q[i].id = 0;
        }
    }

    sort(q + 1, q + 1 + q_sz, [](const TQuery &A, const TQuery &B) {
        return A.x < B.x;
    });

    int k;
    FOR(i,1,q_sz) if (q[i].x > m) {
        k = i-1;
        break;
    }

    FOR(i,1,k) {
        REP(i, M) FOR(j, 0, n+1) {
            mark[i][j] = false;
            d[i][j] = LLONG_MIN;
        }

        int x = q[i].x, y = q[i].y;
        int u = q[i].u, v = q[i].v;

        d[x][y] = a[x][y];
        dfs(x, y, Abs(x - u) + Abs(y - v), 0);
        ans[q[i].id] = d[u][v];
    }

    #define ENDL putchar('\n')
    FOR(i,1,q_sz) {
        Write(ans[i]);
        ENDL;
    }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}