//Tran Thuy Duong
#include <bits/stdc++.h>
#define maxn 100005
#define maxc 1000000009
#define MOD 1000000007
#define task "CONSTRUCT"
#define reset(x) memset(x, 0, sizeof x)
#define remain(x) ((x >= MOD) ? (x-MOD) : x)
#define pll pair<ll,ll>
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
const ll MM = 1ll * MOD * MOD;

int T, n, m;
ll a[maxn];
ll t[4*maxn], p[4*maxn], f[4*maxn], lazy[4*maxn];
void init(int node, int l, int r)
{
    if (l == r) {t[node] = p[node] = f[node] = a[l]; return;}
    int mid = (r + l) >> 1;
    init(node * 2, l, mid); init(node * 2 + 1, mid + 1, r);
    t[node] = a[l]; p[node] = a[r];
    f[node] = f[node * 2] + f[node * 2 + 1] - min(p[node * 2], t[node * 2 + 1]);
}
void Lazy(int node)
{
    if (lazy[node] == 0) return;
    t[node] += lazy[node];
    p[node] += lazy[node];
    f[node] += lazy[node];
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
    lazy[node] = 0;
}
void update(int node, int l, int r, int u, int v, int k)
{
    Lazy(node);
    if (r < u || v < l) return;
    if (u <= l && r <= v) {lazy[node] += k; Lazy(node); return;}
    int mid = (r + l) >> 1;
    update(node * 2, l, mid, u, v, k);
    update(node * 2 + 1, mid + 1, r, u, v, k);
    t[node] = t[node * 2]; p[node] = p[node * 2 + 1];
    f[node] = f[node * 2] + f[node * 2 + 1] - min(p[node * 2], t[node * 2 + 1]);
}
pll get(int node, int l, int r, int u, int v, bool b)
{
    Lazy(node);
    if (r < u || v < l) return {0, 0};
    if (u <= l && r <= v) return {f[node], (b ? p[node] : t[node])};
    int mid = (r + l) >> 1;
    pll trai = get(node * 2, l, mid, u, v, 1);
    pll phai = get(node * 2 + 1, mid + 1, r, u, v, 0);
    return {trai.F + phai.F - min(trai.S, phai.S), (b ? p[node] : t[node])};
}
void Solve()
{
    init(1, 1, n);
    int type, l, r, k;
    while (m--)
    {
        cin >> type >> l >> r;
        if (type == 1) {cin >> k; update(1, 1, n, l, r, k);}
        else
        {
            pll ans = get(1, 1, n, l, r, 0);
            cout << ans.F << "\n";
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(task".INP", "r", stdin);
	freopen(task".OUT", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i=1; i<=n; i++) cin >> a[i];
        Solve();
    }
	return 0;
}
