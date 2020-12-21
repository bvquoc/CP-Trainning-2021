#include <bits/stdc++.h>
#define task "DHAKA"
#define endl '\n'
#define MASK(i) (1LL << (i))
#define c_bit(i) __builtin_popcountll(i)
#define BIT(x, i) ((x) & MASK(i))
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) &~ MASK(i))
#define int long long
#define ii pair<int,int>

using namespace std;

const int oo=5e16;

int n,m,k,l,res = oo,vis[200000],vis2[200000],res2,d[200000],d2[200000],a[200000],b[200000],c[200000];
vector <ii> e[200000];
int v[200000];

void dijik()
{
    priority_queue <ii,vector<ii>,greater<ii>> pq;
    for (int i = 1;i<=n;i++)
        d[i] = oo;
    d[1] = 0;
    pq.push({0,1});
    while(pq.size())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;
        for (int i = 0;i < e[u].size();i++)
        {
            int uv = e[u][i].second;
            int v = e[u][i].first;
//            cout<<v<<" "<<uv<<endl;
            if (du + uv < d[v])
            {

                d[v] = du + uv;
                pq.push({d[v],v});
            }
        }
    }
}

void dijik2()
{
    priority_queue <ii,vector<ii>,greater<ii>> pq;
    for (int i = 1;i <= n;i++)
        d2[i] = oo;
    d2[n] = 0;
    pq.push({0,n});
    while(pq.size())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d2[u])
            continue;
        for (int i = 0;i < e[u].size();i++)
        {
            int uv = e[u][i].second;
            int v = e[u][i].first;
            if (du + uv < d2[v])
            {
                d2[v] = du + uv;
                pq.push({d2[v],v});
            }
        }
    }
}

void dfs2(int id,int sum,int mask)
{
    mask |= v[id];
    if (c_bit(mask) >= l)
    {
        res2 = min(2 * sum,res2);
        return;
    }
    vis2[id] = 1;
    for (int i = 0 ; i < e[id].size();i++)
        if (vis2[e[id][i].first] == 0)
        {
            dfs2(e[id][i].first,sum + e[id][i].second,mask);
        }
    vis2[id] = 0;
    return;
}


void dfs(int id,int sum,int mask)
{
    mask |= v[id];
    if (id == n)
    {
        if (c_bit(mask) >= l)
            res = min(res,sum);
        else
        {
            res2 = oo;
            dfs2(n,0,mask);
            if (res2 != oo)
                res = min(res,sum + res2);
        }
        return;
    }
    vis[id] = 1;
    for (int i = 0 ; i < e[id].size();i++)
        if (vis[e[id][i].first] == 0)
        {
            dfs(e[id][i].first,sum + e[id][i].second,mask);
        }
    vis[id] = 0;
    return;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m>>k>>l;
    for (int i = 1;i <= n;i++)
    {
        int x;
        cin>>x;
        for (int j = 1;j <= x;j++)
        {
            int x1;
            cin>>x1;
            v[i] |= MASK(x1);
        }
    }
    for (int i = 1;i <= m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        a[i] = u;
        b[i] = v;
        c[i] = w;
    }
    if (n <= 10)
    {
        dfs(1,0,0);
        if (res != oo) cout<<res<<endl;
            else cout<<-1;
        return 0;
    }
    if (l == 0)
    {

        dijik();
        if (d[n] != oo) cout<<d[n];
            else cout<<-1;
        return 0;
    }
    if (k == 1)
    {
//        cout<<1<<endl;
        dijik();
        dijik2();
        for (int i = 1;i <= m;i++)
        {
            if (v[a[i]] != 0 || v[b[i]] != 0)
            {
                res = min(d[b[i]] + d2[a[i]] + c[i],min(res,d[a[i]] + d2[b[i]] + c[i]));
            }
        }
        cout<<res;
        return 0;
    }

    dfs(1,0,0);
    if (res != oo) cout<<res<<endl;
        else cout<<-1;
    return 0;
}
