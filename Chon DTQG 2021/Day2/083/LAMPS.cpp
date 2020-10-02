#include <bits/stdc++.h>
using namespace std;
int a[10000],n,t,x,y,z[10000],xx,reset=0;
bool b[10000],c[1000][1000];
int tf(int x)
 {
     if (x==0) return 1;
     return 0     ;
 }
bool blue(int x[])
 {

      for (int i=1;i<=n;i++)
        if (x[i]==0) return false;
      return true;
 }
int Try(int i, int  k,int n)
 {
     for (int j=1;j<=n;j++)
        if (!b[j])
     {
         b[j]=1;
         a[i]=j;
         if (i==k)
         {
          int x[10000];
          for (int i=1;i<=n;i++)
          x[i]=z[i];
              for (int i=1;i<=k;i++)
              {

                  if (a[i]==1 || a[i]==n)
                  {


                  if (a[i]==1)
                  {
                      x[a[i]]=tf(x[a[i]]);
                      x[a[i]+1]=tf(x[a[i]+1]);
                      x[n]=tf(x[n]);
                  }

                  if (a[i]==n)
                  {
                      x[a[i]]=tf(x[a[i]]);
                      x[a[i]-1]=tf(x[a[i]-1]);
                      x[1]=tf(x[1]);
                  }
                  }

         else
                  {
                      x[a[i]]=tf(x[a[i]]);
                      x[a[i]+1]=tf(x[a[i]+1]);
                      x[a[i]-1]=tf(x[a[i]-1]);
                  }
              }

              if (blue(x)) { cout<<k<<" ";

              for (int i=1;i<=k;i++) cout<<a[i]<<" ";
              cout<<endl;
              reset=1;
              return 0;
              }
           }
         else Try(i+1,k,n);
     b[j]=0;
     }
 }
 int main()
 {
    freopen("LAMP.INP","r",stdin);
    freopen("LAMP.OUT","w",stdout);
    cin>>n>>t;
    for (int i=1;i<=n;i++)
    {
        cin>>xx>>y;
        c[x][y]=true;
        c[y][x]=true;
    }
    while (t>0)
    {
          reset=0;
        t--;
         for (int i=1;i<=n;i++)
        cin>>z[i];
        for (int k=1;k<=n;k++)
     Try(1,k,4);
     if (!reset) cout<<-1<<endl;
    }
     return 0;
 }
