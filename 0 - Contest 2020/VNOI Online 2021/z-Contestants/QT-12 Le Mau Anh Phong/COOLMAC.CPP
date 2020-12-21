#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int st[MAXN << 2], n, m;

void update(int id, int l, int r, int p, int v)
{
    if (p > r || p < l) return;
    if (l == r) return st[id] = min(st[id], v), void();
    int mid = (l + r) >> 1, g = id << 1;
    update(g, l, mid, p, v);
    update(g | 1, mid + 1, r, p, v);
    st[id] = min(st[g], st[g | 1]);
}

int getMin(int id, int l, int r, int i, int j)
{
    if (i > r || j < l) return INT_MAX;
    if (i <= l && j >= r) return st[id];
    int mid = (l + r) >> 1, g = id << 1;
    return min(getMin(g, l, mid, i, j), getMin(g | 1, mid + 1, r, i, j));
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
        freopen("COOLMAC.INP", "r", stdin);
        freopen("COOLMAC.OUT", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int mx = 100000;
    cin >> m;
    fill(st, st + 4 * mx + 1, INT_MAX);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        update(1, 1, mx, v, u);
    }

    int mi = INT_MAX;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        mi = min(x, mi);
    }

    int r = mx, ans = 0;
    while (r > mi)
    {
        int t = getMin(1, 1, mx, r, mx);
        if (t >= r) return cout << - 1, 0;
        ++ans;
        r = t;
    }
    cout << ans;
    return 0;
}
