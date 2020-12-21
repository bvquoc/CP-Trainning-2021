/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, A, B) for(int i=(A); i<=(B); i++)
#define FORD(i, A, B) for(int i=(A); i>=(B); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define sz(A) (int(A.size()))
#define BIT(A, i) (((A) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(A, i) ((A) | MASK(i))
#define turnOFF(A, i) ((A) & (~MASK(i)))
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
int n, m, p;

int f[MAX][MAX][MAX];

int dp(int i, int j, int k) {
    if (k == p) return INF;
    if (i >= m && j >= n) return 0;
    if (i > m || j > n) return INF;
    if (f[i][j][k] != -1) return f[i][j][k];
    
    int &res = f[i][j][k];
    res = INF;
    minimize(res, min({ dp(i + 1, j, k + (A[i] == C[k])) + 1, dp(i + (A[i] == B[j]), j + 1, k + (B[j] == C[k])) + 1}));
    return res;
}
void trace(int i, int j, int k) {
    if (i >= m && j >= n) return;
    if (dp(i, j, k)==dp(i+1, j, k+(A[i]==C[k]))+1) {
        cout << A[i];
        trace(i + 1, j, k + (A[i] == C[k]));
        return;
    }
    if (dp(i, j, k) == dp(i, j+1, k+(B[j]==C[k]))+1) {
        cout << B[j];
        trace(i, j + 1, k + (B[j] == C[k]));
        return;
    }
    if (A[i] == B[j] && dp(i, j, k) == dp(i+1, j+1, k+(A[i]==C[k])) + 1) {
        cout << A[i];
        trace(i + 1, j + 1, k + (A[i] == C[k]));
        return;
    }
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("XCKLT.INP","r",stdin);
    freopen("XCKLT.OUT","w",stdout);
    #endif
    cin >> A >> B >> C;
    m = A.size();
    n = B.size();
    p = C.size();

    FOR(i,0,m) FOR(j,0,n) FOR(k,0,p) f[i][j][k] = -1;

    int res = dp(0, 0, 0);
    if (res >= INF) {
        cout << "TRETRAU";
        exit(0);
    }

    cout << res << endl;
    trace(0, 0, 0);

    return 0;
}