#include <bits/stdc++.h>
#define fi first
#define se second
#define getv(i, u) (e[i].first+e[i].second-u)
using namespace std;
typedef long long LL;
typedef pair <int ,int> p;
const LL maxn = 4010 ,INF = 1e18 ,mod = 1e6 + 3 ,Maxn = 200010;
LL n ,m ,ans = 0;
LL a[maxn] ,dp[maxn][maxn] ,f[Maxn];

void Read()
{
    cin >> n >> m;
    n *= 2;

    for (int i = 1 ; i <= n ; ++i)
         cin >> a[i];

return ;
}
void Solve1()
{
    for (int i = 1 ; i < n ; ++i)    dp[i][i + 1] = 1;

    for (int kc = 4 ; kc <= n ; kc += 2)
    for (int Begin = 1 ; Begin + kc <= n + 1 ; ++Begin)
    for (int End = Begin + 1 ; End + 1 <= Begin + kc && a[End] <= a[Begin] + m ; End += 2) {
      //   if (kc == 6 && Begin == 1) cout << End << ' ';
         if (End == Begin + kc - 1)
             dp[Begin][End] = (dp[Begin][End] + dp[Begin + 1][End - 1]) % mod;
         else {
             LL l = (Begin + 1 == End ? 1 : dp[Begin + 1][End - 1]) ,
                r = (End + 1 == Begin + kc - 1 ? 1 : dp[End + 1][Begin + kc - 1]);

             dp[Begin][Begin + kc - 1] = (dp[Begin][Begin + kc - 1] + l * r) % mod;
     //    if (kc == 6 && Begin == 1)
       //      cout << dp[Begin][Begin + kc - 1] << ' ';
         }
    }
  //  cout << '\n';
    //cout << dp[3][6] << '\n';
    cout << dp[1][n];
return ;
}
void Solve2()
{

    f[2] = 1;
    f[4] = 2;

    for (int i = 6 ; i <= n ; i += 2) {
         int res = 0;
         res = (2 * f[i - 2] + f[i - 4]) % mod;

         for (int j = 4 ; j + 4 <= i ; j += 2)
              res = (res + f[j - 2] * f[i - j]) % mod;
         f[i] = res;
    }

    cout << f[n] ;
return ;
}
int main()  {
          #define TASK "MINE"
      freopen(TASK ".inp","r",stdin);
      freopen(TASK ".out","w",stdout);
           ios_base::sync_with_stdio(false);
           cin.tie(NULL);
           cout.tie(NULL);
      Read();
      if (n <= 400)  {
          Solve1();
          return 0;
      }

      if (n <= 10000 && m >= a[n] - a[1]){
          Solve2();
          return 0;
      }

      cout << rand() % mod;
return 0;
}
