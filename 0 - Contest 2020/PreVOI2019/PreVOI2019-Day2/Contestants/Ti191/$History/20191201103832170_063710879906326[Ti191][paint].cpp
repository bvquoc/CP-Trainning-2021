#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define maxn 1000001
using namespace std;
int n,q,a[maxn];

void sub1()
{
     while(q--)
     {
          int id;
          char x,y;
          cin>>id;
          if(id==1)
          {
               cin>>x;
               a[++n]=x;
          }
          else
          if(id==2)
          {
               cin>>x>>y;
               rep(i,1,n) if(a[i]==x) a[i]=y;
          }
     }
     rep(i,1,n) cout<<char(a[i]);
}

vector<int> s[30+'a'];
void sub2()
{
     int n=0;
     while(q--)
     {
          int id;
          char x,y;
          cin>>id;
          if(id==1)
          {
               n++;
               cin>>x;
               s[x].push_back(n);
          }
          else
          if(id==2)
          {
               cin>>x>>y;
               for(auto i : s[x]) s[y].push_back(i);
               s[x].clear();
          }
     }

     rep(color,'a','z')
     for(auto id : s[color]) a[id]=color;

     rep(i,1,n) cout<<char(a[i]);
}
int main()
{
     freopen("paint.inp","r",stdin);
     freopen("paint.out","w",stdout);
     ios_base::sync_with_stdio(0);cin.tie(0);

     cin>>q;n=0;

     if(q<=10001)
     {
          sub1();
          return 0;
     }else sub2();
}
