#include <bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;
struct node
{
    int l,r,x;
}t[4*N];
int n,m,q;
int h[N];
int lz[4*N];
int a[N],b[N];
node mau;
void build(int k,int l,int r)
{
    if(l==r)
    {
        t[k].x=0;
        t[k].l=a[l];
        t[k].r=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    t[k].x=t[k*2].x+t[k*2+1].x+max(0LL,t[k*2+1].l-t[k*2].r);
    t[k].l=t[k*2].l;
    t[k].r=t[k*2+1].r;
}
void update(int k,int l,int r,int i,int j,int x)
{
    if(lz[k]!=0)
    {
        t[k].l+=lz[k];
        t[k].r+=lz[k];
        if(l!=r)
        {
            lz[k*2]+=lz[k];
            lz[k*2+1]+=lz[k];
        }
        lz[k]=0;
    }
    if(i>r || l>j)return;
    if(i<=l && r<=j)
    {
        t[k].l+=x;
        t[k].r+=x;
        if(l!=r)
        {
            lz[k*2]+=x;
            lz[k*2+1]+=x;
        }
        return;
    }
    int mid=(l+r)/2;
    update(k*2,l,mid,i,j,x);
    update(k*2+1,mid+1,r,i,j,x);
    t[k].x=t[k*2].x+t[k*2+1].x+max(0LL,t[k*2+1].l-t[k*2].r);
    t[k].l=t[k*2].l;
    t[k].r=t[k*2+1].r;
}
node get(int k,int l,int r,int i,int j)
{
    if(lz[k]!=0)
    {
        t[k].l+=lz[k];
        t[k].r+=lz[k];
        if(l!=r)
        {
            lz[k*2]+=lz[k];
            lz[k*2+1]+=lz[k];
        }
        lz[k]=0;
    }
    if(i>r || l>j)return mau;
    if(i<=l && r<=j)return t[k];
    int mid=(l+r)/2;
    node le=get(k*2,l,mid,i,j);
    node ri=get(k*2+1,mid+1,r,i,j);
    node ans;
    if(le.x==-1)
    {
        ans.x=ri.x;
        ans.l=ri.l;
        ans.r=ri.r;
        return ans;
    }
    if(ri.x==-1)
    {
        ans.x=le.x;
        ans.l=le.l;
        ans.r=le.r;
        return ans;
    }
    ans.x=le.x+ri.x+max(ri.l-le.r,0LL);
    ans.l=le.l;
    ans.r=ri.r;
    return ans;
}
int getl(int k,int l,int r,int i)
{
    if(lz[k]!=0)
    {
        t[k].l+=lz[k];
        t[k].r+=lz[k];
        if(l!=r)
        {
            lz[k*2]+=lz[k];
            lz[k*2+1]+=lz[k];
        }
        lz[k]=0;
    }
    if(i>r || l>i)return 0;
    if(i==l && l==r)
    {
        return t[k].l;
    }
    int mid=(l+r)/2;
    return getl(k*2,l,mid,i)+getl(k*2+1,mid+1,r,i);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Construct.inp","r",stdin);
    freopen("Construct.out","w",stdout);
    cin>>q;
    mau.l=-1;
    mau.r=-1;
    mau.x=-1;
    while(q--)
    {
        memset(lz,0,sizeof(lz));
        cin>>n>>m;
        for(int i=1;i<=n;i++){cin>>a[i];b[i]=a[i];}
        build(1,1,n);
        while(m--)
        {
            int k;
            cin>>k;
            if(k==1)
            {
                int l,r,x;
                cin>>l>>r>>x;
                update(1,1,n,l,r,x);
            }
            if(k==2)
            {
                int l,r;
                cin>>l>>r;
                cout<<get(1,1,n,l,r).x+getl(1,1,n,l)<<'\n';
            }
        }
    }
}
