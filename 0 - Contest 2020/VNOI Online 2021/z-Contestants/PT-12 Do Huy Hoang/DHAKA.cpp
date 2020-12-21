#include <bits/stdc++.h>

using namespace std;
#define task "DHAKA"
#define c_bit(x) __builtin_popcount(x)
#define MASK(x) pw[x]
#define BIT(x, i) ((x) & MASK(i))
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) (x & ~MASK(i))
const int MAXN = 1e5 + 7;
const long long INF = 1e18 + 7;
int N, M, K, L;
int pw[34];
int WaterMelon[MAXN];
vector <pair <int, int> > edges[MAXN];
void Input()
{
    cin >> N >> M >> K >> L;
    pw[0] = 1;
    for(int i = 1; i <= 10; i++)
        pw[i] = pw[i - 1] << 1;
    for(int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        while(num--)
        {
            int x;
            cin >> x;
            --x;
            WaterMelon[i] = SET_ON(WaterMelon[i], x);
        }
    }
    for(int i = 1; i <= M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({w, v});
        edges[v].push_back({w, u});
    }
}
long long d[MAXN][36];
struct Node
{
    long long du;
    int u;
    int HaveBought;
};
bool operator < (const Node &x,const Node &other)
{
    return (x.du > other.du);
}
priority_queue <Node> pq;
bool minimize(long long &x, const long long &y)
{
    if(x > y)
    {
        x = y;
        return true;
    }
    return false;
}
void Output()
{
    for(int i = 1; i <= N; i++)
        for(int mask = 0; mask < MASK(K); mask++)
            d[i][mask] = INF;
    d[1][WaterMelon[1]] = 0;
    pq.push({0, 1, WaterMelon[1]});
    while(!pq.empty())
    {
        int u = pq.top().u;
        long long du = pq.top().du;
        int mask = pq.top().HaveBought;
        pq.pop();
        if(d[u][mask] != du)
            continue ;
        for(auto p : edges[u])
        {
            int v = p.second;
            int dv = p.first;
            int newmask = mask | WaterMelon[v];
            if(minimize(d[v][newmask], du + dv))
                pq.push({d[v][newmask], v, newmask});
        }
    }
    long long ans = INF;
    for(int mask = 0; mask < MASK(K); mask++)
        if(c_bit(mask) >= L)
            minimize(ans, d[N][mask]);
    if(ans == INF)
        cout << -1;
    else
        cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    Input();
    Output();
    return 0;
}
