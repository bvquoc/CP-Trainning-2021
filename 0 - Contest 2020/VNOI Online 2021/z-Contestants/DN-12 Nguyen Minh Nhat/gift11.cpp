#include<bits/stdc++.h>
using namespace std;
#define nhat "gift11"
#define ll long long
#define db double
#define pb push_back
const int mm=2e3+5,mod=998244353;
int n;
ll re=0;
int st[mm][2],xl[mm];
int tt[10];
void tinh(int x,int id)
{
    st[id][0]=st[id][1]=0;
    int r=0;
    while(x) tt[++r]=x%10,x/=10;
    xl[id]=r%2;
    int d=0;
    for(int i=r;i>=1;i--) st[id][d]=(st[id][d]+tt[i])%11,d=1-d;
}
int s1_a[10],s1_xh[10];
void quaylui(int d)
{
    if(d>n)
    {
        int tam=0,tl=0;
        for(int i=1;i<=n;i++)
        {
            tam=(tam+st[s1_a[i]][tl]-st[s1_a[i]][1-tl]+11)%11;
            if(xl[s1_a[i]]) tl=1-tl;
        }
        if(!tam) re++;
    }
    else for(int i=1;i<=n;i++)
        if(!s1_xh[i])
        {
            s1_xh[i]=1; s1_a[d]=i;
            quaylui(d+1); s1_xh[i]=0;
        }
}
void sub1()
{
    re=0; quaylui(1);
    printf("%lld\n",re);
}
void sub2()
{
    int tam=0; re=1ll;
    for(int i=1;i<=n;i++)
    {
        tam=(tam+st[i][0]-st[i][1]+11)%11;
        re=(ll)(1ll*re*i)%mod;
    }
    if(!tam) printf("%lld\n",re);
    else printf("0\n");
}
ll f[mm][15][15],f1[mm][15][15];
void sub3()
{
    for(int i=0;i<=(n+1)/2;i++)
        for(int x=0;x<11;x++)
            for(int y=0;y<11;y++)
                f[i][x][y]=0;
    f[0][0][0]=1;
    for(int z=1;z<=n;z++)
    {
        for(int i=0;i<=(n+1)/2;i++)
            for(int x=0;x<11;x++)
                for(int y=0;y<11;y++)
                {
                    f1[i][x][y]=(ll)((ll)f1[i][x][y]+(ll)f[i-1][(x-st[z][0]+11)%11][(y-st[z][1]+11)%11])%mod;
                    f1[i][x][y]=(ll)((ll)f1[i][x][y]+(ll)f[i][(x-st[z][1]+11)%11][(y-st[z][0]+11)%11])%mod;
                }
        for(int i=0;i<=(n+1)/2;i++)
            for(int x=0;x<11;x++)
                for(int y=0;y<11;y++)
                    f[i][x][y]=f1[i][x][y],f1[i][x][y]=0;
    }
    re=0;
    for(int i=0;i<11;i++) re=(ll)((ll)re+(ll)f[(n+1)/2][i][i])%mod;
    for(int i=1;i<=n/2;i++) re=(ll)(1ll*re*i*i)%mod;
    if(n%2) re=(ll)(1ll*re*(n/2+1))%mod;
    printf("%lld\n",re);
}
int main()
{
    freopen(nhat".inp","r",stdin);
    freopen(nhat".out","w",stdout);
    int t; scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int le=0,chan=0;
        for(int i=1;i<=n;i++)
        {
            int x; scanf("%d",&x);
            tinh(x,i);
            if(xl[i]) chan=1;
            else le=1;
        }
        if(n<=8) sub1();
        else if(!chan) sub2();
        else if(!le) sub3();
        else printf("0\n");
    }
}
