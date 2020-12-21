#include <bits/stdc++.h>
#define mod 998244353
using namespace std;

int T;
int n,m;
int a[5005],b[5005],c[5005];
int cl[1505];
int kc[1505];
int ko[1505];
typedef pair < int , int > II;
#define fr first
#define sc second
set < II > s;
vector < int > g[1505];
int dp[1505][1505];
int dd[1505][1505];
int res[5005];

void dij()
{
    while(!s.empty())
    {
        auto it=s.begin();

        int u=(*it).sc;

        s.erase(it);

        for(auto &x : g[u])
        {
            int v=b[x];
            int l=c[x];

            if(!cl[v])
            {
                cl[v]=1;
                ko[v]=ko[u];
                kc[v]=kc[u]+l;
                s.insert(II(kc[v],v));
            }
            else
            if(kc[v]>kc[u]+l)
            {
                s.erase(II(kc[v],v));
                ko[v]=ko[u];
                kc[v]=kc[u]+l;
                s.insert(II(kc[v],v));
            }
            else
            if(kc[v]==kc[u]+l)
                ko[v]=(ko[v]+ko[u])%mod;
        }
    }
}

void sub1()
{
    for(int i=1;i<=m;++i)
    {
    int res=0;
    int u=a[i];
    int v=b[i];

    for(int i1=1;i1<=n;++i1)
    for(int j1=1;j1<=n;++j1)
    if(dp[i1][j1]==dp[i1][u]+c[i]+dp[v][j1])
    res=(res+(1ll*dd[i1][u]*dd[v][j1])%mod)%mod;

    printf("%d\n",res);
    }
}

void sol(int u, int v)
{
    cl[v]=1;
    ko[v]=1;

    for(auto &x : g[v])
    {
        int v1=b[x];

        if(!cl[v1])
        sol(u,v1);

        if(dp[u][v1]==dp[u][v]+c[x])
        {
            ko[v]=(ko[v]+ko[v1])%mod;

            res[x]=(res[x]+(1ll*dd[u][v]*ko[v1])%mod)%mod;
        }
    }
}

void sub2()
{
    for(int i=1;i<=n;++i)
    {
        memset(cl,0,sizeof cl);
        sol(i,i);
    }

    for(int i=1;i<=m;++i)
    printf("%d\n",res[i]);
}

int main ()
{
    freopen("CAULUONG.inp","r",stdin);
    freopen("CAULUONG.out","w",stdout);

    scanf("%d ",&T);

    scanf("%d %d ",&n,&m);

    for(int i=1;i<=m;++i)
    {
        scanf("%d %d %d ",&a[i],&b[i],&c[i]);

        g[a[i]].push_back(i);
    }

    for(int i=1;i<=n;++i)
    {
        memset(cl,0,sizeof cl);
        memset(kc,0,sizeof kc);
        memset(ko,0,sizeof ko);

        cl[i]=1;
        ko[i]=1;
        s.insert(II(0,i));

        dij();

        for(int j=1;j<=n;++j)
        dp[i][j]=kc[j],dd[i][j]=ko[j];
    }

    if(n<=300&&m<=1000)
    sub1();
    else
    sub2();
}
