#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
const int N=1e5+7;
const ll LLmax=1e18;
typedef pair<int,int> ii;
int n,m,k,l;
vector<int> c[N];
vector<ii> adj[N];
struct Edge
{
    int u,v,w;
    friend bool operator < (Edge &x,Edge &y)
    {
        return x.w<y.w;
    }
} e[N];
struct DisjointSetUnion
{
    int root[N];
    int Get(int u)
    {
        return ((u==root[u])?(u):(root[u]=Get(root[u])));
    }
    bool Union(int u,int v)
    {
        int p=Get(u),q=Get(v);
        if(p==q) return 0;
        root[p]=q;
        return 1;
    }
} DSU;
void inp()
{
    cin>>n>>m>>k>>l;
    for(int i=1; i<=n; ++i)
    {
        int sz;
        cin>>sz;
        for(int j=1; j<=sz; ++j)
        {
            int x;
            cin>>x;
            c[i].push_back(x);
        }
    }
    for(int i=1; i<=m; ++i)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
        adj[e[i].u].push_back({e[i].w,e[i].v});
        adj[e[i].v].push_back({e[i].w,e[i].u});
    }
}
int d[N],cnt[7],W[13][13];
ll res=LLmax;
void sub1()
{
    int a[13];
    for(int i=1; i<=n; ++i) a[i]=i;
    for(int i=1; i<=m; ++i)
    {
        W[e[i].u][e[i].v]=e[i].w;
        W[e[i].v][e[i].u]=e[i].w;
    }
    do
    {
        bool ok=1;
        for(int i=1; i<=k; ++i) cnt[i]=0;
        int pos=0,pos1=0,num=0;
        ll sum=0;
        for(int i=1; i<=n; ++i)
        {
            if(a[i]==n)
            {
                if(!pos)
                {
                    ok=0;
                    break;
                }
                pos1=i;
            }
            if(a[i]==1) pos=i;
        }
        if(!ok) continue;
        for(auto t:c[a[pos]])
            if(!cnt[t])
            {
                ++num;
                ++cnt[t];
            }
        for(int i=pos; i<pos1; ++i)
        {
            if(!W[a[i]][a[i+1]])
            {
                ok=0;
                break;
            }
            else
            {
                sum+=0ll+W[a[i]][a[i+1]];
                for(auto t:c[a[i+1]])
                    if(!cnt[t])
                    {
                        ++num;
                        ++cnt[t];
                    }
            }
        }
        if(!ok) continue;
        if(num>=l)
            res=min(res,sum);
        else
        {
            for(int i=pos; i>1; --i)
            {
                if(!W[a[i]][a[i-1]])
                {
                    break;
                }
                else
                {
                    sum+=0ll+W[a[i]][a[i-1]];
                    for(auto t:c[a[i-1]])
                        if(!cnt[t])
                        {
                            ++num;
                            ++cnt[t];
                        }
                    if(num==l)
                    {
                        res=min(res,sum);
                        break;
                    }
                }
            }
        }
    }
    while(next_permutation(a+1,a+n+1));
    cout<<((res<LLmax)?res:(-1));
}
void sub2()
{
    for(int i=1; i<=n; ++i) d[i]=INT_MAX;
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    d[1]=0;
    pq.push({0,1});
    while(pq.size())
    {
        int u=pq.top().S,du=pq.top().F;
        pq.pop();
        if(du!=d[u]) continue;
        for(auto v:adj[u])
            if(d[v.S]>du+v.F)
            {
                d[v.S]=du+v.F;
                pq.push({d[v.S],v.S});
            }

    }
    cout<<d[n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DHAKA.inp","r",stdin);
    freopen("DHAKA.out","w",stdout);
    inp();
    if(n<11)
    {
        sub1();
        return 0;
    }
    sub2();
    return 0;
}
