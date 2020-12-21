#include <bits/stdc++.h>
#define maxn 2005
using namespace std;
int a[maxn],n,b[maxn];
int main()
{
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);
    scanf("%d",&n);
     bool ok=true;
     bool ok2=true;
    for(int i=1; i<=n;i++) scanf("%d",&a[i]);
    for(int i=1; i<=n; i++) scanf("%d",&b[i]);
    for(int i=1; i<=n; i++){
        if(a[i]!=b[i]) ok=false;
        if(a[i]!=b[n-i+1]) ok2=false;
            }
    if(ok) { int dem=0;
        for(int i=1; i<=n-1; i++)
             for(int j=1; j<=n-1; j++)
             if(a[j]>a[j+1])
        {
             int tt=a[j];
                a[j]=a[j+1];
                a[j+1]=tt;
                ++dem;
        }
printf("%d",dem);}
 if(ok2)
     { int dem=0;
        for(int i=1; i<=n-1; i++)
             for(int j=1; j<=n-1; j++)
             if(b[j]>b[j+1])
        {
             int tt=b[j];
                b[j]=b[j+1];
                b[j+1]=tt;
                ++dem;
        }
  printf("%d",dem);}


}

