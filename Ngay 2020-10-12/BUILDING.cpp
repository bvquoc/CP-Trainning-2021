#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

const int N = 1003;
int m, n, h[N][N];
int row[N], col[N];
bool mark[N][N];

signed main(void) {
    FastIO;
    freopen("BUILDING.INP","r",stdin);
    freopen("BUILDING.OUT","w",stdout);
    Read(m); Read(n);
    FOR(i,1,m) FOR(j,1,n) Read(h[i][j]);

    FOR(i,1,max(m,n)) row[i] = col[i] = 0;
    FOR(i,1,m) {
        FOR(j,1,n) {
            if (h[i][j] >= row[i]) {
                mark[i][j] = true;
                row[i] = h[i][j];
            }
            if (h[i][j] >= col[j]) {
                mark[i][j] = true;
                col[j] = h[i][j];
            }
        }
    }

    FOR(i,1,max(m,n)) row[i] = col[i] = 0;
    FORD(i,m,1) {
        FORD(j,n,1) {
            if (h[i][j] >= row[i]) {
                mark[i][j] = true;
                row[i] = h[i][j];
            }
            if (h[i][j] >= col[j]) {
                mark[i][j] = true;
                col[j] = h[i][j];
            }
        }
    }

    int res = 0;
    FOR(i,1,m) FOR(j,1,n) if (!mark[i][j]) res++;
    printf("%d", res);
    return 0;
}