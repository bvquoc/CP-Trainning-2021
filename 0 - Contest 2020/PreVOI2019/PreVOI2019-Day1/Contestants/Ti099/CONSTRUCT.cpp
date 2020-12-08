#include <bits/stdc++.h>
using namespace std;
int t, n, m, a[100100];
long long lazy[400100], res;
pair <long long, int> it[400100];
void build(int k, int l, int r)
{
    if (l == r)
    {
        it[k].first = a[l];
        it[k].second = l;
        return;
    }
    int mid = (l + r) / 2;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    it[k] = min(it[k * 2], it[k * 2 + 1]);
}
void dolazy(int k, int l, int r)
{
    it[k].first += lazy[k];
    if (l != r)
    {
        lazy[k * 2] += lazy[k];
        lazy[k * 2 + 1] += lazy[k];
    }
    lazy[k] = 0;
}
void update(int k, int l, int r, int L, int R, long long x)
{
    dolazy(k, l, r);
    if (r < L || l > R)
        return;
    if (L <= l && R >= r)
    {
        it[k].first += x;
        if (l != r)
        {
            lazy[k * 2] += x;
            lazy[k * 2 + 1] += x;
        }
        return;
    }
    int mid = (l + r) / 2;
    update(k * 2, l, mid, L, R, x);
    update(k * 2 + 1, mid + 1, r, L, R, x);
    it[k] = min(it[k * 2], it[k * 2 + 1]);
}
pair <long long, int> get(int k, int l, int r, int L, int R)
{
    dolazy(k, l, r);
    if (r < L || l > R)
        return make_pair(1e18, 0);
    if (L <= l && R >= r)
        return it[k];
    int mid = (l + r) / 2;
    return min(get(k * 2, l, mid, L, R), get(k * 2 + 1, mid + 1, r, L, R));
}
void solve(int l, int r, int x)
{
    if (l > r)
        return;
    pair <long long, int> tmp = get(1, 1, n, l, r);
    //cout << tmp.first << "\n";
    res += (tmp.first - x);
    solve(l, tmp.second - 1, tmp.first);
    solve(tmp.second + 1, r, tmp.first);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CONSTRUCT.inp", "r", stdin);
    freopen("CONSTRUCT.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        build(1, 1, n);
        while (m--)
        {
            int t, l, r;
            cin >> t >> l >> r;
            if (t == 1)
            {
                int x;
                cin >> x;
                update(1, 1, n, l, r, x);
            }
            else
            {
                res = 0;
                solve(l, r, 0);
                cout << res << "\n";
            }
        }
    }
}
