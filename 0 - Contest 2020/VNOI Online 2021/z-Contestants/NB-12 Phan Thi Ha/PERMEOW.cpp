#include <bits/stdc++.h>
using namespace std;
int a[2005],b[2005],dem,n,gt;
int main()
{
    freopen("PERMEOW.inp","r",stdin);
    freopen("PERMEOW.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++) cin>>b[i];
    dem=0;
    a[n+1]=1000000000;
    b[n+1]=1000000000;
    for (int i=1; i<=n; i++)
          for (int j=1; j<=n; j++)
              if (a[j]>a[j+1])
                  {
                     ++dem;
                     gt=a[j];
                     a[j]=a[j+1];
                     a[j+1]=gt;
                  }
    for (int i=1; i<=n; i++)
          for (int j=1; j<=n; j++)
              if (b[j]>b[j+1])
                  {
                     ++dem;
                     gt=b[j];
                     b[j]=b[j+1];
                     b[j+1]=gt;
                  }
    cout<<dem<<endl;

}
