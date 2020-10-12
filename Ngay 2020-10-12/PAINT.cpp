#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
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
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 1003;
int n, m, h[N][N];
int res = 0;

// int calc_row(int a[], int n) {
//     stack <int> S;
//     vector <int> L(n+2), R(n+2);
//     stack <int> S;
//     for (int i=1;i<=n;++i) {
//         while (!S.empty() && a[S.top()]<=a[i]) S.pop();
//         L[i]=(S.empty() ? 0 : (S.top()));
//         L[i]++;
//         S.push(i);
//     }
//     while (!S.empty()) S.pop();
//     for (int i=n;i>=1;--i) {
//         while (!S.empty() && a[S.top()]<a[i]) S.pop();
//         R[i]=(S.empty() ? n+1 : S.top());
//         R[i]--; 
//         S.push(i);
//     }
//     FOR(i,1,n) {
//         cout << a[i] << ' ' << L[i] << ' ' << R[i] << endl;
//     }
// }
signed main(void) {
    FastIO;
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    Read(m); Read(n);
    FOR(i,1,m) FOR(j,1,n) {
        Read(h[i][j]);
        if (i == 1 || i == m) res += h[i][j];
        if (j == 1 || j == n) res += h[i][j];
    }
    res = 0;
    FOR(i,1,m) {
        h[i][n+1] = 0;
        res += h[i][1];
        FOR(j,1,n) {
            res += abs(h[i][j]-h[i][j+1]);
            res++;
        }
    }
    // calc_row(h[1], n);
    FOR(j,1,n) {
        h[m+1][j] = 0;
        res += h[1][j];
        FOR(i,1,m) {
            res += abs(h[i][j]-h[i+1][j]);
        }
    }
    Write(res);
    return 0;
}