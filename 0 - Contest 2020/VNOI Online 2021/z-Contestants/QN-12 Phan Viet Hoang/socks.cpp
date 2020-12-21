#include <bits/stdc++.h>
#define fi first
#define se second
#define fr(i, x, y) for (int i = x; i <= y; ++i)
#define ft(i, x, y) for (int i = y; i >= x; --i)
#define pii pair <int, int>
#define getbit(x, k) ((x) & (1 << (k)))
#define flip(x, k) ((x) ^ (1 << (k)))
#define ll long long
using namespace std;
bool ok_sub2 = false;
int n, q, deg[500010], st, cnt = 1, branch[500010], dd[4], col[500010], max_deg = 0, res = 0, c[2];
vector <int> edge[500010];
void inp ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("socks.inp", "r", stdin);
    freopen ("socks.out", "w", stdout);
    cin >> n >> q;
    fr (i, 1, n)
    {
        cin >> col[i];
        c[col[i]]++;
    }
    fr (i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        deg[u]++;
        deg[v]++;
        max_deg = max(max_deg, max(deg[u], deg[v]));
    }
    fr (i, 1, n)
    {
        if (deg[i] == 3)
        {
            if (!ok_sub2)
            {
                ok_sub2 = true;
                st = i;
            }
            else
            {
                ok_sub2 = false;
                break;
            }
        }
    }
}
void sub1 ()
{
    int sum = 0;
    fr (i, 1, 3) sum += dd[i];
    if (c[1] == 0 or sum == 1) cout << "0\n";
    else cout << "1\n";
    while (q--)
    {
        int x;
        cin >> x;
        if (col[x])
        {
            c[1]--;
            col[x] = 0;
        }
        else
        {
            c[1]++;
            col[x] = 1;
        }
        sum = 0;
        fr (i, 1, 3) sum += dd[i];
        if (c[1] == 0 or sum == 1) cout << "0\n";
        else cout << "1\n";
    }
    exit(0);
}
void dfs_sub2 (int u, int p)
{
    branch[u] = cnt;
    if (col[u]) dd[cnt]++;
    if (edge[u].size() == 1) cnt++;
    for (int v : edge[u])
    {
        if (v == p) continue;
        dfs_sub2 (v, u);
    }
}
void sub2 ()
{
    dfs_sub2 (st, st);
    int check = 0, sum = 0;
    fr (i, 1, 3)
    {
        check += (dd[i] > 0);
        sum += dd[i];
    }
    if (check == 3) cout << "2\n";
    else
    {
        if (check == 0 or sum == 1) cout << "0\n";
        else cout << "1\n";
    }
    while (q--)
    {
        int x;
        cin >> x;
        if (col[x] == 1)
        {
            col[x] = 0;
            dd[branch[x]]--;
        }
        else
        {
            col[x] = 1;
            dd[branch[x]]++;
        }
        check = 0, sum = 0;
        fr (i, 1, 3)
        {
            check += (dd[i] > 0);
            sum += dd[i];
        }
        if (check == 3) cout << "2\n";
        else
        {
            if (check == 0 or sum == 1) cout << "0\n";
            else cout << "1\n";
        }
    }
    exit(0);
}
void dfs (int u, int p)
{
    if (cnt == 0) branch[u] = max(branch[u], col[u]);
    if (u == st) branch[u] = 0;
    if (edge[u].size() == 1) cnt = 0;
    if (branch[u] == 1 and edge[u].size() == 1) res++;
    for (int v : edge[u])
    {
        if (v == p) continue;
        branch[v] = max(branch[u], col[v]);
        cnt++;
        dfs (v, u);
    }
}
void sub3 ()
{
    fr (i, 1, n) if (edge[i].size() > 1)
    {
        st = i;
        break;
    }
    res = 0;
    dfs (st, st);
    cout << (res + 1) / 2 << "\n";
    while (q--)
    {
        res = 0;
        int x;
        cin >> x;
        if (col[x]) col[x] = 0;
        else col[x] = 1;
        branch[st] = 0;
        cnt = 0;
        dfs (st, st);
//        cout << " " << " " << res << "\n";
        cout << (res + 1) / 2 << "\n";
    }
}
int main ()
{
    inp();
    if (max_deg == 2) sub1();
    if (max_deg == 3 and ok_sub2) sub2();
    sub3();
    return 0;
}
