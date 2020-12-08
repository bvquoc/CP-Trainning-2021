//Tran Thuy Duong
#include <bits/stdc++.h>
#define maxn 100005
#define maxc 1000000009
#define MOD 1000000007
#define task "ODDCOIN"
#define reset(x) memset(x, 0, sizeof x)
#define remain(x) ((x >= MOD) ? (x-MOD) : x)
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
const ll MM = 1ll * MOD * MOD;

int q, x, t, a[17];
void init()
{
    a[1] = 1; a[2] = 3; a[3] = 5;
    for (int i=4; i<=15; i++) a[i] = a[i-3] * 10;
}
int dp[maxn];
void brute_force()
{
    for (int i=1; i<=t; i++) dp[i] = MOD;
    dp[0] = 0; a[16] = x;
    for (int i=1; i<=16; i++)
        for (int x = a[i]; x<=t; x++)
            dp[x] = min(dp[x], dp[x - a[i]] + 1);
    cout << dp[t] << "\n";
}
void Solve()
{
    int ans = 0;
    for (int i=15; i>=1; i--)
    {
        if (a[i] > t) continue;
        if (a[i] < x)
        {
            ans += t / x;
            t %= x;
        }
        ans += t / a[i];
        t %= a[i];
    }
    cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(task".INP", "r", stdin);
	freopen(task".OUT", "w", stdout);
	init();
    cin >> q;
    while (q--)
    {
        cin >> x >> t;
        if (t <= 1e5) brute_force();
        else Solve();
    }
	return 0;
}
