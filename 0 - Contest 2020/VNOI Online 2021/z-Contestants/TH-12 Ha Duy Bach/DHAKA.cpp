#include <bits/stdc++.h>
#define name "DHAKA"
#define pb push_back
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define fi first
#define se second
#define gb(x,k) ( x>>(k-1) & 1)
#define onbit(x,k) ( x | 1<<(k-1) )
using namespace std;
const int N=1e5+100;

priority_queue <iii ,vector<iii> , greater <iii> > pq;

vector <ii> ke[N];
vector<int> ml[N];
ll nhan[N][50];
int k,m,n,l,K;

void init()
{
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<K; j++)
            nhan[i][j]=LLONG_MAX;
    }
}

void dijkstra(int xp)
{
    init();
    nhan[xp][0]=0;
    pq.push({ nhan[xp][0],{ xp  ,  0 }  });
    ///        val         edge  status
    int h;

    while (pq.size())
    {
        iii p=pq.top(); pq.pop();
        if (p.fi!=nhan[p.se.fi][p.se.se] ) continue;
        int u=p.se.fi, st=p.se.se;
        if (u==n && __builtin_popcount(st)==l )
        {
            cout<<p.fi; return ;
        }

        for (auto q:ke[u])
        {
            int v=q.fi , val=q.se;
            h=st;
            for (auto k:ml[v]) h=onbit(h,k);
            if (nhan[v][h] > nhan[u][st] + val )
            {
                nhan[v][h]=nhan[u][st]+val;
                pq.push({nhan[v][h],{v,h}} );
            }
        }
    }
    cout<<-1; return ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(name".inp","r") )
    {
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }
    cin>>n>>m>>k>>l;

    K=(1<<k);

    for (int i=1; i<=n; i++)
    {
        int z;
        cin>>z;
        for (int j=1; j<=z; j++)
        {
            int c1;
            cin>>c1;
            ml[i].pb(c1);
        }
    }

    while (m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ke[u].pb({v,w});
        ke[v].pb({u,w});
    }
    dijkstra(1);
}
