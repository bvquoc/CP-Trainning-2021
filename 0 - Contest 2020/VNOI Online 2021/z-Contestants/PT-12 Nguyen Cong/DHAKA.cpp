#include <bits/stdc++.h>
#define MASK(i) (1LL << (i))
#define c_bit(i) __builtin_popcount(i)
#define BIT(x, i) (((x) >> (i)) & 1LL)

using namespace std;

#define ii pair <int, int>
#define fi first
#define se second

const long long INF = 1e18 + 7;

int n, m, l, k;
struct Tnode
{
    int u, v, w;
} E[100010];
vector <ii> Adj[100010];
int wtl[100010];

#define jj pair <long long, ii>
priority_queue <jj, vector <jj>, greater <jj> > pq;
long long d[100010][33];

void Process (void )
{
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 0; j <= 33; j ++)
        {
            d[i][j] = INF;
        }
    }
    d[1][wtl[1]] = 0;
    pq.push({0, {1, wtl[1] }});

    while(pq.size())
    {
        long long du = pq.top().fi;
        int u = pq.top().se.fi;
        int type = pq.top().se.se;
        pq.pop();

        if(d[u][type] != du )
            continue;

        for(auto tmp : Adj[u])
        {
            int v = tmp.se;
            long long w = tmp.fi;

            if(d[v][type | wtl[v]] > d[u][type] + w)
            {
                d[v][type | wtl[v]]  = d[u][type] + w;
                pq.push({d[v][type | wtl[v]] ,{v, type | wtl[v] }});
            }
        }
    }

    long long Ans = INF;
    for(int mask = 0; mask < MASK(k); mask ++) {
        if(c_bit(mask) >= l) Ans = min(Ans, d[n][mask]);
    }
    if(Ans == INF) cout << -1;
    else cout << Ans;
}

main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("DHAKA.inp", "r", stdin);
    freopen("DHAKA.out", "w", stdout);

    cin >> n >> m >> l >> k;
    for(int i = 1; i <= n; i ++)
    {
        int sl;
        cin >> sl;
        int mask = 0;
        for(int j = 1; j <= sl; j ++)
        {
            int u;
            cin >> u;
            mask |= MASK(u-1);
        }
        wtl[i] = mask;
    }

    for(int i = 1; i <= m; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E[i].u = u;
        E[i].v = v;
        E[i].w = w;

        Adj[u].push_back({w, v});
        Adj[v].push_back({w, u});
    }
    Process();
}
