#define taskname "CONSTRUCT"
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn=1e6+2;
int n, m, a[maxn];
long long ans=0, lazy[4*maxn];

struct T
{
    long long v;
    int id;
};
T f[4*maxn];

void Init(int k,int l,int r)
{
    if(l==r)
    {
        f[k]={a[l],l};
        return;
    }
    int mid=(l+r)/2;
    Init(k*2,l,mid);
    Init(k*2+1,mid+1,r);
    if(f[k*2].v<f[k*2+1].v)
        f[k]=f[k*2];
    else f[k]=f[k*2+1];
}

void Enter()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    fill_n(lazy,4*n+1,0);
    Init(1,1,n);
}

void Dolazy(int k,int l,int r)
{
    if(lazy[k]==0)return;
    f[k].v+=lazy[k];
    if(l!=r)
    {
        lazy[2*k]+=lazy[k];
        lazy[2*k+1]+=lazy[k];
    }
    lazy[k]=0;
}

void Update(int k,int l,int r,int L,int R,int v)
{
    if(R<l||r<L)return;
    Dolazy(k,l,r);
    if(L<=l&&r<=R)
    {
        f[k].v+=v;
        if(l!=r)
        {
            lazy[2*k]+=v;
            lazy[2*k+1]+=v;
        }
        return;
    }
    int mid=(l+r)/2;
    Update(k*2,l,mid,L,R,v);
    Update(k*2+1,mid+1,r,L,R,v);
    if(f[k*2].v<f[k*2+1].v)
        f[k]=f[k*2];
    else f[k]=f[k*2+1];
}

T Get(int k,int l,int r,int L,int R)
{
    Dolazy(k,l,r);
    if(R<l||r<L)return {1000000000,1};
    if(L<=l&&r<=R)return f[k];
    int mid=(l+r)/2;
    T x=Get(k*2,l,mid,L,R), y=Get(k*2+1,mid+1,r,L,R);
    if(x.v<y.v)
        return x;
    return y;
}

void Do(int l,int r,long long pre)
{
    if(l>r)return;
    T u=Get(1,1,n,l,r);
    ans+=u.v-pre;
    Do(l,u.id-1,u.v);
    Do(u.id+1,r,u.v);
}

void Solve()
{
    while(m--)
    {
        int type, l, r, k;
        cin>>type;
        if(type==1)
        {
            cin>>l>>r>>k;
            Update(1,1,n,l,r,k);
        }
        else
        {
            cin>>l>>r;
            ans=0;
            Do(l,r,0);
            cout<<ans<<'\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp","r",stdin);
    freopen(taskname".out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        Enter();
        Solve();
    }
}
