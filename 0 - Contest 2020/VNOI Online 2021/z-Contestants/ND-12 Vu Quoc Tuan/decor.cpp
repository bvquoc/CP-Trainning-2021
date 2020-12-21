#include <bits/stdc++.h>

using namespace std;
int n,m,k,T,l,r,mid,vtd,vtc,f[500005],sl[500005],c[2][500005];
string s;
int phin(int u)
{
    return f[u]<0 ? u : f[u]=phin(f[u]);
}
void uni(int u,int v)
{
    if (f[u]>f[v]) swap(u,v);
    f[u]+=f[v];
    f[v]=u;
    sl[u]+=sl[v];
}
void up(int u,int x,int gt)
{
    T=T+gt*(s[u]-'0');
    u=phin(u);
    int cu=min(c[0][u],sl[u]-c[1][u]);
    c[x][u]+=gt;
    int moi=min(c[0][u],sl[u]-c[1][u]);
    T=T-cu+moi;
}
int main()
{
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    cin>>s;s='.'+s;
    for (int i=1;i<=n;++i)
    {
        if (s[i]=='1') sl[i]=1;
        f[i]=-1;
    }

    for (int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        u=phin(u);
        v=phin(v);
        if (u!=v) uni(u,v);
    }

    l=1;r=n;
    while (l<=r)
    {
        mid=(l+r)/2;

        T=0;

        memset(c,0,sizeof(c));

        for (int i=1;i<mid;++i) up(i,s[i]-'0',1);
        bool ck=false;

        for (int i=mid;i<=n;++i)
        {
            up(i,s[i]-'0',1);

            if (i-mid>0) up(i-mid,s[i-mid]-'0',-1);
            if (T+k>=mid)
            {
                vtd=i-mid+1;vtc=i;
                ck=true;break;
            }
        }
        if (ck) l=mid+1;
        else r=mid-1;

    }
    if (vtd) cout<<vtd<<' '<<vtc;
    else cout<<-1;
    return 0;
}
