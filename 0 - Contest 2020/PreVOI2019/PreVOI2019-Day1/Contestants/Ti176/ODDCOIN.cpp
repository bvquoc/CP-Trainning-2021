//Trương Minh Trí
#include <bits/stdc++.h>
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define FORN(i, x, y) for(int i = x; i >= y; --i)
#define Task "ODDCOIN"
#define maxn
#define maxm
#define pii pair <int, int>
#define pll pair <long long, long long>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
int q, x, t;
int c[20];
int dp[100005];
int res;
void Sub2()
{
    while(q--)
    {
        cin >> x >> t;
        FOR(i, 1, t) dp[i] = 2e9+1;
        c[16] = x;
        FOR(i, 1, 16)
            FOR(j, 1, t) if(j >= c[i]) dp[j] = min(dp[j], dp[j-c[i]] + 1);
        cout << dp[t] << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> q;
    c[1] = 1, c[2] = 3, c[3] = 5, c[4] = 10, c[5] = 30, c[6] = 50, c[7] = 100;
    c[8] = 300, c[9] = 500, c[10] = 1000, c[11] = 3000, c[12] = 5000, c[12] = 10000;
    c[14] = 30000, c[15] = 50000;
    Sub2();

}
