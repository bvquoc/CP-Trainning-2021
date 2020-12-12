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

#define NO putchar('N')
#define YES putchar('Y')

const int N = 10004, INF = 2e18 + 7;
int n, a[N], q_sz, LIM;
bool ok;
int GCD[1003][1003];
int LCM[1003][1003];

void Try(const int &id) {
    if (ok) return;
    if (id > n) {
        FOR(i,1,n) FOR(j,1,n) {
            if (GCD[i][j] != -1 && __gcd(a[i], a[j]) != GCD[i][j]) return;
            if (LCM[i][j] != -1 && (1LL * a[i] * a[j] / __gcd(a[i], a[j])) != LCM[i][j]) return;
        }
        ok = true;
        return;
    }
    FOR(j,1,LIM) {
        a[id] = j;
        Try(id + 1);
    }
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("GCDLCM.INP","r",stdin);
    freopen("GCDLCM.OUT","w",stdout);
    #endif

    auto prepare = [&]() {
        FOR(i,1,n) FOR(j,1,n) {
            GCD[i][j] = -1;
            LCM[i][j] = -1;
        }
    };

    int subtask, T;
    cin >> subtask >> T;

    if (subtask == 1) {
        while (T--) {
            cin >> n >> q_sz;
            prepare();
            /* Read input */ {
                string s; int x, y, z;
                while (q_sz--) {
                    cin >> s >> x >> y >> z;
                    if (s == "GCD") GCD[x][y] = z;
                    else LCM[x][y] = z;
                }
            }
            
            LIM = 100;
            ok = false;
            Try(1);
            if (ok) YES;
            else NO;
        }
        exit(0);
    }

    while (T--) {
        /* Read input */ {
            cin >> n >> q_sz;
            string s; int x, y, z;
            while (q_sz--) {
                cin >> s >> x >> y >> z;
                if (s == "GCD") ;
                else ;
            }
        }
        
        ok = (subtask <= 3);
        if (ok) YES;
        else NO;
    }
    return 0;
}