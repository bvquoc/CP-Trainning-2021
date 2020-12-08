#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int oo = 1e9+7;
char kq[1000060];
char Kq[1000060];
int n;
int par[1000060];
int dd[1000];
int root(int u)
{
     if(par[u] == u) return u;
     return par[u] = root(par[u]);
}
void Merge(int u,int v)
{
     int uu = root(u);
     int vv = root(v);
     if(u==v) return ;
     par[vv] = uu;
     return ;
}
void sub1()
{
     int cnt= 0 ;
    for(int i=1;i<=n;i++)
    {
         int type;
         cin >> type;
         if(type==1)
         {
              char cur;
              cin >> cur;
              Kq[++cnt] = cur;
         }
         else
         {
              char cur1,cur2 ;
              cin >> cur1 >> cur2 ;
              for(int i=1;i<=cnt;i++)
              {
                   if(Kq[i]==cur1) Kq[i] = cur2;
              }
         }
    }
   for(int i=1;i<=cnt;i++) cout << Kq[i] ;
}
void sub2()
{
     int cnt = 0;
     for(int i=1;i<=n;i++)
     {
          int type;
          cin >> type;
          if(type==1)
          {
               char cur;
               cin >> cur;
               ++cnt;
               par[cnt] = cnt;
               if(dd[(int)cur])
               Merge(dd[(int)cur],cnt);
               else{
                    dd[(int)cur] = cnt;
                    kq[cnt] = cur;
               }
          }
          else{
               char cur1,cur2;
               cin >> cur1 >> cur2 ;
               if(cur1==cur2) continue;
               Merge(dd[(int)cur2],dd[(int)cur1]);
               kq[dd[(int)cur1]]= '#';
               dd[(int)cur1] = 0;
               }
     }
     for(int i=1;i<=cnt;i++)
     {
          cout << kq[root(i)];
     }
}
int main()
{
     freopen("paint.inp","r",stdin);
     freopen("paint.out","w",stdout);
     ios_base::sync_with_stdio(false);cin.tie(nullptr);
     cin >> n;
    // sub1();
      sub2();
}
