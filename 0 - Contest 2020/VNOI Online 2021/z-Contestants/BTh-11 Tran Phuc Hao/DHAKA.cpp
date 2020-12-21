#include<bits/stdc++.h>
#define ll long long
#define INF 10000000000000000
using namespace std;
typedef pair <int,int> pii;
ll get_bit(ll x,ll k)
{
    return x>>k & 1;
}
ll turn_on(ll x,ll k)
{
    return x | 1<<k;
}
ll n,m,k,l,s,si,x,y,w;
ll res=INF;
vector<ll> A[100005];
struct node
{
    ll v;
    ll w;
    bool operator < (node &x) const
    {
        return x.w<w;
    }
};
ll M[105][105];
ll tham[105][105];
vector<node> V[100005];
vector<ll> dinh;
set<ll> S;
bool ok[100005];
void DFS(ll u,ll cost)
{
    dinh.push_back(u);
    if(u==n)
    {
        ll mask=0;ll dem=0;
        for(ll i=0;i<dinh.size();i++)
        {
            ll p=dinh[i];
            for(ll j=0;j<A[dinh[i]].size();j++)
            {
                ll o=A[dinh[i]][j];
                mask=turn_on(mask,A[dinh[i]][j]-1);
            }
        }
        for(ll i=5;i>=0;i--)
        {
            if(get_bit(mask,i))
            {
                dem++;
            }
        }
        if(dem>=l)
        {
            res=min(res,cost);
        }
        dinh.pop_back();
        return;
    }
    for(int i=0;i<V[u].size();i++)
    {
        if(!tham[u][V[u][i].v] && !tham[V[u][i].v][u])
        {
            tham[u][V[u][i].v]=1;
            tham[V[u][i].v][u]=1;
            DFS(V[u][i].v,cost+V[u][i].w);
            if(V[u][i].v==n)
            {
                tham[u][V[u][i].v]=0;
                tham[V[u][i].v][u]=0;

            }
        }
    }
    dinh.pop_back();
}
int d[100005];
void dijtra(int s)
{
    for (int i=1;i<=n;i++) d[i]=INF;
    d[s]=0;
    priority_queue <pii,vector<pii>,greater<pii> > pq;
    pq.push(pii(0,1));

    while (!pq.empty())
    {
        int u=pq.top().second;int du=pq.top().first;pq.pop();
        if(du>d[u]) continue;
        for(int i=0;i<V[u].size();i++)
        {
            int v=V[u][i].v;int dv=V[u][i].w;
            if(d[v]>du+dv)
            {
                d[v]=du+dv;
                pq.push(pii(d[v],v));
            }
        }
    }
}
void sub13()
{

    DFS(1,0);
    if(res==INF) res=-1;
    cout<<res;
}
void sub2()
{
    dijtra(1);
    cout<<d[n];
}
int main()
{
    freopen("DHAKA.inp","r",stdin);
    freopen("DHAKA.out","w",stdout);
    cin>>n>>m>>k>>l;
    for(ll i=1;i<=n;i++)
    {
        cin>>s;
        ok[i]=s;
        for(ll j=1;j<=s;j++)
        {
            cin>>si;
            A[i].push_back(si);
        }
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>x>>y>>w;
        M[x][y]=w;
        M[y][x]=w;
        V[x].push_back({y,w});
        V[y].push_back({x,w});
    }
    if(l==0)
    {
        sub2();
    }
    else
    {
        sub13();
    }
    return 0;
}
