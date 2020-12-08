// Nguyen Anh Tu
#include <bits/stdc++.h>
#define FOR(x,a,b) for(int x=a;x<=b;x++)
#define FORD(x,a,b) for(int x=a;x>=b;x--)
#define maxn 1000005
#define maxc 1000000007
#define MOD 1000000007
#define reset(x,y) memset(x,y,sizeof(x))
#define task "ODDCOIN"
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
#define remain(a,b) (a+b >= MOD) ? (a+b - MOD) : (a+b)

using namespace std;
int q,ans,x,t;
int a[maxn], dp[maxn];
int n = 15;
void trau()
{
    fill(dp+1,dp+t+1,INT_MAX);
    dp[0] = 0;
    for(int i=1; i <= n + 1; ++i)
        for(int j=a[i]; j<=t; ++j)
        {
            dp[j] = min(dp[j], dp[j-a[i]] + 1);
        }
    cout << dp[t] + ans << '\n';
}
int main()
{
    #ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    #endif
    a[1] = 1;
    a[2] = 3;
    a[3] = 5;
    for(int i = 1; i<=3; ++i)
        for(int j=1; j<=4; ++j)
        {
            a[i + 3 * j] = a[i + 3 * (j-1)] * 10;
        }
    cin >> q;
    for(int i=1; i<=n; ++i) s.insert(a[i]);
    while(q--)
    {
        ans = 0;
        cin >> x >> t;
        a[n+1] = x;
        if(t <= 1000000) trau();
        else
        {
            ans += t / 50000;
            t %= 50000;
            trau();
        }
    }
}
