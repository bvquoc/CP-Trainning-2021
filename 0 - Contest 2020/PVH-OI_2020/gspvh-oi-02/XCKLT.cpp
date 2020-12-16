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

const int MAX = 502, INF = 1e9;
string A, B, C;
string ans = "";
int f[MAX][MAX][MAX];

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("XCKLT.INP","r",stdin);
    freopen("XCKLT.OUT","w",stdout);
    #endif
    cin >> A >> B >> C;
    int m = A.size();
    int n = B.size();
    int p = C.size();
    A = '*' + A + '*';
    B = '*' + B + '*';
    C = '*' + C + '*';

    memset(f, 0x3f, sizeof f);
    f[0][0][0] = 0;

    FOR(i,0,m) FOR(j,0,n) FOR(k,0,p) if (f[i][j][k] < INF) {
        REP(t, 2) {
            char tmp = (t ? A[i+1] : B[j+1]);
            if (tmp == '*') continue;

            int newI = (tmp == A[i+1] ? i + 1 : i);
            int newJ = (tmp == B[j+1] ? j + 1 : j);
            int newK = (tmp == C[k+1] ? k + 1 : k);
            if (newK < p) {
                if (minimize(f[newI][newJ][newK], f[i][j][k] + 1)) {

                }
            }
        }
    }

    int res = *min_element(f[m][n], f[m][n] + p);
    if (res > INF) {
        cout << "TRETRAU";
        exit(0);
    }

    

    cout << res << endl;
    cout << ans;

    return 0;
}