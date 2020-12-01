/* 𝙰𝚞𝚝𝚑𝚘𝚛: 𝙱𝚞𝚒 𝚅𝚒 𝚀𝚞𝚘𝚌 */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define X first
#define Y second
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORD(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
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

const int N = 100005, INF = 2e9 + 7;
int n, ptr = 1;

struct Point {
    int x, y;
    Point () { x = 0; y = 0; }
    Point (int _x, int _y) { x = _x; y = _y; }
    Point move(const Point &p) {
        return Point(x + p.x, y + p.y);
    }

    bool operator == (const Point &p) const { return (x == p.x && y == p.y); }
    bool operator < (const Point &p) const { return (y == p.y ? x < p.x : y < p.y); }
    bool operator != (const Point &p) const { return (x != p.x || y != p.y); }
} a[N];
istream& operator >> (istream &is, Point &p) { return is >> p.x >> p.y; }

bool check1(const Point &A, const Point &B) {
    if ((ll) A.x * B.x > 0) return false;
    return true;
}
bool check2(const Point &A, const Point &B) {
    if ((ll) A.y * B.y > 0) return false;
    return true;
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("SIMULATION.INP","r",stdin);
    freopen("SIMULATION.OUT","w",stdout);
    #endif
    cin >> n; a[0] = {1,1};
    FOR(i,1,n) cin >> a[i];
    
    int q; cin >> q;
    char type;
    
    
    while (q--) {
        cin >> type;
        if (type == 'C') {
            cin >> a[ptr];
            continue;
        }
        if (type == 'B') {
            if (ptr > 1) ptr--;
            continue;
        }
        if (type == 'F') {
            if (ptr < n) ptr++;
            continue;
        }

        /* 'Q' query */
        
        ll res = 0;
        Point A(1,1), B;

        FOR(i,1,n) {
            B = A.move(a[i]);
            if (check1(A, B)) res++;
            if (check2(A, B)) res++;
            // cout << A.x << ' ' << A.y << endl;
            // cout << B.x << ' ' << B.y << endl;
            // cout << res << endl;
            A = B;
        }
        // cout << "-----------------------\n";
        Write(res);
        putchar(endl);
    }

    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}


// const Point NA = Point(INF, INF);
// const Point LEFT = Point(-INF, 0);
// const Point RIGHT = Point(INF, 0);
// const Point UP = Point(0, INF);
// const Point DOWN = Point(0, -INF);