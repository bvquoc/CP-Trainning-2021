#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define reset(x) memset(x, 0, sizeof x)
#define MIN(x,y) {if (x > (y)) x = (y);}
#define MAX(x,y) {if (x < (y)) x = (y);}
#define remain(x) while (x >= MOD) x -= MOD
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 100010
#define maxC INT_MAX
#define MOD 1000000007
#define ll long long
#define pii pair <int, int>
#define task "CONSTRUCT"

using namespace std;

int n, m, a[maxn], b[maxn];

ll tim(int l, int r)
{
    if (l == r) return b[l];
    ll res = 0;
    int x = maxC;
    FOR(i, l, r) MIN(x, b[i]);
    FOR(i, l, r) b[i] -= x;
    res += x;
    int luu = l;
    FOR(i, l, r)
        if (b[i] == 0)
        {
            if (i == luu) {luu = i + 1; continue;}
            res += tim(luu, i-1);
            luu = i + 1;
        }
    if (luu != r+1)
        res += tim(luu, r);
    return res;
}

int main()
{
    ios_base:: sync_with_stdio(NULL);
    cin. tie(NULL) ; cout. tie(NULL);
    freopen(task".INP" , "r", stdin);
    freopen(task".OUT", "w", stdout);
    int T; cin >> T;
    while(T--)
    {
        cin >> n >> m;
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, m)
        {
            int type, u, v, k;
            cin >> type;
            if (type == 1)
            {
                cin >> u >> v >> k;
                FOR(j, u, v) a[j] += k;
            }
            else
            {
                cin >> u >> v;
                FOR(j, u, v) b[j] = a[j];
                cout << tim(u, v) << "\n";
            }
        }
    }
    return 0;
}
