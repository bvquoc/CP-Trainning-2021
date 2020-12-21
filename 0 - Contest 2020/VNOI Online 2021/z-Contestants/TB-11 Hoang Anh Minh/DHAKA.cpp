#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define FORU(i , a , b) for (int i = (a) ; i <= (b) ; i++)
#define FORD(i , a , b) for (int i = (a) ; i >= (b) ; i--)
#define pii pair <int , int>
#define fi first
#define se second
#define task "DHAKA"
#define oo (int)1e18
using namespace std;
const int maxn = 1e5 + 10;
int l , k , n , m;
int d[maxn][35];
vector <pii> adj[maxn];
int watermelon[maxn];
void input()
{
    cin >> n >> m >> k >> l;
    FORU(i , 1 , n)
    {
        int si;
        cin >> si;
        FORU(j , 1 , si)
        {
            int x;
            cin >> x;
            watermelon[i] |= (1 << (x - 1));
        }
    }
    FORU(i , 1 , m)
    {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({v , w});
        adj[v].push_back({u , w});
    }
}
struct pack
{
    int u , w , mask;
    bool operator > (const pack &k) const
    {
        return w > k.w;
    }
};
void dijkstra()
{
    FORU(i , 1 , n) FORU(j , 0 , 32) d[i][j] = oo;
    d[1][watermelon[1]] = 0;
    priority_queue <pack , vector<pack> , greater<pack>> q;
    q.push({1 , 0 , watermelon[1]});
    while (q.size())
    {
        pack tmp = q.top();
        int u = tmp.u , w = tmp.w , mask = tmp.mask;
        q.pop();
        if (d[u][mask] != w) continue;
        for (pii p : adj[u])
        {
            int v = p.fi , uv = p.se , wt = watermelon[v];
            int nMask = mask | wt;
            if (d[v][nMask] > w + uv)
            {
                d[v][nMask] = w + uv;
                q.push({v , d[v][nMask] , nMask});
            }
        }
    }
    int ret = oo;
    FORU(i , 0 , 32)
    {
        int tmp = __builtin_popcount(i);
        if (tmp >= l) ret = min(ret , d[n][i]);
    }
    if (ret == oo) cout << -1;
    else cout << ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp" , "r" , stdin);
    freopen(task".out" , "w" , stdout);
    input();
    dijkstra();
    return 0;
}
