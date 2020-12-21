#include <bits/stdc++.h>

using namespace std;

#define task "DHAKA"
#define file freopen(task".inp","r",stdin),freopen(task".out","w",stdout);
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define DFOR(i,a,b) for(int i=b; i>=a; i--)
#define ii pair<int,int>
#define X first
#define Y second
#define ll long long
#define pb push_back

#define BUG(x) {cout << #x << " = " << x << '\n';}
#define PR(x,a,b) {cout << #x << " = " ; FOR(i,a,b) cout << x[i] << ' '; cout << '\n';}

#define MOD 1000000007
#define MAXN 100111

int n,m,l,k;
vector <ii> adj[MAXN];
vector <int> a[MAXN];

void read()
{
    cin >> n >> m >> l >> k;

    int s;
    FOR(i,1,n)
    {
        cin >> s;
        FOR(j,1,s)
        {
            int u;
            cin >> u;
            a[i].pb(u);
        }
    }

    FOR(i,1,m)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb( {w,v} );
        adj[v].pb( {w,u} );
    }
}

namespace sub1
{
    int visit[10];

    bool check()
    {
        int cnt = 0;

        FOR(i,1,n)
        {
            for(auto s:a[i])
            {
                if(!visit[s])
                {
                    visit[s]=1;
                    cnt++;
                }
            }
        }
        return cnt >= k;
    }

    int d[MAXN];

    void dijkstra()
    {
        FOR(i,1,n)
            d[i] =  MOD;
        d[1] = 0;

        priority_queue <ii,vector <ii> , greater <ii> > pq;

        pq.push( {0,1} );

        int u,du,v,uv;

        while(!pq.empty())
        {
            u = pq.top().Y;
            du = pq.top().X;

            pq.pop();

            if(d[u]!=du)
                continue;
            for(auto e:adj[u])
            {
                v = e.Y;
                uv = e.X;

                if(d[v] > du+uv)
                {
                    d[v] = du+uv;
                    pq.push( {d[v],v} );
                }
            }
        }
        cout << d[n] << '\n';
    }

    void solve()
    {
        dijkstra();
    }
}

namespace sub2
{
    int d[MAXN][35];

    int getbit(int s,int i)
    {
        return (s>>i) & 1;
    }

    int offbit(int s,int i)
    {
        return s & ~ (1<< (i-1));
    }

    void dijkstra()
    {
        d[1][0] = 0;

        priority_queue <ii,vector <ii>, greater <ii> > pq;
        pq.push( {0,1} );

        int u,du,v,uv;

        while(!pq.empty())
        {
            u = pq.top().Y;
            du = pq.top().X;

            pq.pop();

            for(auto e:adj[u])
            {
                v = e.Y;
                uv = e.X;

                FOR(mask,0,(1<<l)-1)
                    for(auto s:a[v])
                    {
                        if(!getbit(mask,s-1))
                        {
                            if( d[v][mask ^ ( 1<< (s-1)) ] > d[u][mask] + uv)
                            {
                                d[v][mask ^ ( 1<< (s-1)) ] = d[u][mask] + uv;

                                pq.push( {d[v][mask ^ ( 1<< (s-1)) ],v} );
                            }
                        }
                    }
            }
        }
        if(d[n][ (1<<l)-1]==MOD)
            d[n][ (1<<l)-1]=-1;
        cout << d[n][(1<<l)-1];
    }

    void solve()
    {
        FOR(i,1,n)
            FOR(j,1,k)
                d[i][j] = MOD;
        dijkstra();
    }
}

void solve()
{
    if(!sub1::check())
    {
        cout << -1 << '\n';
        return;
    }

    if(l==0)
    {
        sub1::solve();
        return;
    }

    sub2::solve();
    return;
}

int main()
{
    file;
    faster;

    read();
    solve();

    return 0;
}
