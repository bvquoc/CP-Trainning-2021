#include <bits/stdc++.h>
#define PII pair<int,int>
#define LL long long
#define F first
#define S second
using namespace std;
const int N=100001;
LL it[N*4][3],lz[N*4];
int t,a[N];
LL val;
void tc(int k,int d,int c)
{
    lz[k]=0;
    if (d==c)
    {
        it[k][0]=it[k][1]=a[d];
        it[k][2]=0;
        return;
    }
    int m=(d+c)/2;
    tc(k*2,d,m);
    tc(k*2+1,m+1,c);
    it[k][0]=it[k*2][0];
    it[k][1]=it[k*2+1][1];
    it[k][2]=it[k*2][2]+it[k*2+1][2]+max(0LL,it[k*2+1][0]-it[k*2][1]);
}
void ud(int k,int d,int c,int l,int r,int v)
{
    if (d!=c)
    {
        lz[k*2]+=lz[k];
        lz[k*2+1]+=lz[k];
    }
    it[k][0]+=lz[k];
    it[k][1]+=lz[k];
    lz[k]=0;
    if (d>r||c<l) return;
    if (d>=l&&c<=r)
    {
        it[k][0]+=v;
        it[k][1]+=v;
        if (d!=c)
        {
            lz[k*2]+=v;
            lz[k*2+1]+=v;
        }
        return;
    }
    int m=(d+c)/2;
    ud(k*2,d,m,l,r,v);
    ud(k*2+1,m+1,c,l,r,v);
    it[k][0]=it[k*2][0];
    it[k][1]=it[k*2+1][1];
    it[k][2]=it[k*2][2]+it[k*2+1][2]+max(0LL,it[k*2+1][0]-it[k*2][1]);
}
LL tv(int k,int d,int c,int l,int r)
{
    if (d!=c)
    {
        lz[k*2]+=lz[k];
        lz[k*2+1]+=lz[k];
    }
    it[k][0]+=lz[k];
    it[k][1]+=lz[k];
    lz[k]=0;
    if (d>r||c<l) return 0LL;
    if (d>=l&&c<=r)
    {
        LL res=it[k][2]+max(0LL,it[k][0]-val);
        val=it[k][1];
        return res;
    }
    int m=(d+c)/2;
    return tv(k*2,d,m,l,r)+tv(k*2+1,m+1,c,l,r);
}
int main()
{
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
        tc(1,1,n);
        for (int i=1;i<=m;i++)
        {
            int tt,l,r,k;
            scanf("%d%d%d",&tt,&l,&r);
            if (tt==1)
            {
                scanf("%d",&k);
                ud(1,1,n,l,r,k);
            }
            else
            {
                val=0;
                printf("%lld\n",tv(1,1,n,l,r));
            }
        }
    }
    return 0;
}
