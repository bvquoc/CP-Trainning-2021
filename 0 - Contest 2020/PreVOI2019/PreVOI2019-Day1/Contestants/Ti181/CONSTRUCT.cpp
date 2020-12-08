#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;i++)
#define fid(i,a,b) for(int i=a;i>=b;i--)
#define maxn 100005
#define ll long long
#define pii pair<int, int>
#define TTT "CONSTRUCT"
using namespace std;
int n, m, a[maxn];
ll it[maxn * 4], dc[maxn * 4];
void update(int id, int l, int r, int u, ll val)
{
    if(l > u || r < u) return;
    if(l == r)
    {
        it[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, val);
    update(id * 2 + 1, mid + 1, r, u, val);
    it[id] = it[id * 2] + it[id * 2 + 1];
}
ll get(int id, int l, int r, int u, int v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return it[id];
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
void updatedc(int id, int l, int r, int u, int v, int h)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v)
    {
        dc[id] += h;
        return;
    }
    int mid = (l + r) / 2;
    updatedc(id * 2, l, mid, u, v, h);
    updatedc(id * 2 + 1, mid + 1, r, u, v, h);
}
ll getdc(int id, int l, int r, int u)
{
    if(l > u || r < u) return 0;
    if(l == r) return dc[id];
    int mid = (l + r) / 2;
    return dc[id] + getdc(id * 2, l, mid, u) + getdc(id * 2 + 1, mid + 1, r, u);
}
void solve()
{
    cin >> n >> m;
    fi(i, 1, n)
    {
        cin >> a[i];
        updatedc(1, 1, n, i, i, a[i]);
        int v = max(0, a[i] - a[i - 1]);
        update(1, 1, n, i, v);
    }
    int x, l, r, k;
    ll u, v, tg, res;
    while(m--)
    {
        cin >> x;
        if(x == 1)
        {
            cin >> l >> r >> k;
            updatedc(1, 1, n, l, r, k);
            u = getdc(1, 1, n, l - 1);
            v = getdc(1, 1, n, l);
            if(v - u > 0) tg = v - u; else tg = 0;
            update(1, 1, n, l, tg);
            u = getdc(1, 1, n, r);
            v = getdc(1, 1, n, r + 1);
            if(v - u > 0) tg = v - u; else tg = 0;
            update(1, 1, n, r + 1, tg);
        }
        else
        {
            cin >> l >> r;
            u = getdc(1, 1, n, l - 1);
            v = getdc(1, 1, n, l);
            res = get(1, 1, n, l, r);
            if(v > u) tg = u; else tg = v;
            cout << res + tg << '\n';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(TTT".inp","r",stdin);
    freopen(TTT".out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
        fi(id, 1, 4 * n) it[id] = dc[id] = 0;
    }
}
