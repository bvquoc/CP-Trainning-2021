#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define ll long long
#define task "dhaka"
#define MAX 100000
#define INF 1000000000000000
using namespace std;
int n,m,k,l,x[MAX+5];
vector<pair<int,ll>>  g[MAX+5];

struct Data
{
    ll w;
    int u;
    int mask;
    bool operator <(const Data&o)const
    {
        return w>o.w;
    }
};

ll d[MAX+5][(1<<5)];

void DIJKTRA()
{
    rep(i,1,n) rep(j,0,(1<<k)-1) d[i][j]=INF;
    d[1][x[1]]=0;
    priority_queue<Data> q;q.push({0,1,x[1]});

    while(!q.empty())
    {
        int u=q.top().u;
        int mask=q.top().mask;
        q.pop();
        for(auto i : g[u])
        {
            int v=i.first;
            ll  w=i.second;
            if(d[v][mask|x[v]]>d[u][mask]+w)
            {
                d[v][mask|x[v]]=d[u][mask]+w;
                q.push({d[v][mask|x[v]],v,mask|x[v]});
            }
        }
    }
    ll result=INF;
    rep(i,0,(1<<(k))-1)
    {
        int cnt=0;
        for(int j=0;j<k;++j) cnt=cnt+int((i>>j)&1);
        if(cnt==l) result=min(result,d[n][i]);
    }
    if(result==INF) cout<<-1;
    else cout<<result;
}


int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n>>m>>k>>l;
    for(int i=1;i<=n;++i)
    {
        int sn,mask=0;
        cin>>sn;
        rep(j,1,sn)
        {
            int idx;cin>>idx;
            mask=(mask|(1<<(idx-1)));
        }
        x[i]=mask;
    }

    for(int i=1;i<=m;++i)
    {
        int u,v;ll w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    DIJKTRA();
}
