#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 1e5 + 5;
const long long oo = 1e18;

vector <pair <int, int>> adj[N];
pair <int, int> st[32 * N];

long long dp[32 * N];

int id[N][32];
int mask[N];
int n,node,m,k,l;

int numbit(int x)
{
    int cnt = 0;
    while (x > 0)
    {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

bool minimize(long long &a, long long b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

void proc()
{
    for (int i = 1; i <= n; i++)
    for (int j = 0; j < (1 << k); j++)
    {
        id[i][j] = ++node;
        st[node] = mp(i, j);
    }

    priority_queue <pair <long long, int>> heap;

    for (int i = 1; i <= n; i++)
    for (int j = 0; j < (1 << k); j++)
    {
        int pos = id[i][j];
        dp[pos] = (i != 1 || j != 0) ? oo : 0;
    }

    heap.push(mp(0, id[1][0]));

    while (heap.size())
    {
        pair <long long, int> res = heap.top();
        heap.pop();

        int cur = res.se;
        if (-res.fi != dp[cur])
            continue;

        int u = st[cur].fi;
        int msk = st[cur].se;
        for (pair <int, int> to : adj[u])
        {
            int v = to.fi;
            int w = to.se;
            int newmask = msk | mask[v];
            int nxt = id[v][newmask];
            if (minimize(dp[nxt], dp[cur] + w))
                heap.push(mp(-dp[nxt], nxt));

        }
    }

    long long res = oo;
    for (int i = 0; i < (1 << k); i++) if (numbit(i) >= l)
    {
        int en = id[n][i];
        minimize(res, dp[en]);
    }
    if (res == oo)
        cout << -1;
    else
        cout << res;
}

void enter()
{
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; i++)
    {
        int sz; cin >> sz;
        while (sz--)
        {
            int x;
            cin >> x;
            mask[i] |= 1 << (x - 1);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back(mp(v, w));
        adj[v].push_back(mp(u, w));
    }
}

void preproc()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DHAKA.inp","r",stdin);
    freopen("DHAKA.out","w",stdout);
}

int main()
{
    preproc();
    enter();
    proc();
    return 0;
}
