#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const int N = 5003;
int n, c[N], dp[N][N][3];

signed main(void) {
    FastIO;
    freopen("FLOODFILL.INP","r",stdin);
    freopen("FLOODFILL.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) cin >> c[i];
    n = unique(c+1,c+1+n)-c-1;
    FORD(L,n,1) {
        dp[L][L][1] = dp[L][L][2] = 0; 
        FOR(R,L+1,n) {
            dp[L][R][1] = min(dp[L+1][R][1]+(c[L]!=c[L+1]), dp[L+1][R][2]+(c[L]!=c[R]));
            dp[L][R][2] = min(dp[L][R-1][1]+(c[L]!=c[R]), dp[L][R-1][2]+(c[R-1]!=c[R]));
        }
    }
    int res = min(dp[1][n][1],dp[1][n][2]);
    cout << res;
    return 0;
}