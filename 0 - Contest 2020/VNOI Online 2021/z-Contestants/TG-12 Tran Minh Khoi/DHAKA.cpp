#include <bits/stdc++.h>
#define fi "DHAKA.inp"
#define fo "DHAKA.out"
#define oo 1e18+11

using namespace std;

struct node
{
    int v, w;
    bool operator<(const node b) const
    {
        return b.w > w;
    }
};

int n, m, k, l, c[100011];
vector<node> a[100011];

int onbit(int i, int j)
{
    return (i | (1 << (j - 1)));
}

void INP()
{
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; i++)
    {
        int s, t = 0;
        cin >> s;
        for (int j = 1; j <= s; j++)
        {
            int t2;
            cin >> t2;
            t = onbit(t, t2);
        }
        c[i] = t;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
}

#define ni pair<node, int>
#define X first
#define Y second

int dem(int i)
{
    int res = 0;
    while(i)
    {
        if (i & 1) res++;
        i >>= 1;
    }
    return res;
}

void Solve()
{
    long long f[100011][32];
    priority_queue<ni, vector<ni> > qu;
    qu.push({{1, 0}, c[1]});
    for (int i = 1; i <= n; i++)
        for (int kt = 0; kt <= (1<<k)-1; kt++)
            f[i][kt] = oo;
    f[1][c[1]] = 0;
    while(qu.size())
    {
        ni U = qu.top();
        qu.pop();
        int u = U.X.v, w = U.X.w, tt = U.Y;
        //cout << "1:" << u << " " << w << " " << tt << endl;
        if (f[u][tt] < w) continue;
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].v;
            //cout << "2:" << tt << " " << v << " " << f[u][tt] << endl;
            if (f[v][tt|c[v]] > f[u][tt] + a[u][i].w)
            {
                f[v][tt|c[v]] = f[u][tt] + (long long)a[u][i].w;
                //cout << "3:" << u << " " << v << " " << f[v][tt|c[v]] << " " << (tt|c[v]) << endl;
                qu.push({{v,f[v][tt|c[v]]},tt|c[v]});
            }
        }
    }
    long long res = oo;
    for (int i = 0; i <= (1<<k)-1; i++)
        if (dem(i) >= l)
            res = min(res, f[n][i]);
    if (res == oo) cout << -1; else cout << res;
}

int main()
{
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
    INP();
    Solve();
    return 0;
}
