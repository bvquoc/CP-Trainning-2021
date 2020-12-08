#include <bits/stdc++.h>
#define fi first
#define se second
#define getv(i, u) (e[i].first+e[i].second-u)
using namespace std;
typedef long long LL;
typedef pair <int ,int> p;
const LL maxn = 10 + 1e6 ,INF = 1e18;
LL n ,m ,ans = 0 ,query;
LL a[maxn] ,lazy[maxn * 4] ,f[maxn * 4];

void InIT(int id ,int l ,int r)
{
    if (l == r) {
        f[id] = a[l];
        return ;
    }
    int mid = (l + r) / 2;
    InIT(id * 2 ,l ,mid) ,InIT(id * 2 + 1 ,mid + 1 ,r);

    f[id] = f[id * 2] + f[id * 2 + 1];
return ;
}
void Dolazy(int id ,int l ,int r)
{
    if (! lazy[id]) return ;
    f[id] += lazy[id];
    if (l != r) {
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;

return ;
}
void Update(int id ,int l ,int r ,int L ,int R ,int delta)
{
    Dolazy(id ,l ,r);
    if (l > R || r < L)    return ;
    if (L <= l && r <= R)  {
        f[id] += delta;
        if (l != r) {
            lazy[id * 2] += delta;
            lazy[id * 2 + 1] += delta;
        }
        return ;
    }
    int mid = (l + r) / 2;
    Update(id * 2 ,l ,mid ,L ,R ,delta) ,Update(id * 2 + 1 ,mid + 1 ,r ,L ,R ,delta);

    f[id] = f[id * 2] + f[id * 2 + 1];
return ;
}
LL get(int id ,int l ,int r ,int pos)
{
   Dolazy(id ,l ,r);
   if (l > r || r < pos || l > pos) return 0;
   if (l == r && l == pos)          return f[id];
   int mid = (l + r) / 2;

   return max(get(id * 2 ,l ,mid ,pos) ,get(id * 2 + 1 ,mid + 1 ,r ,pos));
}
void Read()
{
    scanf("%lld" ,&query);
    for (int i = 1 ; i <= query ; ++i) {
         scanf("%lld%lld" ,&n ,&m);
         for (int i = 1 ; i <= n ; ++i)
              scanf("%lld" ,&a[i]);
         //fill(f + 1 ,f + 4 * n + 1 ,0);
         InIT(1 ,1, n);
         for (int i = 1 ; i <= m ; ++i) {
              int type ,l ,r ,delta;
              scanf("%lld%lld%lld" ,&type ,&l ,&r);
              if (type == 1) {
                  scanf("%lld" ,&delta);
                  Update(1 ,1 ,n ,l ,r ,delta);
              }
              else {
                  ans = 0;
                  int Pre = 0;
                  for (int j = l ; j <= r ; ++j) {
                       int Now = get(1 ,1 ,n ,j);
                       if (Pre > Now)
                           ans += Pre - Now;
                       Pre = Now;
                  }
                  ans += Pre;
                  printf("%lld\n" ,ans);
              }
         }
    }

return ;
}
int main()  {
          #define TASK "CONSTRUCT"
      freopen(TASK ".inp","r",stdin);
      freopen(TASK ".out","w",stdout);
           ios_base::sync_with_stdio(false);
           cin.tie(NULL);
           cout.tie(NULL);
      Read();

return 0;
}
