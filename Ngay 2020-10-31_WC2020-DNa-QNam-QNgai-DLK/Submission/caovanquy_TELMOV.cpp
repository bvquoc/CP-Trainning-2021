#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<long long,ii> lii;
const int N = 1e4+5;
const long long oo = 1e14+5;
long long d[N];
vector<ii> ds[N];
int n,m,p,l,k;
priority_queue<ii,vector<ii>,greater<ii> > pq;
void dijkstra()
{
        for (int i = 1; i <= n; i++)
            d[i]=+oo;
        d[1]=0;
        pq.push(ii(0,1));
        while (!pq.empty())
        {
            long long du = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (du != d[u])
                continue;
            if (u == n)
            {
                cout<<d[n];
                return ;
            }
            for (auto adj : ds[u])
            {
                int v = adj.first,w = adj.second;
                if (d[v]>d[u]+w)
                {
                    d[v]=d[u]+w;
                    pq.push(ii(d[v],v));
                }
            }

        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    #ifndef ONLINE_JUDGE
//    freopen("telmov.inp","r",stdin);
//    freopen("telmov.out","w",stdout);
//    #endif // ONLINE_JUDGE
    cin >> n >> m >> p >> l >> k;
    while (m--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        ds[u].push_back(ii(v,w));
        ds[v].push_back(ii(u,w));
    }
    dijkstra();
}
