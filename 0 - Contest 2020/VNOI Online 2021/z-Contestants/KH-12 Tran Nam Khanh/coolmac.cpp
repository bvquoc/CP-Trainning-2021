#include <iostream>
#include <fstream>
#include <algorithm>
#define int long long
using namespace std;
const int inf=1e18;
const int nax=1e5+5;
struct node
{
    int mi;
}f[4*nax];
int n,m,mi=inf;
pair<int,int>a[nax];
void build(int id,int l,int r)
{
    f[id].mi=inf;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
}
void update(int id,int l,int r,int k,int value)
{
    if(k<l||k>r)return;
    if(l==r)
    {
        f[id].mi=min(f[id].mi,value);
        return;
    }
    int mid=(l+r)>>1;
    update(id*2,l,mid,k,value);
    update(id*2+1,mid+1,r,k,value);
    f[id].mi=min(f[id*2].mi,f[id*2+1].mi);
}
int query(int id,int l,int r,int x,int y)
{
    if(y<l||r<x)return inf;
    if(x<=l&&r<=y)return f[id].mi;
    int mid=(l+r)>>1;
    return min(query(id*2,l,mid,x,y),query(id*2+1,mid+1,r,x,y));
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].second>>a[i].first;
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        mi=min(tmp,mi);
    }
    a[0]={mi-1,0};
    build(1,0,1e5);
    update(1,0,1e5,0,0);
    sort(a,a+m+1);
    for(int i=0;i<=m;i++)
    {
        int l=a[i].second,r=a[i].first;
        int tmp=query(1,0,1e5,max(0ll,l-1),r);
        if(tmp!=inf)update(1,0,1e5,r,tmp+1);
    }
    int ans=query(1,0,1e5,1e5,1e5);
    if(ans>=inf)cout<<-1<<endl;else cout<<ans-1<<endl;
    return 0;
}
