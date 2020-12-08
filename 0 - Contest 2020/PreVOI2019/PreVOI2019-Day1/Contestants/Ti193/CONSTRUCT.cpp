#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define io ios_base::sync_with_stdio(), cin.tie(0), cout.tie(0)

using namespace std;

const int maxn = 1e5 + 7;

ll a[maxn], res, val[maxn];
int len, n, m, fa[maxn], test;
vector<int> cmp[maxn];
bitset<maxn> d;

int root(int u)
{
    if (fa[u] < 0) return u;
    return fa[u] = root(fa[u]);
}

void join(int u, int v)
{
    u = root(u), v = root(v);
    if (u != v) fa[v] = u, --len;
}

void solve()
{
    while (m--)
    {
        int t, l, r, k;
        cin >> t >> l >> r;
        if (t == 1)
        {
            cin >> k;
            for (int i = l; i <= r; ++i) a[i] += 1LL*k;
        }else
        {
            vector<int> v;
            len = 0, res = 0;
            for (int i = l; i <= r; ++i) v.push_back(a[i]);
            d.reset();
            sort(v.begin(), v.end());
            for (int i = 1; i <= r - l + 1; ++i) cmp[i].clear();
            for (int i = l; i <= r; ++i)
            {
                int p = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
                val[p] = a[i], cmp[p].push_back(i), fa[i] = -1;
            }

            int run = r - l + 1;
            while (cmp[run].empty()) --run;
            val[0] = 0;
            while (run)
            {
                len += (int)cmp[run].size();
                for (auto v: cmp[run])
                {
                    if (d[v + 1]) join(v, v + 1);
                    if (d[v - 1]) join(v, v - 1);
                    d[v] = 1;
                }
                int save = run;
                --run;
                while (cmp[run].empty() && run > 0) --run;
                res += (1LL*len*(val[save] - val[run]));
            }
            cout << res << "\n";
        }
    }
}

void enter()
{
    freopen("CONSTRUCT.INP","r",stdin);
    freopen("CONSTRUCT.OUT","w",stdout);
    io;
    cin >> test;
    while (test--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        solve();
    }
}

int main()
{
    enter();
}
