#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define reset(x) memset(x, 0, sizeof x)
#define MIN(x,y) {if (x > (y)) x = (y);}
#define MAX(x,y) {if (x < (y)) x = (y);}
#define remain(x) while (x >= MOD) x -= MOD
#define all(x) x.begin(), x.end()
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 100010
#define maxC INT_MAX
#define MOD 1000000007
#define ll long long
#define pii pair <int, int>
#define task "ODDCOIN"

using namespace std;

int a[20] = {0, 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000}, dp[maxn];
ll x, t;

void sub12()
{
    fill(dp, dp+maxn, maxC);
    FOR(i, 0, 16) dp[a[i]] = 1;
    FOR(i, 1, 16)
        FOR(j, 1, t) if (j >= a[i]) {MIN(dp[j], dp[j-a[i]] + 1);}
    cout << dp[t] << "\n";
}

//void sub()
//{
//    FOR(i, 1, 16) b[i] = a[i];
//    sort(b+1, b+17);
//    while(t)
//    {
//        int u = upper_bound(b+1, b+17, t) - b - 1;
//        FOR(i, 1, u)
//        {
//            int sl = t / v[u];
//            sub()
//        }
//        ans += sl;
//        t -= v[u]*sl;
//    }
//    return res;
//}

int main()
{
    ios_base:: sync_with_stdio(NULL);
    cin. tie(NULL) ; cout. tie(NULL);
    freopen(task".INP" , "r", stdin);
    freopen(task".OUT", "w", stdout);
    int q; cin >> q;
    while(q--)
    {
        cin >> x >> t;
        a[16] = x;
        sub12();
//        else
//            sub();
    }
    return 0;
}
