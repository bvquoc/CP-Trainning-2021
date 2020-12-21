#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 7;

int par[MAXN], cnt[MAXN], n, m, k;
bool a[MAXN];

int root(int u)
{
    return par[u] < 0 ? u : par[u] = root(par[u]);
}

void join(int u, int v)
{
    if ((u = root(u)) == (v = root(v))) return;
    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    cnt[u] += cnt[v];
    par[v] = u;
}

int check(int len)
{
    vector <int> D(n + 7, 0);
    int c = 0;
    for (int i = 1; i <= n; ++i)
    {
        int u = root(i);
        if (++D[u] <= cnt[u]) ++c;
        if (i > len)
        {
            int v = root(i - len);
            if (--D[v] < cnt[v]) --c;
        }

        if (c + k >= len && i >= len) return i;
    }

    return 0;
}

int main()
{
    if (fopen("tst.inp", "r"))
    {
        freopen("tst.inp", "r", stdin);
        freopen("tst.out", "w", stdout);
    }
    else
    {
        freopen("DECOR.INP", "r", stdin);
        freopen("DECOR.OUT", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        char x;
        cin >> x;
        a[i] = x == '1';
        par[i] = - 1;
        cnt[i] = a[i];
    }

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        join(u, v);
    }

    int l = 1, r = n, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }

    if (!ans) cout << - 1;
    else
    {
        int t = check(ans);
        cout << t - ans + 1 << ' ' << t;
    }
    return 0;
}
