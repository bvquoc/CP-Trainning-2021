#include <bits/stdc++.h>
#define debug(x) cerr << #x << "=" << x << endl;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define task "SHOCKS"
using namespace std;
const int MaxN = 500001;
int n, q, cnt, c[MaxN];
vector<int> f[MaxN];
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++)
    {
        cin >> c[i];
        if (c[i] == 1) cnt++;
    }
    for (int i=1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        f[u].push_back(v);
        f[v].push_back(u);
    }
    if (cnt == 0) cout << 0 << '\n';
    else cout << 1 << '\n';
    while (q--)
    {
        int x;
        cin >> x;
        if (c[x] == 1)
        {
            cnt--;
            c[x] = 0;
        }
        else
        {
            cnt++;
            c[x] = 0;
        }
        if (cnt == 0) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
#ifdef dungctb
    cerr << "Time collapse : " << fixed << setprecision(3) << 1.000*clock()/CLOCKS_PER_SEC;
#endif // dungctb

    return 0;
}
