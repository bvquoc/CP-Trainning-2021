#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
const long long oo=1e18;
int n,m,k,l,s[N],c[N][6];
long long d[N];
struct Data
{
    long long x;
    int y;
};
vector<Data>a[N];

struct cmpsub2
{
    bool operator()(Data u,Data v){return u.x>v.x;}
};
void dtrasub2()
{
    priority_queue<Data,vector<Data>,cmpsub2>pq;
    pq.push({0,1});
    for (int i=1;i<=n;i++) d[i]=oo;
    d[1]=0;
    while (pq.size()>0)
    {
        int u=pq.top().y;
        long long du=pq.top().x;
        pq.pop();
        if (u==n){cout<<d[n];return;}
        for (int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].y;
            if (d[v]>du+a[u][i].x)
            {
                d[v]=du+a[u][i].x;
                pq.push({d[v],v});
            }
        }
    }
    cout<<-1;
}


struct Data1
{
    long long x;
    int y;
    int z;
};
struct cmpsub3
{
    bool operator()(Data1 u,Data1 v){return u.x>v.x;}
};
long long D[N][35];
void sub3()
{
    if (l>k) {cout<<-1;return;}
    priority_queue<Data1,vector<Data1>,cmpsub3>pq;
    if (s[1]>0) pq.push({0,1,1});
    else pq.push({0,1,0});
    for (int i=1;i<=n;i++)
    { D[i][1]=D[i][0]=oo;}
    D[1][s[1]]=0;
    while (pq.size()>0)
    {
        int u=pq.top().y;
        long long du=pq.top().x;
        int ch=pq.top().z;
        pq.pop();
        if (u==n&&ch){cout<<D[n][ch];return;}
        for (int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].y;
            int ty=0;
            if (ch||s[v]) ty=1;
            if (D[v][ty]>du+a[u][i].x)
            {
                D[v][ty]=du+a[u][i].x;
                pq.push({D[v][ty],v,ty});
            }
        }
    }
    cout<<-1;
}


int getbit(int u,int v)
{
    return (u>>v)&1;
}
int F[N];
void dtrasub5()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=s[i];j++)
            F[i]=F[i]|(1<<(c[i][j]-1));
    }
    priority_queue<Data1,vector<Data1>,cmpsub3>pq;
    pq.push({0,1,F[1]});
    for (int i=1;i<=n;i++)
    for (int j=0;j<=(1<<k)-1;j++)D[i][j]=oo;
    D[1][F[1]]=0;
    while (pq.size()>0)
    {
        int u=pq.top().y;
        long long du=pq.top().x;
        int ch=pq.top().z;
        pq.pop();
        if (u==n)
        {
            int dem=0;
            for (int i=1;i<=k;i++)
                if (getbit(ch,i-1)) dem++;
            if (dem>=l)
            {
                cout<<D[n][ch];
                return;
            }
        }
        for (int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].y;
            int ty=(ch|F[v]);
            if (D[v][ty]>du+a[u][i].x)
            {
                D[v][ty]=du+a[u][i].x;
                pq.push({D[v][ty],v,ty});
            }
        }
    }
    cout<<-1;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    cin>>n>>m>>k>>l;
    for (int i=1;i<=n;i++)
    {
        cin>>s[i];
        for (int j=1;j<=s[i];j++) cin>>c[i][j];
    }
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        a[x].push_back({z,y});
        a[y].push_back({z,x});
    }
    if (l==0) dtrasub2();
    else if (k==1) sub3();
    else
        dtrasub5();
}
