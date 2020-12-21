#include <bits/stdc++.h>

using namespace std;
struct mask
{
    int u, val, mask1, mask2;
};
int n, m, k, l, check[100009], dis[100009];
vector < pair <int,int> > adj[100009];
vector < int > watermelon[100009];
int bitmask()
{
    int ans = INT_MAX;
    queue < mask > q;
    q.push({1,0,1,0});
    while (!q.empty())
    {
        int u = q.front().u;
        int val = q.front().val;
        int mask1 = q.front().mask1;
        int mask2 = q.front().mask2;
        q.pop();
        if (u == n)
        {
            int check = __builtin_popcount(mask2);
            if (check >= l)
                ans = min(ans, val);
            continue;
        }
        for (pair <int,int> i:adj[u])
            if (((mask1>>(i.first-1))&1) == 0)
            {
                int premask = mask2;
                for (int j:watermelon[i.first])
                    premask = mask2|(1<<(j - 1));
                int premask2 = mask1|(1<<(i.first - 1));
                q.push({i.first,val + i.second,premask2,premask});
            }
    }
    return ans;
}
void dijkstra(int x)
{
    fill(dis,dis+n+1,INT_MAX);
    priority_queue < pair <int,int>, vector < pair <int,int> >, greater < pair <int,int> > > pq;
    pq.push({0,x});
    while (!pq.empty())
    {
        int u = pq.top().second;
        int disu = pq.top().first;
        pq.pop();
        if (disu > dis[u])
            continue;
        for (pair < int, int> i:adj[u])
        {
            int v = i.first;
            int disv = i.second;
            if (disv + disu < dis[v])
            {
                dis[v] = disu + disv;
                pq.push({dis[v],v});
            }
        }
    }
}
int main()
{
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; i++)
    {
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++)
        {
            int x;
            cin >> x;
            watermelon[i].push_back(x);
            check[x]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,y});
    }
    if (l == 0)
    {
        dijkstra(1);
        cout << dis[n];
        return 0;
    }
    if (k == 1)
    {
        if (watermelon[1].size() > 0 || watermelon[n].size() > 0)
        {
            dijkstra(1);
            cout << dis[n];
            return 0;
        }
        dijkstra(1);
        vector < pair <int,int> > allow;
        for (int i = 1; i <= n; i++)
            if (watermelon[i].size() > 0 && dis[i] != INT_MAX)
                allow.push_back({i,dis[i]});
        int ans = INT_MAX;
        for (pair <int,int> i:allow)
        {
            dijkstra(i.first);
            ans = min(ans,dis[n] + i.second);
        }
        cout << ans;
        return 0;
    }
    int res = bitmask();
    if (res == INT_MAX)
        cout << -1;
    else
        cout << res;
    return 0;
}
