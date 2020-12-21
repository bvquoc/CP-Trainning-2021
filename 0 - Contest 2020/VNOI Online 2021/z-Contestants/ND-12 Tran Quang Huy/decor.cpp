#include <bits/stdc++.h>
#define N 500002
using namespace std;
int f[N],n,m,k,i,j,l,r;
char c[N];
void sub1()
{
    for(i=1;i<=n;i++) f[i]=f[i-1]+1-(c[i]-'0');
    j=1;
    for(i=1;i<=n;i++)
    {
        while(f[i]-f[j-1]>k) j++;
        if(r-l+1<i-j+1)
        {
            l=j; r=i;
        }
    }
    if(l==0) cout<<-1;
    else cout<<l<<" "<<r;
}


////////////////////////////////////////////////



int rt[N],d1[2002],d0[2002],u,v;
int root(int u)
{
    if(u==rt[u]) return u;
    return rt[u]=root(rt[u]);
}
bool check(int l,int r)
{
    int i,u;
    memset(d0,0,sizeof(d0));
    memset(d1,0,sizeof(d1));
    for(u=1;u<l;u++)
        if(c[u]=='1') d1[root(u)]++;
    for(u=r+1;u<=n;u++)
        if(c[u]=='1') d1[root(u)]++;
    for(u=l;u<=r;u++)
        if(c[u]=='0')
        {
         //   cerr<<1<<'\n';
            d0[root(u)]++;
        }
    int sum=0;
    for(u=1;u<=n;u++)
    {
     //   cerr<<rt[u]<<" "<<d1[u]<<" "<<d0[u]<<'\n';
        if(rt[u]==u && d1[u]<d0[u]) sum+=d0[u]-d1[u];
    }
    return sum<=k;
}
void sub2()
{
    for(u=1;u<=n;u++) rt[u]=u;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        u=root(u); v=root(v);
        rt[u]=v;
    }
   // cerr<<check(1,5); return ;
    j=1;
    for(i=1;i<=n;i++)
    {
        while(check(j,i)==0) j++;
        if(r-l+1<i-j+1)
        {
            l=j; r=i;
        }
    }
    if(l==0) cout<<-1;
    else cout<<l<<" "<<r;
}
int main()
{
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(i=1;i<=n;i++) cin>>c[i];
    if(m==0) sub1();
    else sub2();
}
