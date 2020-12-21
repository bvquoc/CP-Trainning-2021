#include <bits/stdc++.h>
#define FILE "socks"
#define ll long long
using namespace std;

const int N = 500009;
int n,q;
bool c[N];
vector<vector<int> > a;
void sub1()
{
    int sl=0,x;
    for(int i=1;i<=n;i++)
        sl+=c[i];
    for(int i=1;i<=q+1;i++)
    {
        cout<<(sl >= 2)<<'\n';
        if(i<=q) 
        {
            cin>>x;
            if(c[x]) sl--;
            else sl++;
            c[x]=1-c[x];
        }
    }
}
int dir[N];
void dfs_dd(int u,int p)
{
    dir[u]=dir[p];
    for(int &v:a[u])
        if(v!=p) dfs_dd(v,u);
}
inline int tt(int d1,int d2,int d3)
{
    return (d1>0)+(d2>0)+(d3>0);
}
void sub2()
{
    int r=1;
    for(int i=1;i<=n;i++)
        if(a[i].size() == 3) {r=i;break;}
    dir[r]=1;
    dfs_dd(a[r][0],r);
    dir[r]=2;
    dfs_dd(a[r][1],r);
    dir[r]=3;
    dfs_dd(a[r][2],r);
    dir[r]=0;
    int d[4],t,x;
    d[0]=d[1]=d[2]=d[3]=0;
    for(int i=1;i<=n;i++)
        if(c[i]) d[dir[i]]++;
    for(int i=1;i<=q+1;i++)
    {
        t=tt(d[1],d[2],d[3]);
        if(t==3) cout<<2<<'\n';
        if(t==2) cout<<1<<'\n';
        if(t==1)
            if(d[1] > 1 || d[2] > 1 || d[3] > 1 || d[0]==1) cout<<1<<'\n';
            else cout<<0<<'\n';
        if(i<=q) 
        {
            cin>>x;
            if(c[x]) d[dir[x]]--;
            else d[dir[x]]++;
            c[x]=1-c[x];
        }
    }
}
int f[N][2],g[N];
void dfs(int u,int p)
{
    f[u][0]=f[u][1]=n+7;
    if(a[u].size()==0)
    {
        f[u][0]=f[u][1]=0;
        if(c[u]) f[u][1]=1;
    }
    g[u]=c[u];
    int s0=0,s1=0;
    for(int &v:a[u])
        if(v!=p) 
        {
            dfs(v,u);
            g[u]+=g[v];
            s0+=f[v][0];
            s1+=f[u][1];
        }
    if(c[u])
    {
        for(int &v:a[u])
            f[u][0]=min(f[u][0],s0-f[v][0]+f[v][1]+1);
        f[u][1]=s0;
    }
    else
    {
        for(int &v:a[u])
            f[u][1]=min(f[u][1],s0-f[v][0]+f[v][1]);
        f[u][0]=s0;
    }
}
void sub3()
{
    for(int i=1;i<=q+1;i++)
    {
        dfs(1,0);
        cout<<f[1][0]<<'\n';
        if(i <= q)
        {
            int x;
            cin>>x;
            c[x]=1-c[x];
        }
    }
}
int main()
{
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>c[i];
    a.resize(n+7);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    bool oks1=1,oks2=1;int demb3=0;
    for(int i=1;i<=n;i++) 
    {
        if(a[i].size() > 2) oks1=0;
        if(a[i].size() == 3) demb3++;
        if(a[i].size() > 3) oks2=0;
    }
    if(oks1) {sub1();return 0;}
    if(oks2 && demb3==1) {sub2();return 0;}
    sub3();
}
