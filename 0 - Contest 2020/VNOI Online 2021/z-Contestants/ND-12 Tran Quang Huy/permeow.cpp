#include <bits/stdc++.h>
#define N 200002
using namespace std;
long long f[N],bit[N],n,u,g[N],i,a[N],b[N],gt[N];
const int mod=round(1e9)+7;
void updatebit(int i)
{
    f[i]++;
    while(i<=n) { bit[i]++; i+=(i & -i); }
}
int getbit(int l,int r)
{
    int i=r,kq=0;
    while(i>=l)
        if(i-(i & -i)>=l) { kq+=bit[i]; i-=(i & -i); }
        else { kq+=f[i]; i--; }
    return kq;
}
long long sl(long long a[])
{
    memset(bit,0,sizeof(bit));
    int kq=0;
    for(int i=1;i<=n;i++)
    {
        kq=(kq+getbit(a[i]+1,n))%mod;
        updatebit(a[i]);
    }
    return kq;
}
void sub1()
{
    for(i=1;i<=n;i++)
        if(a[i]!=b[i]) return ;
    cout<<sl(a);
    exit(0);
}
void sub2()
{
    for(i=1;i<=n;i++)
        if(a[i]!=i || b[i]!=n-i+1) return ;
    cout<<g[n]; exit(0);
}

///////////////////////////////////////////////////////////////////////////////



/*

struct pt { int sl,sum; };
pt st[4*N];
long long lz[4*N];
pt operator + (const pt &a,const pt &b)
{
    return { a.sl+b.sl,(a.sum+b.sum)%mod };
}
void cong(int id,int k)
{
    k=(k+mod)%mod;
    st[id].sum=(st[id].sum+k*st[id].sl)%mod;
    lz[id]+=k;
}
void down(int id)
{
    int k=lz[id];
    if(k==0) return ;
    cong(id*2,k); cong(id*2+1,k);
    lz[id]=0;
}
void update(int id,int l,int r,int u,int sl,int sum)
{
    if(u<l || u>r) return ;
    if(l==r) { st[id]={ sl,sum }; return; }
    down(id);
    int mid=(l+r)>>1;
    update(id*2,l,mid,u,sl,sum);
    update(id*2+1,mid+1,r,u,sl,sum);
    st[id]=st[id*2]+st[id*2+1];
}
void lzupdate(int id,int l,int r,int u,int v,int k)
{
    if(u<=l && r<=v)
    {
        cong(id,k);
        return ;
    }
    down(id);
    int mid=(l+r)>>1;
    if(v<=mid) lzupdate(id*2,l,mid,u,v,k);
    else if(u>mid) lzupdate(id*2+1,mid+1,r,u,v,k);
    else
    {
        lzupdate(id*2,l,mid,u,mid,k);
        lzupdate(id*2+1,mid+1,r,mid+1,v,k);
    }
    st[id]=st[id*2]+st[id*2+1];
}
pt get(int id,int l,int r,int u,int v)
{
    if(u>v) return { 0,0 };
    if(u<=l && r<=v)
    {
       // cerr<<st[id].sum<<'\n';;
        return st[id];
    }
    down(id);
    int mid=(l+r)>>1;
    if(v<=mid) return get(id*2,l,mid,u,v);
    if(u>mid) return get(id*2+1,mid+1,r,u,v);
    return (get(id*2,l,mid,u,mid)+get(id*2+1,mid+1,r,mid+1,v))%mod;
}
long long tinh(long long a[])
{
    memset(lz,0,sizeof(lz));
    for(i=1;i<=n;i++) update(1,1,n,i,1,i-1);
 //   cerr<<get(1,1,n,1,2).sum;
    long long sum=0,kq;
    for(i=1;i<=n;i++)
    {
        pt x=get(1,1,n,1,a[i]-1);
        long long t=sum*x.sl%mod;
        t+=x.sum;
        t=t*gt[n-i]%mod;
        t=(t+g[n-i]*x.sl)%mod;
        cerr<<i<<" "<<x.sum<<'\n';
        kq=(kq+t)%mod;
        sum=(sum+get(1,1,n,a[i],a[i]).sum);
        update(1,1,n,a[i],0,0);
        //if(a[i]<n) lzupdate(1,1,n,a[i]+1,n,-1);
    }
   // cerr<<kq<<'\n';
    return kq+sum;
}*/
int main()
{
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=n;i++) cin>>b[i];
    for(i=1;i<=n;i++)
    {
        g[i]=(g[i-1]*i+i*(i-1)/2)%mod;
        gt[i]=gt[i-1]*i%mod;
    }
    sub1();
    sub2();
//    tinh(a); return 0;
   // cout<<(tinh(b)-tinh(a)+sl(a)+mod)%mod;
}
