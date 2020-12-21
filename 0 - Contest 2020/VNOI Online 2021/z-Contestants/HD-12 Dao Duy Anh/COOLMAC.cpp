#include <bits/stdc++.h>
using namespace std;

int m,n;
typedef pair < int , int > II;
#define fr first
#define sc second
int minn=100001;
II a[100005];
int b[100005];
int dp[100005];
int ans;

void update(int u, int delta)
{
    while(u<=100001)
        b[u]=min(b[u],delta),u+=u&(-u);
}

int get(int u)
{
    int res=m+1;

    while(u>0)
        res=min(res,b[u]),u-=u&(-u);

    return res;
}

int main ()
{
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);

    scanf("%d ",&m);

    ans=m+1;

    for(int i=1;i<=m;++i)
        scanf("%d %d ",&a[i].fr,&a[i].sc),a[i].fr++,a[i].sc++;

    sort(a+1,a+m+1);

    scanf("%d ",&n);

    for(int i=1;i<=n;++i)
    {
        int u;

        scanf("%d ",&u);

        u++;

        minn=min(minn,u);
    }

    for(int i=1;i<=100001;++i)
        b[i]=m+1;

    for(int i=m;i>=1;--i)
    {
        if(a[i].sc==100001)
            dp[i]=1;
        else
            dp[i]=get(a[i].sc+1)+1;

        update(a[i].fr,dp[i]);

        if(a[i].fr<=minn)
            ans=min(ans,dp[i]);
    }

    if(ans==m+1)
        printf("-1");
    else
        printf("%d ",ans);
}
