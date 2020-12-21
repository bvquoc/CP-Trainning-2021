#include <bits/stdc++.h>
#define ft                          first
#define sd                          second
#define task                        "dhaka"
#define fi			                freopen(task".inp", "r", stdin)
#define fo			                freopen(task".out", "w", stdout)
#define reset(a, b)                 memset(a, b, sizeof(a))
#define MAX(a, b)                   a = max(a, b)
#define MIN(a, b)                   a = min(a, b)
#define pb  			            push_back
#define mp(a, b)                    make_pair(a, b)

using namespace std;

typedef long long                   LL;
typedef pair<int,int>               II;

const LL MOD = 1e9 + 7;
const LL N   = 1e5 + 5;
const LL INF = 1e18;
const int base = 27;

struct DATA
{
    LL tm;
    int msk, u;

    bool operator < (const DATA &P) const
    {
        return tm > P.tm;
    }
};

/* ------------- ------------- ------------- ------------- ------------- ------------- ------------- */
int n, m, k, l, a[N], mask;
LL d[N][35];
vector<II> adj[N];

int CBIT(int x)
{
    int cnt = 0;

    for (; x; x &= x - 1)
        cnt++;

    return cnt;
}

void Dijkstra()
{
    priority_queue<DATA> pq;
    mask = (1 << k);

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < mask; j++)
            d[i][j] = INF;

    pq.push({0, a[1], 1});
    d[1][a[1]] = 0;

    while (pq.size())
    {
        DATA tmp = pq.top();
        pq.pop();

        LL tm = tmp.tm;
        int msk = tmp.msk, u = tmp.u;

        if (d[u][msk] < tm)
            continue;

        for (II i : adj[u])
        {
            int v = i.ft;
            LL w = i.sd;
            int nxt = a[v] | msk;

            if (d[v][nxt] > d[u][msk] + w)
            {
                d[v][nxt] = d[u][msk] + w;
                pq.push({d[v][nxt], nxt, v});
            }
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    fi;
    fo;
    cin >> n >> m >> k >> l;

    for (int i = 1; i <= n; i++)
    {
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++)
        {
            int type;
            cin >> type;
            a[i] |= (1 << (type-1));
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    Dijkstra();
    LL ans = INF;

    for (int i = 0; i < mask; i++)
        if (CBIT(i) >= l)
            MIN(ans, d[n][i]);

    cout << (ans < 1e16 ? ans : -1);
    return 0;
}
