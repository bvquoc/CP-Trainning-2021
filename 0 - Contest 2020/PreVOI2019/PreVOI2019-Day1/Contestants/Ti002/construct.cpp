#include <bits/stdc++.h>
using namespace std;

int T;
int n,m;
int a[100005];
int pre[100005];
int nex[100005];
int s[100005];
int sn=0;

void sol()
{
    scanf("%d %d ",&n,&m);

    for(int i=1; i<=n; ++i)
        scanf("%d ",&a[i]);

    for(int i=1; i<=m; ++i)
    {
        int loai,l,r,k;

        scanf("%d ",&loai);
        if(loai==1)
        {
            scanf("%d %d %d ",&l,&r,&k);

            for(int j=l; j<=r; ++j)
                a[j]+=k;
        }
        else
        {
            scanf("%d %d ",&l,&r);

            int ans=0;

            sn=0;

            for(int j=l; j<=r; ++j)
            {
                if(a[j]>=a[j-1]||j==l)
                    pre[j]=j;
                else
                {
                    int k;
                    while(sn>0&&a[s[sn]]>a[j])
                    {
                        k=s[sn];
                        sn--;
                    }

                    pre[j]=pre[k];
                }

                s[++sn]=j;
            }

            sn=0;

            for(int j=r; j>=l; --j)
            {
                if(a[j]>a[j+1]||j==r)
                    nex[j]=j;
                else
                {
                    int k;
                    while(sn>0&&a[s[sn]]>=a[j])
                    {
                        k=s[sn];
                        sn--;
                    }

                    nex[j]=nex[k];
                }

                s[++sn]=j;
            }

            for(int j=l; j<=r; ++j)
            {
                int hi=(pre[j]==l) ? 0 : a[pre[j]-1];
                int lo=(nex[j]==r) ? 0 : a[nex[j]+1];
                int k=max(hi,lo);
                ans+=a[j]-k;
            }

            printf("%d\n",ans);
        }
    }
}
int main ()
{
    freopen("CONSTRUCT.inp","r",stdin);
    freopen("CONSTRUCT.out","w",stdout);

    scanf("%d ",&T);

    while(T>0)
    {
        T--;
        sol();
    }
}
