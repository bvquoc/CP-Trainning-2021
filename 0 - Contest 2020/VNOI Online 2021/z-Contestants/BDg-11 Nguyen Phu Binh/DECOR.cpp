#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 5e5 + 5;

int a[N];
int cnt[N];
int cur[N];
int par[N];
int n,m,k,egg;

int getpar(int u)
{
    return (par[u] < 0) ? u : (par[u] = getpar(par[u]));
}

void join(int u, int v)
{
    u = getpar(u);
    v = getpar(v);
    if (u == v)
        return;
    if (par[u] > par[v])
        swap(u, v);
    par[u] += par[v];
    par[v] = u;
}

void add(int i)
{
    int p = getpar(i);
    cur[p]++;
    if (cur[p] <= cnt[p])
        egg++;
}

void sub(int i)
{
    int p = getpar(i);
    cur[p]--;
    if (cur[p] < cnt[p])
        egg--;
}

void proc()
{
    for (int i = 1; i <= n; i++)
        cnt[getpar(i)] += a[i];

    egg = 0;
    int l = 0, r = -1;
    for (int i = 1, j = 1; i <= n; i++)
    {
        add(i);
        while (egg + k < (i - j + 1))
        {
            sub(j);
            j++;
        }

        if (i - j + 1 > r - l + 1)
        {
            l = j;
            r = i;
        }
    }
    if (l == 0)
        cout << -1;
    else
        cout << l << " " << r;
}

void enter()
{
    cin >> n >> m >> k;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        a[i] = s[i - 1] - '0';
    }
    for (int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        join(u, v);
    }
}

void preproc()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
}

int main()
{
    preproc();
    enter();
    proc();
    return 0;
}
