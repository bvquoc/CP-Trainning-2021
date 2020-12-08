#include <bits/stdc++.h>
#define oo 1000000007
using namespace std;

int q;
int f[100005];
int a[20];
int x,t;

void sub1()
{
    int ans=oo;
    int k=0;

    while(t>=0)
    {
        ans=min(ans,k+f[t]);
        k++;
        t-=x;
    }

    printf("%d\n",ans);
}

void sub2()
{
    sub1();
}

int main ()
{
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);

    scanf("%d ",&q);

    a[1]=1;
    a[2]=3;
    a[3]=5;

    for(int i=4; i<=15; ++i)
        a[i]=a[i-3]*10;

    for(int i=1; i<=100005; ++i)
        f[i]=oo;

    for(int i=1; i<=15; ++i)
        for(int j=a[i]; j<=100000; ++j)
            f[j]=min(f[j],f[j-a[i]]+1);

    for(int i=1; i<=q; ++i)
    {
        scanf("%d %d ",&x,&t);

        if(x<=100005&&t<=100005)
            sub1();
        else
            sub2();
    }
}
