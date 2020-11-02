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
    } else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    } else return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 102;
int m, n, a[N][N];
int H[N], W[N];
int L[N][N], R[N][N];


#define id(X,Y) (m*(X-1)+Y)
#define row(X) (X/n + (X % n != 0))
#define col(X) ((X%m) + (X%m == 0)*n)
int x[21]; bool ok = false;
void Try(int idx) {
    if (idx > m*n) {
        FOR(i,1,m) {
            int cur_W = 0;
            FOR(j,1,n) cur_W += x[id(i,j)];
            if (cur_W != W[i]) return;
        }
        FOR(j,1,n) {
            int cur_H = 0;
            FOR(i,1,m) cur_H += x[id(i,j)];
            if (cur_H != H[j]) return;
        }
        ok = true;
        FOR(i,1,m) {
            FOR(j,1,n) cout << x[id(i,j)] << ' ';
            cout << endl;
        }
        return;
    }
    if (ok) return;
    int i = row(idx), j = col(idx);
    FOR(k,L[i][j],R[i][j]) {
        x[idx] = k;
        Try(idx+1);
    }
}

signed main(void) {
    FastIO;
    freopen("input.txt","r",stdin);
    cin >> m >> n;
    FOR(i,1,m) cin >> W[i];
    FOR(i,1,n) cin >> H[i];
    FOR(i,1,m) FOR(j,1,n) cin >> L[i][j];
    FOR(i,1,m) FOR(j,1,n) cin >> R[i][j];

    if (m * n <= 20) { // Subtask 1
        Try(1);
        exit(0);
    }

    return 0;
}