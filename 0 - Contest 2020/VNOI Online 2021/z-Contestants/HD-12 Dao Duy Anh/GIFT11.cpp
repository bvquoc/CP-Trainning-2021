#include <bits/stdc++.h>
#define mod 998244353
using namespace std;

int T;
int n;
int a[2005],b[2005],c[2005];
int s[20],sn=0;
int res=0;
int dp[2005][1005][15];
int ans,ser,ok;
int cl[2005];

void pt(int u, int id)
{
    sn=0;
    a[id]=b[id]=c[id]=0;

    while(u>0)
        s[++sn]=u%10,u/=10;

    reverse(s+1,s+sn+1);

    c[id]=sn%2;

    for(int i=1;i<=sn;++i)
    if(i%2)
    b[id]=(b[id]+s[i])%11;
    else
    a[id]=(a[id]+s[i])%11;
}

void sub1()
{
    ser=0;

    for(int i=1;i<=n;++i)
    ser=(ser+a[i]-b[i]+11)%11;

    if(ser==0)
        ans=1;
    else
        ans=0;

    for(int i=1;i<=n;++i)
        ans=(1ll*ans*i)%mod;

    printf("%d\n",ans);
}

void sub2()
{
    memset(dp,0,sizeof dp);

    dp[0][0][0]=1;

    int hi=(n+1)/2;
    int lo=n/2;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=hi;++j)
        for(int z=0;z<11;++z)
        {
            int newz=(z+a[i]-b[i]+11)%11;
            dp[i][j][newz]=(dp[i][j][newz]+dp[i-1][j-1][z])%mod;
        }

        for(int j=0;j<=hi;++j)
        for(int z=0;z<11;++z)
        {
            int newz=(z+b[i]-a[i]+11)%11;
            dp[i][j][newz]=(dp[i][j][newz]+dp[i-1][j][z])%mod;
        }
    }

    ans=dp[n][hi][0];

    for(int i=1;i<=hi;++i)
    ans=(1ll*ans*i)%mod;

    for(int j=1;j<=lo;++j)
    ans=(1ll*ans*j)%mod;

    printf("%d\n",ans);
}

void TRY(int k)
{
    if(k>n)
    {
        if(ser==0)
            ans++;

        return;
    }

    for(int i=1;i<=n;++i)
    if(!cl[i])
    {
        cl[i]=1;

        if(!ok)
            ser=(ser+a[i]-b[i]+11)%11;
        else
            ser=(ser+b[i]-a[i]+11)%11;

        ok=(ok+c[i])%2;

        TRY(k+1);

        cl[i]=0;

        ok=(ok-c[i]+2)%2;

        if(!ok)
            ser=(ser-a[i]+b[i]+11)%11;
        else
            ser=(ser-b[i]+a[i]+11)%11;
    }
}

void sub3()
{
    ans=ok=ser=0;

    TRY(1);

    printf("%d\n",ans);
}

void sol()
{
    scanf("%d ",&n);

    res=0;

    for(int i=1;i<=n;++i)
    {
        int u;

        scanf("%d ",&u);

        pt(u,i);

        res+=c[i];
    }

    if(!res)
        sub1();
    else
    if(res==n)
        sub2();
    else
        sub3();
}

int main ()
{
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);

    scanf("%d ",&T);

    while(T--)
        sol();
}
