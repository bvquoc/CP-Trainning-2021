#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,t[N];
struct data
{
    int x,y;
}a[N];
bool cmp(data u,data v) {return u.x<v.x;}

int getbit(int x,int y)
{
    return (x>>y)&1;
}
void sub1()
{
    int mi=1e9,kq=1e9;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mi=min(mi,x);
    }
    sort(a+1,a+1+m,cmp);
    for (int s=0;s<=(1<<m)-1;s++)
    {
        int dau=-1,cuoi=0,dem=0;
        for (int i=1;i<=m;i++)
        if (getbit(s,i-1))
        {
            dem++;
            if (dau==-1||cuoi<a[i].x) dau=a[i].x;
            cuoi=max(cuoi,a[i].y);
        }
        if (dau>mi||cuoi<1e5) continue;
        kq=min(kq,dem);
    }
    if (kq==1e9) cout<<-1;
    else cout<<kq;
}

int it[4*N],lz[4*N];
bool ch[N];
void lazy(int t)
{
    if (lz[t]==1e9) return;
    int z=lz[t];
    lz[2*t]=min(lz[2*t],z);
    it[2*t]=min(it[2*t],z);
    lz[2*t+1]=min(lz[2*t+1],z);
    it[2*t+1]=min(it[2*t+1],z);
    lz[t]=1e9;
}
void update(int i,int j,int t,int u,int v,int z)
{
    if (j<i||v<u||v<i||j<u) return;
    lazy(t);
    if (u<=i&&j<=v)
    {
        it[t]=min(it[t],z);
        lz[t]=min(lz[t],z);
        return;
    }
    lazy(t);
    int mid=(i+j)/2;
    update(i,mid,2*t,u,v,z);
    update(mid+1,j,2*t+1,u,v,z);
    it[t]=min(it[2*t],it[2*t+1]);
}
int query(int i,int j,int t,int u,int v)
{
    if (j<i||v<u||v<i||j<u) return 1e9;
    lazy(t);
    if (u<=i&&j<=v) return it[t];
    lazy(t);
    int mid=(i+j)/2;
    return min(query(i,mid,2*t,u,v),query(mid+1,j,2*t+1,u,v));
}
void sub3()
{
    int mi=1e9,kq=1e9,vt=m+1;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mi=min(mi,x);
    }
    sort(a+1,a+1+m,cmp);

    for (int i=1;i<=m;i++)
        if (a[i].x<=mi&&a[i].y>=1e5) {cout<<1;return;}
    for (int i=1;i<=4*1e5;i++) {it[i]=1e9;lz[i]=1e9;}
    for (int i=1;i<=m;i++)
    {
        if (a[i].x>mi) {vt=i;break;}
        update(1,1e5,1,a[i].x,a[i].y,1);
    }
    for (int i=vt;i<=m;i++)
    {
        int t=query(1,1e5,1,a[i].x,a[i].y)+1;
        if (a[i].y==1e5) kq=min(kq,t);
        update(1,1e5,1,a[i].x,a[i].y,t);
    }
    if (kq==1e9) cout<<-1;
    else cout<<kq;
}

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    cin>>m;
    for (int i=1;i<=m;i++)cin>>a[i].x>>a[i].y;
    cin>>n;
    if (n<=10&&m<=16) sub1();
    else sub3();
}
