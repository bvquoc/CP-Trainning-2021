#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nhat "permeow"
#define db double
#define pb push_back
#pragma GCC optimize("Ofast")
const int mm=2e5+5,mod=1e9+7;
int n;
int a[mm],b[mm];
void sub1()
{
    int re=0;
    for(int i=1;i<=n;i++)
    {
        int vt=0;
        for(int j=i;j<=n;j++)
            if(a[j]==i)
            {
                vt=j;
                break;
            }
        for(int j=vt-1;j>=i;j--) a[j+1]=a[j];
        if(vt) re+=vt-i;
    }
    printf("%d",re);
}
void sub2()
{
    ll gt=1,re=0;
    for(int i=2;i<=n;i++)
    {
        gt=(1ll*gt*i)%mod;
        re=(ll)((1ll*re*i)%mod+(1ll*gt*(i-1)/2)%mod)%mod;
    }
    printf("%lld",re);
}
int main()
{
    freopen(nhat".inp","r",stdin);
    freopen(nhat".out","w",stdout);
    int cc=0; scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        if(a[i]-b[i]) cc=1;
    }
    if(!cc) sub1();
    else sub2();
}
