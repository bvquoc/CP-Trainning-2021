#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ii pair <int,int>
#define pl pair <ll,ll>
#define fr(i,x,y) for (int i=x;i<=y;i++)
#define ft(i,x,y) for (int i=y;i>=x;i--)
#define N 100005
using namespace std ;
int n,m,T;
ll a[100001],b[100001];
void inp()
{
    freopen("construct.inp","r",stdin) ;
    freopen("construct.out","w",stdout);
    scanf("%d",&T);
}
void xuli()
{
    scanf("%d%d",&n,&m);
    fr(i,1,n)
    {
        scanf("%d",&a[i]);
    }
    fr(i,1,m)
    {
        int tv,u,v,w ;
        ll ans= 0 ;
        int dem = 0 ;
        scanf("%d",&tv);
        if (tv==1)
        {
            scanf("%d%d%d",&u,&v,&w) ;
            fr(i,u,v) a[i]+=w ;
        }
        else
        {
            fr(i,1,n)
            {
                b[i] =a[i];
            }
            scanf("%d%d",&u,&v);
            while(true)
            {
                int maxn = INT_MAX;
                int vt=0 ;
                fr(i,1,n)
                {
                    if (a[i]>0 and maxn>a[i])
                    {
                        vt = i ;
                        maxn =a[i];
                    }
                }
                if (vt==0) break ;
                ans+=maxn ;
                int l,r  ;
                ft(j,1,vt)
                {
                    if (a[j]>0)
                    {
                        a[j]-=maxn ;
                    }
                    else
                        break ;
                }
                fr(j,vt+1,n)
                if (a[j]>0)
                {
                    a[j]-=maxn ;
                }
                else break ;
            }
            printf("%d\n",ans);
            fr(i,1,n) a[i] = b[i];
        }
    }
}
void sub()
{
    fr(i,1,T)
    {
        xuli();
    }
}
int main()
{
    inp() ;
    sub() ;
}
