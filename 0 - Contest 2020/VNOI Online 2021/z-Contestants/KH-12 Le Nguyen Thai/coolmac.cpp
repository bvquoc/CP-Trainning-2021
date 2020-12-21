#include<bits/stdc++.h>
using namespace std;
const long long N=100010;
long long n,m,a[100010],st[400010],l[N],r[N];
void build (int id ,int l,int r)
{
    if(l>r) return ;
    if(l==r)
    {
        st[id]=a[l];
        return ;
    }
    long long mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=min(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if(u>r||v<l) return INT_MAX;
    if(u<=l&&r<=v)
    {
        return st[id];
    }
    long long mid=(l+r)>>1;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main()
{
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        l[i]=x;
        r[i]=y;
        a[y]=x;
    }
    build(1,1,100000);
    cin>>n;
    int mi=1e6;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mi=min(mi,x);
    }
    long long l=100000;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int giatri=get(1,1,100000,l,100000);
        l=giatri;
        ans++;
        if(l<=mi) break;
    }
    if(l<=mi) cout<<ans<<endl;
    else cout<<"-1"<<endl;
    return 0;

}
