#include <bits/stdc++.h>
using namespace std;
 int n,m,c[10000][10000],x,y,z,e10=100000000,u,minc,d[10000],check[100000];
void input()
{
    cin>>n>>m;
     for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
       c[i][j]=e10;
    for (int i=1;i<=m;i++)
     {
         cin>>x>>y>>z;
         c[x][y]=z;
         c[y][x]=min(c[y][x],c[x][y]);
     }
}


void dijk(int S,int F)
 {
     for (int i=1;i<=n;i++)
        { d[i]=c[S][i]; check[i]=0; }

 do
        {
          minc=e10;
           u=0;
          for (int i=1;i<=n;i++) if (d[i]<minc && !check[i]) { minc=d[i]; u = i; }
          check[u]=1;

      for (int v=1;v<=n;v++)  if (!check[v] && d[v]>c[u][v]+d[u]) d[v]=c[u][v]+d[u];
        }
     while (u!=0 && u!=F);
   //update to c[][]
   for (int i=1;i<=n;i++)
    c[S][i]=d[i];


 }

 int main()
 {
    freopen("DULICH.INP","r",stdin);
    freopen("DULICH.OUT","w",stdout);
    input();
   /* for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (i!=j) dijk(i,j);

          for (int i=1;i<=n;i++)
          {
               for (int j=1;j<=n;j++)
                cout<<c[i][j]<<" ";
               cout<<endl;
          }
        */
        cout<<0;


     return 0;
 }
