#include <bits/stdc++.h>
#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
using namespace std;
const int nmax=1e5+5;
const ll inf=1e18+5;
int n, m, k, l, tmp;
ll d[nmax], dd[nmax], ds[nmax], dt[nmax];
int a[nmax];
vector <pii> g[nmax];

priority_queue <pii, vector<pii>, greater<pii> > q;
void batbit(int i, int &x)
{
    x = (1<<i) | x;
}
void dij(int s)
{
    memset(d,0x3f,sizeof(d));
    d[s]=0;
    q.push({0,s});
    while (!q.empty())
    {
        pii t=q.top();
        q.pop();
        int u=t.se;
        for (int i=0; i<g[u].size(); ++i)
        {
            int v = g[u][i].fi, w = g[u][i].se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v],v});
            }
        }
    }
}

void sub2()
{
    dij(1);
    cout<<d[n];
}
void sub3()
{
    ll res=inf;
    dij(1);
    memcpy(&ds, &d, sizeof(d));
    dij(n);
    memcpy(&dt, &d, sizeof(d));
    for (int i=1; i<=n; ++i)
    {
        if (a[i]==0) continue;
        res = min(res, ds[i] + dt[i]);
    }
    cout<<res;
}

#define vi pair <int, pii>
ll dist[nmax][33];
priority_queue <vi, vector<vi>, greater<vi> > pQ;

void Dij(int s)
{
    memset(dist,0x3f,sizeof(dist));
    dist[s][a[s]]=0;
    pQ.push({0,{s,a[s]}});
    while (!pQ.empty())
    {
        vi t=pQ.top();
        pii _u=t.se;
        pQ.pop();
        int u=_u.fi;
        int tt= _u.se;
        for (int i=0; i<g[u].size(); ++i)
        {
            int v = g[u][i].fi;
            pii _v = {v, tt | a[v]};
            ll w = g[u][i].se;

            if (dist[v][_v.se] > dist[u][_u.se] + w)
            {
                dist[v][_v.se] = dist[u][_u.se] + w;
                pQ.push({dist[v][_v.se],{v,_v.se}});
            }
        }
    }
}

void sub()
{
    Dij(1);
    cout<<dist[n][tmp];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);
    cin>>n>>m>>k>>l;
    for (int i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        if (x==0) continue;
        for (int j=1; j<=x; ++j)
        {
            int y;
            cin>>y;
            batbit(y,a[i]);
            dd[y]=1;
        }
        tmp = tmp | a[i];
    }
    int cnt=0;
    for (int i=1; i<=5; ++i)
        if (dd[i]==1) cnt++;
    if (cnt < k)
    {
        cout<<"-1";
        return 0;
    }
    for (int i=1; i<=m; ++i)
    {
        int u, v, w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
//    if (l==0) {sub2();return 0;}
//    if (k==1) {sub3();return 0;}
    sub();
    return 0;
}
