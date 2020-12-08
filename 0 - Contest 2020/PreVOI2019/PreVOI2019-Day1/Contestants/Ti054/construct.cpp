#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=1e5;
const int oo=1e9+5;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e9+7;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

int n,m;
long long a[N+5],t[N+5],now[4*N+5],val[4*N+5],f[4*N+5],lz[4*N+5];
void build(int id, int l, int r)
{
    if (l>r) return;
    if (l==r)
    {
        val[id]=t[l];
        if (t[l]>0) f[id]=t[l]; else f[id]=0;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    f[id]=f[id*2]+f[id*2+1];
    return;
}
void update(int id, int l, int r, int u, long long k)
{
    if (l>r || l>u || r<u) return;
    if (l==r)
    {
        val[id]+=k;
        if (val[id]>0) f[id]=val[id]; else f[id]=0;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,k);
    update(id*2+1,mid+1,r,u,k);
    f[id]=f[id*2]+f[id*2+1];
    return;
}
long long get(int id, int l, int r, int u, int v)
{
    if (u>v || l>r || l>v || r<u) return 0;
    if (u<=l && r<=v) return f[id];
    int mid=(l+r)/2;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
void down(int id)
{
    long long tmp=lz[id]; lz[id]=0;
    now[id*2]+=tmp; now[id*2+1]+=tmp;
    lz[id*2]+=tmp; lz[id*2+1]+=tmp;
    return;
}
void builda(int id, int l, int r)
{
    if (l>r) return;
    if (l==r)
    {
        now[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    builda(id*2,l,mid);
    builda(id*2+1,mid+1,r);
    now[id]=0;
    return;
}
void update1(int id, int l, int r, int u, int v, long long k)
{
    if (l>r || l>v || r<u) return;
    if (l==r)
    {
        now[id]+=k;
        lz[id]+=k;
        return;
    }
    down(id);
    int mid=(l+r)/2;
    update1(id*2,l,mid,u,v,k);
    update1(id*2+1,mid+1,r,u,v,k);
    now[id]=0;
    return;
}
long long getval(int id, int l, int r, int u)
{
    if (l>r || l>u || r<u) return 0;
    if (l==r) return now[id];
    down(id);
    int mid=(l+r)/2;
    return getval(id*2,l,mid,u)+getval(id*2+1,mid+1,r,u);
}
int main()
{
	freopen("construct.inp","r",stdin);
	freopen("construct.out","w",stdout);
	ios_base::sync_with_stdio(false);
	int type,u,v;
	long long k;
	int nq;
    scanf("%d",&nq);
    for (int hihi=1;hihi<=nq;hihi++)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for (int i=1;i<n;i++) t[i]=a[i+1]-a[i];
        build(1,1,n-1);
        builda(1,1,n);
        for (int i=1;i<=m;i++)
        {
            int type;
            scanf("%d",&type);
            if (type==1)
            {
                scanf("%d%d%lld",&u,&v,&k);
                update(1,1,n-1,u-1,k);
                update(1,1,n-1,v,-k);
                update1(1,1,n,u,v,k);
            } else
            {
                scanf("%d%d",&u,&v);
                printf("%lld\n",getval(1,1,n,u)+get(1,1,n-1,u,v-1));
            }
        }
    }
	return 0;
}
