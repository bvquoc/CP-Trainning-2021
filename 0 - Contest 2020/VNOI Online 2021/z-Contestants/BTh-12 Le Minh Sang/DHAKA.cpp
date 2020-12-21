#include <bits/stdc++.h>
#define TASK "DHAKA"
#define X first
#define Y second
#define ll long long
#define pi pair<int,int>
#define Bit(i) (1<<(i))
#define Get_Bit(i,x) (((x)>>i)&1)
#define pii pair<pair<ll,int>,int>

using namespace std;
const int N = 1e5 + 5;
const ll MAXN = 1e18;
int n,m,k,l,b[40];
ll d[N][40],res;
vector<pair<int,ll> > ke[N];

void Dij()
{
    for (int i=1; i<=n; ++i) for (int j=0; j<Bit(k); ++j)
        d[i][j] = MAXN;

    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push({{0,1},b[1]});
    d[1][b[1]] = 0;
    while (!q.empty()) {
        int u = q.top().X.Y;
        ll du = q.top().X.X;
        int bit = q.top().Y;
        q.pop();
        if (du!=d[u][bit]) continue;
        for (int i=0; i<ke[u].size(); ++i) {
            int v = ke[u][i].X;
            ll w = ke[u][i].Y;
            int n_b = bit | b[v];
            if (d[v][n_b] > du + w) {
                d[v][n_b] = du + w;
                q.push({{d[v][n_b],v},n_b});
            }
        }
    }
    res = MAXN;
    for (int i=0; i<Bit(k); ++i) {
        int tmp = __builtin_popcount(i);
        if (tmp>=l) res = min(res,d[n][i]);
    }
    if (res==MAXN) cout << -1; else cout << res;
}

void Sub5()
{
    Dij();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    cin >> n >> m >> k >> l;
    for (int i=1; i<=n; ++i) {
        int x;  cin >> x;
        for (int j=1; j<=x; ++j) {
            int y;  cin >> y;
            b[i] += Bit(y-1);
        }
    }
    for (int i=1; i<=m; ++i) {
        int u,v;    ll w;  cin >> u >> v >> w;
        ke[u].push_back({v,w});
        ke[v].push_back({u,w});
    }
    Sub5();
    return 0;
}
