// https://lqdoj.edu.vn/problem/chiatao
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
#define int long long
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

const int N = 1e5 + 5;
const int K = 105;
const int INF = 0x3f3f3f3f, LINF = 4557430888798830399;

int a[N], psum[N];
int L[N], minF[N];
int dp[K][N];
int n, m, k;
int mx[K][N];

int f(int cnt_gr, int j) {
    if (dp[cnt_gr][j] != LINF) return dp[cnt_gr][j];
    int &F = dp[cnt_gr][j];
}
signed main(void) {
    FastIO;
    freopen("input.txt","r",stdin);
    cin >> n >> m; k = min(n,100LL);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    int res = 0;
    FOR(i,1,k) res = maximize(res, psum[n] - f(i,n));
    cout << res;
    return 0;
}



// // https://lqdoj.edu.vn/problem/chiatao
// #include <bits/stdc++.h>
// #define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
// #define fi first
// #define se second
// #define FOR(i, a, b) for(int i=a; i<=b; i++)
// #define FORD(i, a, b) for(int i=a; i>=b; i--)
// #define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
// #define ALL(v) (v).begin(), (v).end()
// #define BIT(x, i) (((x) >> (i)) & 1)
// #define MASK(i) (1LL << (i))
// #define endl '\n'
// #define int long long
// using namespace std;

// template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
// template<class X, class Y>
// bool minimize(X &x, const Y &y) {
//     X eps = 1e-9;
//     if (x > y + eps) {
//         x = y;
//         return true;
//     } else return false;
// }
// template<class X, class Y>
// bool maximize(X &x, const Y &y) {
//     X eps = 1e-9;
//     if (x + eps < y) {
//         x = y;
//         return true;
//     } else return false;
// }

// using ii = pair <int, int>;
// using ll = long long;
// using ld = long double;

// const int N = 1e5 + 5;
// const int K = 105;
// const int INF = 0x3f3f3f3f;

// int a[N], psum[N];
// int L[N], minF[N];
// int dp[K][N];
// int n, m, k;
// int mx[K][N];

// signed main(void) {
//     FastIO;
//     freopen("input.txt","r",stdin);
//     cin >> n >> m; k = min(n,100LL);
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//         psum[i] = psum[i-1] + a[i];
//     }
//     memset(dp, 0x3f, sizeof dp);
//     dp[1][0] = 0; mx[1][0] = 0;
//     for (int i = 1; i <= n; ++i) {
//         dp[1][i] = max(dp[1][i-1], a[i]);
//         mx[1][i] = psum[i];
//     }
//     for (int i = 2; i <= k; ++i) {
//         stack<pair<int, int>> S;
//         for (int j = i; j <= n; ++j) {
//             int minF = dp[i - 1][j - 1];
//             mx[i][j] = 0;
//             while (!S.empty() && a[S.top().second] <= a[j]) {
//                 minF = min(minF, S.top().first);
//                 S.pop();
//             }
//             dp[i][j] = min(dp[i][S.empty() ? 0 : S.top().second], minF + a[j]);
//             S.push(make_pair(minF, j));
//         }
//     }
//     int res = 0, LEFT_LIM = 1, cur = 0;
//     FOR(i,1,n) {
//         if (cur + a[i] > m) {
//             LEFT_LIM++;
//             cur = 0;
//             continue;
//         }
//         cur += a[i];
//     }
//     FOR(i, LEFT_LIM, k) {
//         cout << i << endl;
//         if (mx[i][n] > m) continue;
//         maximize(res, psum[n]-dp[i][n]);
//     }
//     cout << res;
//     return 0;
// }