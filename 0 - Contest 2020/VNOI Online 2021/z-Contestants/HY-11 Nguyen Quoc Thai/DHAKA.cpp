#include <bits/stdc++.h>
#define MAXN 100005
#define SUB1 15
#define ll long long
#define pii pair < int, int >
#define F first
#define S second

using namespace std;
int n, m, k, l;
int t[MAXN];
int s[MAXN][6];
ll d[SUB1][SUB1];
vector < pii > ke[MAXN];
void read()
{
    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; ++i)
    {
        cin >> t[i];
        for(int j = 1; j <= t[i]; ++j)
        {
            cin >> s[i][j];
        }
    }
    for(int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].push_back({v,w});
        ke[v].push_back({u,w});
    }
}
const ll oo = 1e18;
void init()
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(i == j) d[i][j] = 0;
            else d[i][j] = oo;
        }
    }
    for(int u = 1; u <= n; ++u)
    {
        for(auto p : ke[u])
        {
            int v = p.F;
            int w = p.S;
            d[u][v] = w;
            d[v][u] = w;
        }
    }
    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}
int dd[MAXN];
ll ans;
void check(int x)
{
    vector < int > S;
    for(int i = 1; i <= k; ++i) dd[i] = 0;
    for(int i = 1; i <= n; ++i)
    {
        if((x >> (i-1)) & 1)
        {
            for(int j = 1; j <= t[i]; ++j)
            {
                int a = s[i][j];
                dd[a] = 1;
            }
            S.push_back(i);
        }
    }
    //cerr << "x = " <<  x << '\n';
    int dem = 0;
    for(int i = 1; i <= k; ++i)
    {
        //cerr << i << '\n';
        //cerr << dd[i] << '\n';
        dem += dd[i];
    }
    if(dem < l) return;
    int u = 1;
    ll res = 0;
    //cerr << "dem = " << dem << '\n';
    for(auto v : S)
    {
        //cerr << u << " " << v << '\n';
        res += d[u][v];
        //cerr << d[u][v] << '\n';
        u = v;
    }
    res += d[u][n];
    //cerr << "res = " << res << '\n';
    ans = min(res, ans);
}
void sub1()
{
    ans = oo;
    init();
    for(int i = 1; i < (1 << (n)); ++i)
    {
        check(i);
    }
    if(ans == oo ) ans = -1;
}
ll dS[MAXN];
void ijk(int s, ll d[])
{
    d[s] = 0;
    priority_queue < pii > Q;
    Q.push({-d[s], s});
    while(!Q.empty())
    {
        int u = Q.top().S;
        int l = -Q.top().F;
        Q.pop();
        if(l > d[u]) continue;
        for(auto p : ke[u])
        {
            int v = p.F;
            int w = p.S;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({-d[v], v});
            }
        }
    }
}
void sub2()
{
    for(int i = 1; i <= n; ++i) dS[i] = oo;
    ijk(1, dS);
    ans = dS[n];
    if(ans == oo) ans = -1;
}
ll dT[MAXN];
void sub3()
{
    for(int i = 1; i <= n; ++i) dS[i] = oo;
    for(int i = 1; i <= n; ++i) dT[i] = oo;
    ijk(1,dS);
    ijk(n,dT);
    vector < int > p;
    for(int i = 1; i <= n; ++i)
    {
        if(t[i]) p.push_back(i);
    }
    ans = oo;
    for(auto v : p)
    {
        ll res = dS[v] + dT[v];
        ans = min(ans, res);
    }
    if(ans == oo) ans = -1;
}
void out()
{
    cout << ans << '\n';
}
int main()
{
    freopen("DHAKA.inp", "r", stdin);
    freopen("DHAKA.out", "w", stdout);
    read();
    if(n <= 10) sub1();
    else if(l == 0) sub2();
    else if(k == 1) sub3();
    out();
    return 0;
}
