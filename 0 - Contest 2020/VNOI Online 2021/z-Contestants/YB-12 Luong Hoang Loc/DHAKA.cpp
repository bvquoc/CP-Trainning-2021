#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9+7;
typedef pair<int, int> ii;

vector<ii> a[100007];
int n, m, k, l;
bool check[100007];
int d[10007],res=INT_MAX;

void dijkstra(int temp)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i++)
        d[i] = oo;
    d[temp] = 0;
    pq.push(ii(0, temp));

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
                pq.push(ii(d[v], v));
            }
        }
    }
}

int main()
{
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d%d%d%d", &n, &m, &k, &l);
    for (int i=1; i<=n; i++)
    {
        int x;
        scanf ("%d",&x);
        for (int j=1; j<=x; j++)
        {
            int y;
            check[i]=1;
            scanf("%d",&y);
        }
    }
    for (int i=1; i<=m; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[u].push_back({w,v});
        a[v].push_back({w,u});
    }
    dijkstra(1);
    if (d[n]==oo)
    {
        printf("%d",-1);
        return 0;
    }
    if (l==0)
    {
        printf("%d",d[n]);
        return 0;
    }
    if (k==1)
    {
        for (int i=1;i<=n;i++)
            if (check[i])
            {
                dijkstra(i);
                res=min(res,d[1]+d[n]);
            }
        printf("%d",res);
        return 0;
    }
    printf("%d",-1);
    return 0;
}
