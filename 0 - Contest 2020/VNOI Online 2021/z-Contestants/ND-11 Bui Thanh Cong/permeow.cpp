#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=1e9+7;
const long o=200005;
long n,a[o],b[o],vt[o],dd[o],it[4*o];
void sub1()
{
    for(long i=1;i<=n;i++)
        vt[a[i]]=i;
    long kq=0;
    for(long i=1;i<=n;i++)
    {
        long phu=0;
        for(long j=1;j<vt[i];j++)
            phu+=dd[j];
        kq+=vt[i]-1-phu;
        dd[vt[i]]=1;
    }
    cout<<kq;
}
void update(long x,long l,long r,long v)
{
    if(v<l || v>r)
        return;
    if(l==r)
    {
        it[x]=1;
        return;
    }
    long mid=(l+r)>>1;
    update(2*x,l,mid,v);
    update(2*x+1,mid+1,r,v);
    it[x]=it[2*x]+it[2*x+1];
}
long get(long x,long l,long r,long u,long v)
{
    if(v<l || u>r || u>v)
        return 0;
    if(u<=l && r<=v)
        return it[x];
    long mid=(l+r)>>1;
    return get(2*x,l,mid,u,v)+get(2*x+1,mid+1,r,u,v);
}
void subt()
{
    ll kq=0;
    do{
        for(long i=1;i<=4*n;i++)
            it[i]=0;
        bool ok=1;
        for(long i=1;i<=n;i++)
        {
            vt[a[i]]=i;
            if(a[i]!=b[i])ok=0;
        }
        ll phu=0;
        for(long i=1;i<=n;i++)
        {
            phu+=vt[i]-1-get(1,1,n,1,vt[i]-1);
            update(1,1,n,vt[i]);
        }
        kq=(kq+phu)%M;
        if(ok)break;
    }
    while(next_permutation(a+1,a+1+n));
    cout<<kq;
}
int main()
{
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    bool ok2=1;
    for(long i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)ok2=0;
    }
    bool ok=1;
    for(long i=1;i<=n;i++)
    {
        cin>>b[i];
        if(a[i]!=b[i])ok=0;
        if(b[i]!=n-i+1)ok2=0;
    }
    if(ok && n<=2000)sub1();
    else subt();
    return 0;
}
