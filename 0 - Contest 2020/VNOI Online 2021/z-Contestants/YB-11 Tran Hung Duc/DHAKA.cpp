#include <bits/stdc++.h>
#define nmax 100007
#define X first
#define Y second
using namespace std;
typedef pair <int,int> ii;
int n,m,k,l;
vector <ii> g[nmax];
vector <int> ml[nmax];
int dist1[nmax],dist[nmax];
priority_queue <ii, vector <ii>, greater <ii>> pq;
int lil[17][17],tmp[17],dd[17];
set <int> st;
void Dijkstra(int s, int p[])
{
    for (int i=1; i<=n; i++) p[i]=1e9;
    p[s]=0;
    pq.push(ii(0,s));
    while (pq.size())
    {
        ii top=pq.top();
        pq.pop();
        int u=top.Y;
        int du=top.X;
        if (du>p[u]) continue;
        for (auto xx : g[u])
        {
            int v=xx.Y;
            int dv=xx.X;
            if (du+dv<p[v])
            {
                p[v]=du+dv;
                pq.push(ii(p[v],v));
            }
        }
    }
}
void sub2()
{
    Dijkstra(1,dist);
    cout << (dist[n]==1e9 ? -1 : dist[n]);
}
void sub3()
{
    Dijkstra(1,dist);
    Dijkstra(n,dist1);
    int kq=1e18;
    for (int i=1; i<=n; i++)
    {
        cout << i << " " << dist[i] << " " << dist1[i] << '\n';
        if (ml[i].size()>0) kq=min(kq,dist[i]+dist1[i]);
    }
    cout << kq;
}
int main()
{
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    cin >> n >> m >> k >> l;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        for (int j=1; j<=x; j++)
        {
            int y;
            cin >> y;
            ml[j].push_back(x);
            st.insert(y);
        }
    }
    for (int i=1; i<=m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back(ii(w,v));
        g[v].push_back(ii(w,u));
    }
    if (st.size()<l)
    {
        cout << -1;
        return 0;
    }
    if (k==0) sub2();
    if (l==1) sub3();
    return 0;
}
