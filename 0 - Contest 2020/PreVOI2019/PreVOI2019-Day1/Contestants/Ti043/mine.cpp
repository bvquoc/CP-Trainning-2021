#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 2005

using namespace std;
int n, m, a[maxn], dp[maxn][maxn][2], ans, mod = 1000000003;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
     freopen("mine.inp", "r", stdin);
    freopen("mine.out", "w", stdout);
    cin >> n >> m;
    FOR(i, 1, 2*n) cin >> a[i];
        dp[1][1][0] = 1;
        FOR(i, 2, 2*n){
            FOR(k, 1, n){
                (dp[i][k][1] += dp[i-1][k][0] + dp[i-1][k+1][1]) %= mod;
                (dp[i][k][0] += dp[i-1][k-1][0] + dp[i-1][k-1][1]) %= mod;
            }
        }
        FOR(i, 1, n) (ans += dp[2*n][i][1]) %= mod;
        cout << ans;
    }



