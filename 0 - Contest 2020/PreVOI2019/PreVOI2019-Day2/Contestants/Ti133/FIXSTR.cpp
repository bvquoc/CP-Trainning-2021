#include <bits/stdc++.h>
#define fi first
#define se second
#define getv(i, u) (e[i].first+e[i].second-u)

using namespace std;
typedef long long LL;
typedef pair <int ,int> p;
const LL maxn = 10 + 1e6;
LL n ,m ,ans = 0 ,query;
LL a[maxn];
string s;
vector <int> g[maxn];

void Read()
{
    cin >> s;
    n = s.size();
    for (int i = 1 ; i <= n ; ++i) {
         char ch = s[i - 1];
         if (ch == '(')  a[i] = 1;
         else            a[i] = -1;
         g[0].push_back(a[i]);
    }

    cin >> query;
return ;
}
LL getans(int l ,int r)
{  LL sum = 0 ,res = 0;
   for (int i = l ; i <= r ; ++i) {
        if (a[i] > 0 && sum >= 0) {
            sum += a[i];
            continue ;
        }
        if (a[i] > 0 && sum < 0) {
            res += -sum;
            sum = a[i];
            continue ;
        }
        sum += a[i];
   }

   res += abs(sum);
   return res;
}
void Solve1()
{
    for (int i = 1 ; i <= query ; ++i) {
         char type ;
         int posc ,posu ,l ,r;
         cin >> type;
         if (type == 'C') {
             cin >> posc;
             a[posc] = -a[posc];
             for (int j = 1 ; j <= n ; ++j)
                  g[i].push_back(a[j]);
             continue ;
         }
         if (type == 'U') {
             cin >> posu;
             for (int j = 1 ; j <= n ; ++j)
                  a[j] = g[posu - 1][j - 1];
             continue ;
         }
         cin >> l >> r;
       //  cout << l << ' ' << r << '\n';
         cout << getans(l ,r) << '\n';
         for (int j = 1 ; j <= n ; ++j)
              g[i].push_back(a[j]);
    }

return ;
}

int main()  {
          #define TASK "FIXSTR"
      freopen(TASK ".inp","r",stdin);
      freopen(TASK ".out","w",stdout);
           ios_base::sync_with_stdio(false);
           cin.tie(NULL);
           cout.tie(NULL);
      Read();

      Solve1();

return 0;
}


