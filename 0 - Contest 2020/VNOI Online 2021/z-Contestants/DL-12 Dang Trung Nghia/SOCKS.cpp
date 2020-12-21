#include<bits/stdc++.h>
using namespace std;

typedef pair<long, long> ii;

long n, Q, c[500005], deg[500005];
vector<long> g[500005];

void sub1()
{
    long cnt = 0;
    for (long i = 1; i <= n; i++) cnt += c[i];
    if (cnt > 1) cout << 1 << '\n';
    else cout << 0 << '\n';
    while (Q--)
    {
        long u;
        cin >> u;
        cnt -= c[u];
        c[u] = 1 - c[u];
        cnt += c[u];
        if (cnt > 1) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}

void sub2()
{
    long root = 0;
    for (long i = 1; i <= n; i++) if (deg[i] == 3) root = i;
    long v = g[root][1];
    while (g[v].size() != 1)
    {
        deg[v] = -1;
        for (long nv: g[v])
        {
            if (nv != root)
            {
                root = v;
                v = nv;
                break;
            }
        }
    }
    deg[v] = -1;
    for (long i = 1; i <= n; i++) if (deg[i] == 3) root = i;
    v = g[root][0];
    while (g[v].size() != 1)
    {
        deg[v] = -2;
        for (long nv: g[v])
        {
            if (nv != root)
            {
                root = v;
                v = nv;
                break;
            }
        }
    }
    deg[v] = -2;

    for (long i = 1; i <= n; i++) if (deg[i] != -1 && deg[i] != -2 && deg[i] != 3) deg[i] = -3;
    for (long i = 1; i <= n; i++) if (deg[i] == 3) root = i;
    long cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (long i = 1; i <= n; i++)
    {
        if (deg[i] == -1) cnt1 += c[i];
        if (deg[i] == -2) cnt2 += c[i];
        if (deg[i] == -3) cnt3 += c[i];
    }


    if (c[root] == 0)
    {
        if (cnt1 && cnt2 && cnt3)
        {
            cout << 2 << '\n';
        }
        if (((cnt1 > 0) + (cnt2 > 0) + (cnt3 > 0)) == 2)
        {
            cout << 1 << '\n';
        }
        if (((cnt1 > 0) + (cnt2 > 0) + (cnt3 > 0)) == 1)
        {
            if (cnt1 + cnt2 + cnt3 > 1) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
    else
    {
        if (cnt1 && cnt2 && cnt3)
        {
            cout << 2 << '\n';
        }
        if (((cnt1 > 0) + (cnt2 > 0) + (cnt3 > 0)) == 2)
        {
            cout << 1 << '\n';
        }
        if (((cnt1 > 0) + (cnt2 > 0) + (cnt3 > 0)) == 1)
        {
            cout << 1 << '\n';
        }
        if (((cnt1 > 0) + (cnt2 > 0) + (cnt3 > 0)) == 0)
        {
            cout << 0 << '\n';
        }
    }

    while (Q--)
    {
        long u;
        cin >> u;
        if (deg[u] == -1) cnt1 -= c[u];
        if (deg[u] == -2) cnt2 -= c[u];
        if (deg[u] == -3) cnt3 -= c[u];
        c[u] = 1 - c[u];
        if (deg[u] == -1) cnt1 += c[u];
        if (deg[u] == -2) cnt2 += c[u];
        if (deg[u] == -3) cnt3 += c[u];
        if (c[root] == 0)
        {
            if (cnt1 && cnt2 && cnt3)
            {
                cout << 2 << '\n';
            }
            if (((cnt1 > 0) + (cnt2 > 0) + (cnt3 > 0)) == 2)
            {
                cout << 1 << '\n';
            }
            if (((cnt1 > 0) + (cnt2 > 0) + (cnt3 > 0)) == 1)
            {
                if (cnt1 + cnt2 + cnt3 > 1) cout << 1 << '\n';
                else cout << 0 << '\n';
            }
        }
        else
        {
            if (cnt1 && cnt2 && cnt3)
            {
                cout << 2 << '\n';
            }
            if (((cnt1 > 0) + (cnt2 > 0) + (cnt3 > 0)) == 2)
            {
                cout << 1 << '\n';
            }
            if (((cnt1 > 0) + (cnt2 > 0) + (cnt3 > 0)) == 1)
            {
                cout << 1 << '\n';
            }
            if (((cnt1 > 0) + (cnt2 > 0) + (cnt3 > 0)) == 0)
            {
                cout << 0 << '\n';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("SOCKS.INP", "r", stdin);
    freopen("SOCKS.OUT", "w", stdout);
    cin >> n >> Q;
    for (long i = 1; i <= n; i++) cin >> c[i];

    bool ssub1 = true, subT = true;
    long cnt3 = 0;

    for (long i = 1; i <= n - 1; i++)
    {
        long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
        if (deg[u] > 2 || deg[v] > 2) ssub1 = false;
        if (deg[u] > 3 || deg[v] > 3) subT = false;
        cnt3 += (deg[u] == 3);
        cnt3 += (deg[v] == 3);
    }

    if (ssub1)
    {
        sub1();
        return 0;
    }
    if (cnt3 == 1 && subT)
    {
        sub2();
        return 0;
    }
    return 0;
}
