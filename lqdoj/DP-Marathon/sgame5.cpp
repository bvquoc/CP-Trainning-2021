// http://lqdoj.edu.vn/problem/sgame5
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

const int N = 21;
int n, hv[N];
ld a[N][N], res = 0;

signed main(void) {
    FastIO;
    // freopen("input.txt","r",stdin);
    Read(n);
    FOR(i,1,n) {
        FOR(j,1,n) {
            Read(a[i][j]);
            a[i][j] /= 100.0;
        }
        hv[i] = i;
    }

    do {
        ld cur = 1;
        FOR(i,1,n) {
            cur *= a[i][hv[i]];
        }
        res = max(res, cur);
    } while(next_permutation(hv+1,hv+1+n));

    res *= 100;
    cout << fixed << setprecision(6) << res;
    return 0;
}