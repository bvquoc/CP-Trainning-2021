#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

long long c[20][20];

int q[100005],n,m,k,l,hang[20];

vector <int> a[100005];

bool dd[20];

long long ans;

vector < pair<int,long long> > adj[100003];

long long d[3][100005];

long long tinh(int x)
{
    long long tmp = 0;
    for (int i = 1;i < x;i++)
    {
        int u = hang[i];
        int v = hang[i + 1];
        if (c[u][v] == 0) return -1;
        tmp = tmp + c[u][v];
    }
    return tmp;
}

bool check(int x)
{
    set <int> s;
    for (int i = 1;i <= x;i++)
        if (a[hang[i]].size() > 0)
            for (int j = 0;j < a[hang[i]].size();j++)
                s.insert(a[hang[i]][j]);

    if (s.size() >= l) return true;
    else return false;
}

void TRY(int i)
{
    for (int j = 1;j <= n;j++)
        if (dd[j] == false)
        {
            dd[j] = true;
            hang[i] = j;
            if (j != n)
                TRY(i + 1);
            else
                if (check(i) && tinh(i) != -1)
                {
                    if (ans == -1) ans = tinh(i);
                    else ans = min(ans,tinh(i));
                }
            dd[j] = false;
        }
}

void dijkstra(int b,int sp)
{
    for (int i = 1;i <= n;i++)
        d[b][i] = 1e15;
    set < pair<long long,int> > s;
    s.insert({0,sp});d[b][sp] = 0;
    while (s.size() > 0)
    {
        pair <long long,int> tmp = *s.begin();s.erase(s.begin());
        long long W = tmp.fi;int u = tmp.se;
        if (W > d[b][u]) continue;
        for (int i = 0;i < adj[u].size();i++)
        {
            int v = adj[u][i].fi;long long w = adj[u][i].se;
            if (w + W < d[b][v])
            {
                d[b][v] = w + W;
                s.insert({d[b][v],v});
            }
        }
    }
}

int main()
{
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(0);cin.tie(0);
    cin >> n >> m >> k >> l;
    if (l == 0)
    {
        for (int i = 1;i <= n;i++)
        {
            int q,x;
            cin >> q;
            for (int j = 1;j <= q;j++)
            {
                cin >> x;
                a[i].push_back(x);
            }
        }
        for (int i = 1;i <= m;i++)
        {
            long long u,v,w;
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dijkstra(1,1);
        if (d[1][n] == 1e15) cout << -1;
        else cout << d[1][n];
        return 0;
    }
    if (k == 1)
    {
        for (int i = 1;i <= n;i++)
        {
            int q,x;
            cin >> q;
            for (int j = 1;j <= q;j++)
            {
                cin >> x;
                a[i].push_back(x);
            }
        }
        for (int i = 1;i <= m;i++)
        {
            long long u,v,w;
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dijkstra(1,1);
        dijkstra(2,n);
        ans = 1e15;
        for (int i = 1;i <= n;i++)
            if (a[i].size() > 0)
                ans = min(ans,d[1][i] + d[2][i]);
        if (ans == 1e15) cout << -1;
        else cout <<ans;
        return 0;
    }
    if (n < 10)
    {
        for (int i = 1;i <= n;i++)
        {
            int q,x;
            cin >> q;
            for (int j = 1;j <= q;j++)
            {
                cin >> x;
                a[i].push_back(x);
            }
        }
        for (int i = 1;i <= m;i++)
        {
            long long u,v,w;
            cin >> u >> v >> w;
            if (c[u][v] == 0)
            {
                c[u][v] = w;c[v][u] = w;
            }
            else
                if (c[u][v] > w)
                {
                    c[u][v] = w;c[v][u] = w;
                }
        }
        ans = -1;
        hang[1] = 1;dd[1] = true;
        TRY(2);
        cout << ans;
        return 0;
    }
    return 0;
}
