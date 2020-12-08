#include <bits/stdc++.h>
#define inf 1000000001
#define maxn 1000005
using namespace std;
int a[18];
int f[maxn];
int q;
int main()
{
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);
    scanf("%d",&q);
    a[1]=1;
    a[2]=3;
    a[3]=5;
    for (int i=4;i<=15;++i)
         a[i]=a[i-3]*10;
    int x,t;

    for (int i=1;i<=q;++i)
    {
        scanf("%d%d",&x,&t);
        a[16]=x;
        for (int j=1;j<=t;++j)
        {
            f[j]=inf;
            for (int k=1;k<=16;++k)
                if (a[k]<=j)
                   f[j]=min(f[j],f[j-a[k]]+1);
        }
        printf("%d\n",f[t]);
    }
}
