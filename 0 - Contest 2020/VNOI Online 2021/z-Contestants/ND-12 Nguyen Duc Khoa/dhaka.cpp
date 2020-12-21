#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define N 100009
#define ll long long
#define pii pair < int, int >
#define pli pair < ll, int >
#define plpii pair < ll, pii >

using namespace std;

int n, m, k, l, s, u, v, bit, tt_, t;
int tt[N];
ll f[N][40];
vector < pli > a[N];
priority_queue < plpii, vector < plpii >, greater < plpii > > pq;
plpii x;
ll w, res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("dhaka.inp", "r", stdin);
    freopen("dhaka.out", "w", stdout);
    cin >> n >> m >> k >> l;
    for(int i=1; i<=n; ++i)
    {
        cin >> s;
        tt[i] = 0;
        for(int j=1; j<=s; ++j)
        {
            cin >> t;
            t--;
            t = (1 << t);
            tt[i] = tt[i] + t;
        }
    }

    for(int i=1; i<=m; ++i)
    {
        cin >> u >> v >> w;
        a[u].pb({w, v});
        a[v].pb({w, u});
    }

    memset(f, -1, sizeof(f));
    f[1][tt[1]] = 0;
    pq.push({0, {1, tt[1]}});

    res = -1;
    while(pq.size())
    {
        x = pq.top(); pq.pop();
        u = x.S.F; bit = x.S.S;
        if(f[u][bit] != x.F)
            continue;

        if(u == n && __builtin_popcount(bit) >= l)
        {
            res = x.F;
            break;
        }

        for(int i=0; i<a[u].size(); ++i)
        {
            v = a[u][i].S; w = a[u][i].F + x.F;
            tt_ = bit | tt[v];
            if(f[v][tt_] == -1 || f[v][tt_] > w)
            {
                f[v][tt_] = w;
               // cout << v << ' ' << tt_ << ' ' << w << '\n';
                pq.push({w, {v, tt_}});
            }
        }
    }

    cout << res;
    return 0;
}
