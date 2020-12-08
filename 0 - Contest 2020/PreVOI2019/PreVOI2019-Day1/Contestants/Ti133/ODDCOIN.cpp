#include <bits/stdc++.h>
#define fi first
#define se second
#define getv(i, u) (e[i].first+e[i].second-u)
using namespace std;
typedef long long LL;
typedef pair <int ,int> p;
const LL maxn = 100 + 1e6 ,INF = 1e18;
LL n ,m ,ans = 0 ,t ,query;
LL a[maxn] ,dp[maxn];

void Process()
{
    a[1] = 1 ,a[2] = 3 ,a[3] = 5;
    for (int i = 4 ; i <= 15 ; ++i) {
         int j = (i % 3 == 0 ? 3 : i % 3);
         a[i] = a[j];
         for (int is = 1 ,Max = (i % 3 == 0 ? i / 3 - 1 : i / 3 ) ; is <= Max ; ++is)
              a[i] *= 10;
    }

return ;
}
void Solve1(LL t)
{
    for (int i = 1 ; i <= t ; ++i)   dp[i] = INF;
    dp[0] = 0;

    for (int i = 1 ; i <= t ; ++i)
    for (int j = 1 ; j <= 16 ; ++j)
         if (i >= a[j] && dp[i - a[j]] < INF)
             dp[i] = min(dp[i] ,dp[i - a[j]] + 1);

    cout << dp[t] << '\n';
return ;
}
void Solve2(LL t)
{
    LL res = t ,Max = min(1ll * 1000000 ,t);
    for (int i = 1 ; i <= Max ; ++i)     dp[i] = INF;
    dp[0] = 0;

    for (int i = 1 ; i <= Max ; ++i)
    for (int j = 1 ; j <= 16 ; ++j)
         if (i >= a[j] && dp[i - a[j]] < INF)
             dp[i] = min(dp[i] ,dp[i - a[j]] + 1);
//    cout << dp[58150] << '\n';
   // cout << Max << ' ' << t << '\n';
    if (Max == t)  {
        cout << dp[t] << '\n';
        return ;
    }
   // cout << 1 << '\n';
    for (int i = 2 ; i <= 16 ; ++i) {
         LL d = ((t - Max) % a[i] == 0 ? (t - Max) / a[i] : (t - Max) / a[i] + 1);
     //    if (i == 16) cout << d << '\n';
         LL r = t - a[i] * d;
         if (dp[r] < INF)
             res = min(res ,dp[r] + d);
    }

    cout << res << '\n';
return ;
}
void Read()
{
    cin >> query;
    Process();
    for (int i = 1 ; i <= query ; ++i) {
         int x;
         cin >> x >> t;
         a[16] = x;
      //   cout << t << '\n';
         if (t <= 1e5)    Solve1(t);
         else             Solve2(t);
    }

return ;
}
int main()  {
          #define TASK "ODDCOIN"
       freopen(TASK ".inp","r",stdin);
       freopen(TASK ".out","w",stdout);
           ios_base::sync_with_stdio(false);
           cin.tie(NULL);
           cout.tie(NULL);
      Read();

return 0;
}
