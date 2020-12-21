#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;


struct thing
{
    int msk;
    int u;
    long long cost;
    thing(int _ms=0,int _v=0,long long _w=0)
    {
        msk = _ms;
        u = _v;
        cost = _w;
    }
    bool operator < (thing const &T) const
    {
        return T.cost < cost;
    }
};


struct edg
{
    int v;
    long long w;
    edg (int _v=0,int _w=0)
    {
        v = _v;
        w = _w;
    }
};


priority_queue <thing> q;
vector <edg> a[100005];
int n,m,k,l;
int dua[100005];



void inp()
{
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; i++)
    {
        int tt,x;
        cin >> tt;
        while (tt--)
        {
            cin >> x;
            dua[i] |= 1<<(x-1);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(edg(v,w));
        a[v].push_back(edg(u,w));
    }
}

const long long oo = 1e16;
long long d[100005][32];


void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int o = 0; o < (1<<k); o++)
        d[i][o] = oo;
    }
}


void dijkstra()
{
    thing u;
    init();
    d[1][dua[1]] = 0;
    q.push(thing(dua[1],1,0));
    while (!q.empty())
    {
        u = q.top();
        q.pop();
        if (d[u.u][u.msk] < u.cost) continue;
        for (edg v:a[u.u])
        {
            int o = dua[v.v]|u.msk;
            if (u.cost + v.w < d[v.v][o])
            {
                d[v.v][o] = u.cost + v.w;
                q.push(thing(o,v.v,d[v.v][o]));
            }
        }
    }
}


void proc()
{
    long long ans = oo;
    dijkstra();
    for (int o = 0; o < (1<<k); o++)
    if (__builtin_popcount(o) >= l)
    {
        ans = min(ans,d[n][o]);
    }
    if (ans == oo) cout << -1;
    else cout << ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);
    inp();
    proc();
    return 0;
}
