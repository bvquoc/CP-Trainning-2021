#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define ten "dhaka"

using namespace std;

typedef long long ll;
typedef pair<ll, int> pi;
typedef unsigned long long ull;
const ll INF = 1e15;

int n, m, k, l, mask[100003];
ll f[100003][(1 << 5) + 3];
vector<pi> G[100003];

ll trau(int u, int bitmask)
{
    if(u == n && ((int)__builtin_popcount(bitmask) >= l)) return 0;

    ll &res = f[u][bitmask];
    if(res != -1) return res;
    res = INF;

    for(pi d: G[u])
    {
        int v = d.second;
        ll w = d.first;

        res = min(res, trau(v, bitmask | mask[v]) + w);
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(ten".inp", "r", stdin);
    freopen(ten".out", "w", stdout);

    cin >> n >> m >> k >> l;

    for(int i = 1; i <= n; i++)
    {
        int sl;

        cin >> sl;

        while(sl--)
        {
            int typedh;
            cin >> typedh;

            mask[i] |= (1 << (typedh - 1));
        }
    }

    for(int i = 1; i <= m; i++)
    {
        int u, v;
        ll w;

        cin >> u >> v >> w;

        G[u].pb(pi(w, v));
        G[v].pb(pi(w, u));
    }

    memset(f, 255, sizeof(f));

    cout << ((trau(1, 0) >= INF) ? -1LL : trau(1, 0));

    return 0;
}
