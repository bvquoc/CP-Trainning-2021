#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long LL;
const int MAXN=100+2e3;
const int inf=1+1e9;
const LL mod=1e9+7;
int n, m, k;

vector< int > g[MAXN];
vector< int > st[MAXN], dem[MAXN];

int nccc[MAXN], delta[MAXN], cnt[MAXN], col[MAXN];

int ncc = 0;

void dfs(int u)
{
    nccc[u] = ncc;

    for (int id = 0; id < g[u].size(); ++id)
    {
        int v = g[u][id];
        if (!nccc[v]) dfs(v);
    }

}

int L = -1, R = -1;

void upd(int l, int r)
{
    if (L == -1)
    {
        L = l;
        R = r;
        return;
    }
    if (R - L + 1 < r - l + 1)
    {
        L = l;
        R = r;
        return;
    }
    if (R - L + 1 == r - l + 1)
    {
        if (L > l)
        {
            L = l;
            R = r;
        }
    }
}

int cur_l[MAXN], cur_r[MAXN];

int main()
{
#define TASK "DECOR"
    if(fopen(TASK ".inp","r"))
    {
        freopen(TASK ".inp","r",stdin);
        freopen(TASK ".out","w",stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i)
    {
        char c;
        cin >> c;
        col[i] = c - '0';
    }

    for (int i = 1; i <= n; ++i)
    {
        cnt[i] = cnt[i - 1] + col[i];
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int u = 1; u <= n; ++u)
    {
        if (!nccc[u])
        {
            ++ncc;
            dfs(u);
        }
    }

    for (int u = 1; u <= n; ++u)
    {
        st[nccc[u]].push_back(u);
        delta[nccc[u]] += col[u];
    }

    for (int i = 1; i <= ncc; ++i)
        cur_l[i] = cur_r[i] = -1;

    for (int l = 1; l <= n; ++l)
    {
        int cur = 0;
        for (int r = l; r <= n; ++r)
        {
            int id = nccc[r];
            int pos = lower_bound(st[id].begin(), st[id].end(), r) - st[id].begin();
            if (cur_l[id] == -1)
            {
                cur_l[id] = pos;
                cur_r[id] = pos;
                cur = cur + min(delta[id], 1);
            }
            else
            {
                cur = cur - min(delta[id], cur_r[id] - cur_l[id] + 1);
                cur_r[id] = pos;
                cur = cur + min(delta[id], cur_r[id] - cur_l[id] + 1);
            }
            if (cur + k >= r - l + 1)
                upd(l, r);
        }
        for (int i = 1; i <= ncc; ++i)
            cur_l[i] = cur_r[i] = -1;
    }

    if (L == -1) cout << -1;
    else cout << L <<' '<< R << '\n';

    return 0;
}
