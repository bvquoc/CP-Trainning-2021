#include <bits/stdc++.h>
#define mod 1000003
using namespace std;

int n,m;
int a[400005];
int s[25];
int sn=0;
int k[400005];
int ans=0;
int f[2005][2005];
int d[405][405][405];

void TRY(int u)
{
    if(u==2*n+1)
    {
        sn=0;

        for(int i=1; i<=2*n; ++i)
        {
            if(k[i]==1)
                s[++sn]=i;
            else
            {
                if(sn>0&&a[i]-a[s[sn]]<=m)
                    sn--;
                else
                    return;
            }
        }

        if(sn==0)
            ans+=1;

        return;
    }

    k[u]=1;

    TRY(u+1);

    k[u]=-1;

    TRY(u+1);
}

void sub1()
{
    ans=0;

    TRY(1);

    printf("%d",ans%mod);
}

void sub2()
{
    f[0][0]=1;

    for(int i=1; i<=2*n; ++i)
        for(int j=0; j<=2*n; ++j)
        {
            if(j<2*n)
                f[i][j]=f[i-1][j+1];

            if(j>0)
                f[i][j]=(f[i][j]+f[i-1][j-1])%mod;
        }

    printf("%d ",f[n][0]);
}

void sub3()
{
    d[0][0][0]=1;

    for(int i=1; i<=2*n; ++i)
    {
        for(int j=1; j<=i; ++j)
            for(int p=0; p<i; ++p)
                if(a[i]-a[p+1]<=m)
                {
                    if(j<i)
                        d[i][j][p]=d[i-1][j+1][p];
                    if(j>=1)
                        d[i][j][p]=(d[i][j][p]+d[i-1][j-1][p])%mod;
                }

        for(int p=0; p<i; ++p)
            if(a[i]-a[p+1]<=m)
                d[i][0][i]=(d[i][0][i]+d[i-1][1][p])%mod;
    }

    printf("%d",d[2*n][0][2*n]);
}

void sub4()
{
    sub2();
}

int main ()
{
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);

    scanf("%d %d ",&n,&m);

    for(int i=1; i<=2*n; ++i)
        scanf("%d ",&a[i]);

    if(n<=10)
        sub1();
    else if(n<=200&&m==1000000)
        sub2();
    else if(n<=2000)
        sub3();
    else
        sub4();
}
