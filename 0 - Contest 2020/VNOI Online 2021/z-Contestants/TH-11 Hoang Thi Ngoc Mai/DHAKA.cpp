#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define ll long long
#define oo 1000000000000000
#define fi first
#define se second

int n, m, l, k;
int s[N], melon[N][6];
typedef pair < ll, int > ii;
vector < ii > a[N];
ll d[N], c[N];

void read()
{
    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; i ++)
    {
        cin >> s[i];
        for(int j = 1; j <= s[i]; j ++)
            cin >> melon[i][j];
    }
    int u, v, w;
    for(int i = 1; i <= m; i ++)
    {
        cin >> u >> v >> w;
        a[u].push_back(ii(w, v));
        a[v].push_back(ii(w, u));
    }
}

void Dijkstra(int x)
{
    priority_queue < ii, vector < ii >, greater < ii > > q;
    int i, u, v, du, uv;
    fill(d + 1, d + n + 1, oo);
    q.push(ii(0, x));
    d[x] = 0;
    while(!q.empty())
    {
        u = q.top().se;
        du = q.top().fi;
        q.pop();
        if(du != d[u])
            continue;
        for(i = 0; i < a[u].size(); i ++)
        {
            v = a[u][i].se;
            uv = a[u][i].fi;
            if(d[v] > du + uv)
            {
                d[v] = du + uv;
                q.push(ii(d[v], v));
            }
        }
    }
}

void sub1()
{

}

void sub2()
{
    Dijkstra(1);
    if(d[n] != oo)
        cout << d[n];
    else
        cout << -1;
}

void sub3()
{
    ll res = oo;
    Dijkstra(1);
    for(int i = 1; i <= n; i ++)
        c[i] = d[i];
    Dijkstra(n);
    for(int i = 1; i <= n; i ++)
        if(s[i] != 0)
            res = min(res, d[i] + c[i]);
    if(res == oo)
        cout << -1;
    else
        cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DHAKA.INP", "r", stdin);
    freopen("DHAKA.OUT", "w", stdout);
    read();
//    if(n <= 10)
//    {
//        sub1();
//        return 0;
//    }
    if(l == 0)
    {
        sub2();
        return 0;
    }
    if(k == 1)
    {
        sub3();
        return 0;
    }
    return 0;
}
