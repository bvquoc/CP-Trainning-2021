#include<bits/stdc++.h>
using namespace std;
#define nhat "socks"
#define ll long long
#define db double
#define pb push_back
const int mm=5e5+5;
int n,q,s=0;
int a[mm];
vector<int> e[mm];
int cha[mm][20],h[mm],ma=0;
void xuat()
{
    if(s>1) printf("1\n");
    else printf("0\n");
}
void sub1()
{
    xuat();
    while(q--)
    {
        int x; scanf("%d",&x);
        s+=1-2*a[x]; xuat();
        a[x]=(1-a[x]);
    }
}
int kt[mm],kttp[mm];
int cnt=0;
void dfs(int u)
{
    for(int v:e[u])
        if(!kt[v])
        {
            kt[v]=1;
            cha[v][0]=u;
            h[v]=h[u]+1;
            ma=max(ma,h[v]);
            dfs(v);
        }
    if(!kttp[u]) kttp[u]=++cnt;
}
int r=0;
int st[mm];
bool ss(int x,int y)
{
    return kttp[x]>kttp[y];
}
void khoitao()
{
    for(int j=1;j<=log2(ma);j++)
        for(int i=1;i<=n;i++)
            cha[i][j]=cha[cha[i][j-1]][j-1];
}
int nhay(int u,int v)
{
    int tam=h[v]-h[u];
    for(int i=0;i<=log2(tam);i++)
        if((tam>>i)&1) v=cha[v][i];
    return v;
}
int lca(int u,int v)
{
    if(h[u]>h[v]) swap(u,v);
    v=nhay(u,v);
    if(u==v) return u;
    for(int i=log2(ma);i>=0;i--)
        if(cha[u][i]-cha[v][i])
            u=cha[u][i],v=cha[v][i];
    return cha[u][0];
}
void xuli(int x)
{
    int jj=0;
    if(a[x])
    {
        for(int i=1;i<=r;i++) if(st[i]==x)
        {
            st[i]=0;
            break;
        }
    }
    if(x) s+=1-2*a[x],a[x]=1-a[x];
    if(a[x]) st[++r]=x;
    sort(st+1,st+r+1,ss);
    if(!st[r]) r--;
    int res=0;
    for(int i=1;i<r;i++)
        if(lca(st[i],st[i+1])-st[i]) res++;
    if(s>1) printf("%d\n",res/2+1);
    else printf("0\n");
}
void giai()
{
    h[1]=1; dfs(1);
    for(int i=1;i<=n;i++)
        if(a[i]) st[++r]=i;
    xuli(0);
    while(q--)
    {
        int x; scanf("%d",&x);
        xuli(x);
    }
}
int main()
{
    freopen(nhat".inp","r",stdin);
    freopen(nhat".out","w",stdout);
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i];
    int cc=0;
    for(int i=1;i<n;i++)
    {
        int x,y; scanf("%d %d",&x,&y);
        e[x].pb(y); e[y].pb(x);
        if(e[x].size()>=3||e[y].size()>=3) cc=1;
    }
    if(!cc) sub1();
    else giai();
}
