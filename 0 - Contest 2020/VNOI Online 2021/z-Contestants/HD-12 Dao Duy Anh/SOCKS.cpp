#include <bits/stdc++.h>
using namespace std;

int n,q;
int a[500005];
vector < int > g[500005];
int deg[500005];
int cl[500005];
int ans=0;
int res=0;

void sub1()
{
    for(int i=1;i<=n;++i)
        ans+=a[i];

    if(ans<=1)
        putchar('0');
    else
        putchar('1');

    putchar('\n');

    for(int i=1;i<=q;++i)
    {
        int u;

        scanf("%d ",&u);

        ans-=a[u];

        a[u]=1-a[u];

        ans+=a[u];

        if(ans<=1)
            putchar('0');
        else
            putchar('1');

        putchar('\n');
    }
}

void DFS(int u)
{
    cl[u]=1;

    for(auto &v : g[u])
    if(!cl[v])
    {
        DFS(v);
        deg[u]+=deg[v];
    }

    int ok=0;

    if(deg[u]>1)
        ok=1;

    ans+=deg[u]/2;

    deg[u]%=2;

    if(a[u]&&!ok)
        deg[u]=1;
}

void sub2()
{
    memset(cl,0,sizeof cl);
    memset(deg,0,sizeof deg);

    ans=0;

    DFS(1);

    if(res<=1)
        printf("0\n");
    else
        printf("%d\n",ans+deg[1]);

    for(int i=1;i<=q;++i)
    {
        int u;

        scanf("%d ",&u);

        res-=a[u];

        a[u]=1-a[u];

        res+=a[u];

        memset(deg,0,sizeof deg);
        memset(cl,0,sizeof cl);

        ans=0;

        DFS(1);

        if(res<=1)
            printf("0\n");
        else
            printf("%d\n",ans+deg[1]);
    }
}

int main ()
{
    freopen("SOCKS.inp","r",stdin);
    freopen("SOCKS.out","w",stdout);

    scanf("%d %d ",&n,&q);

    for(int i=1;i<=n;++i)
        scanf("%d ",&a[i]),res+=a[i];

    for(int i=1;i<n;++i)
    {
        int u,v;

        scanf("%d %d ",&u,&v);

        g[u].push_back(v);
        g[v].push_back(u);

        deg[u]++;
        deg[v]++;
    }

    int maxd=0;

    for(int i=1;i<=n;++i)
        maxd=max(maxd,deg[i]);

    if(maxd<=2)
        sub1();
    else
        sub2();
}
