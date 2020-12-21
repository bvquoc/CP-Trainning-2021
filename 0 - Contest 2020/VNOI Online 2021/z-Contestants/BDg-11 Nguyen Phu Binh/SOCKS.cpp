#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 5e5 + 5;

vector <int> adj[N];

int sum[N];
int cnt[5];
int a[N];
int f[N];
int h[N];
int c[N];
int deg[N];
int n,q,node;

void sub1()
{
    int root = 1;
    for (int i = 1; i <= n; i++) if (deg[i] == 1)
    {
        root = i;
        break;
    }

    for (int i = 1; i <= n; i++)
        node += c[i];

    cout << (node >= 2) << "\n";
    for (int i = 1; i <= q; i++)
    {
        int id;
        cin >> id;
        if (c[id] == 1)
            node--;
        else
            node++;
        c[id] ^= 1;
        cout << (node >= 2) << "\n";
    }

}

void dfs(int u, int p)
{
    for (int v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

int calcsub2()
{
    if (node == 1)
        return 0;
    int num = 0;
    for (int i = 1; i <= 3; i++)
    {
        num += cnt[i] > 0;
    }
    if (num <= 2)
        return 1;
    else
        return 2;
}

void sub2()
{
    int root = 0;
    for (int i = 1; i <= n; i++) if (deg[i] == 3)
    {
        root = i;
        break;
    }

    int color = 0;
    for (int v : adj[root])
    {
        h[v] = 1;
        dfs(v, root);
        color++;
        for (int i = 1; i <= n; i++) if (a[i] == 0 && h[i] > 0)
        {
            a[i] = color;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cnt[a[i]] += c[i];
        node += c[i];
    }
    cout << calcsub2() << "\n";

    for (int i = 1; i <= q; i++)
    {
        int id;
        cin >> id;
        if (c[id] == 1)
        {
            node--;
            cnt[a[id]]--;
        } else {
            node++;
            cnt[a[id]]++;
        }
        c[id] ^= 1;
        cout << calcsub2() << "\n";
    }
}

void proc()
{
    int mx = *max_element(deg + 1, deg + n + 1);

    if (mx <= 2)
        sub1();
    else if (mx == 3) {
        sub2();
    }
}

void enter()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
}

void preproc()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SOCKS.inp","r",stdin);
    freopen("SOCKS.out","w",stdout);
}

int main()
{
    preproc();
    enter();
    proc();
    return 0;
}
