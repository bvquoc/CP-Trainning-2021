#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define int long long
using namespace std;
typedef pair<int,int> ii;
int n,m,k,l,u,v,w,z,d[100005],S,f[100005][10][10],c[10];
vector<ii> a[100005];
vector<int> b[10];
void dijkstra()
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i++)
        d[i] = 1e12;
    d[S] = 0;
    pq.push(ii(0,S));
    while (pq.size())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] > du + uv)
            {
                d[v] = du + uv;
                pq.push(ii(d[v],v));
            }
        }
    }
}
int dp(int x,int y,int z)
{
    int &res = f[x][y][z];
    if (res != -1) return res;
    res = 0;
    int minz = 1e12;
    S = x;
    dijkstra();
    if (z > l)
    {
        res = res + d[n];
        return res;
    }
    for (int i = 0; i < b[y].size(); i++)
    {
        res = res + d[b[y][i]];
        res = res + dp(b[y][i], c[y+1],z+1);
        if (minz > res)
            minz = res;
        res -= d[b[y][i]];
        res -= dp(b[y][i], c[y+1],z+1);
    }
    return minz;
}
signed main()
{
    FastIO;
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> z;
        for (int j = 1;j <= z; j++)
        {
            cin >> u;
            b[u].push_back(i);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        a[u].push_back(ii(w,v));
        a[v].push_back(ii(w,u));
    }
    if (l == 0)
    {
        S = 1;
        dijkstra();
        cout << d[n];
        return 0;
    }
    if (k == 1)
    {
        memset(f, -1, sizeof f);
        cout << dp(1,1,1);
        return 0;
    }
    cout << -1;
    return 0;
}
