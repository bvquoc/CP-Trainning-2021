#include <bits/stdc++.h>
using namespace std;
ifstream f;
ofstream g;
struct bg
{
    long long  x;
    long long ts;
};
struct cnp
{
    bool operator() (bg a,bg b)
    {
        return a.ts>b.ts;
    }
};
priority_queue <bg,vector<bg>,cnp> h;
long long n,m,p,l,k,dd[1000000];
long long d[1000000];
vector <bg> a[1000000];
void Dijkstra(int s)
{
    d[s]=0;
    bg w;
    w.x=s;
    w.ts=d[s];
    h.push(w);
    while (!h.empty())
    {
        long long u=h.top().x;
        dd[u]=1;
        h.pop();
        for (int i=0;i<a[u].size();i++)
        {
            long long  v=a[u][i].x;
            long long  cost=a[u][i].ts;
            if (dd[v]==0)
            {
                if (d[v]>d[u]+cost)
                {
                    d[v]=d[u]+cost;
                    w.x=v;
                    w.ts=d[v];
                    h.push(w);
                }
            }
        }
    }
}
int main()
{
    f.open("dijkstra.inp");
    g.open("dijkstra.out");
    cin>>n>>m>>p>>l>>k;
    bg w;
    long long u,v,gt;
    for (int i=1;i<=m;i++)
    {
        cin>>u>>v>>gt;
            w.x=v;
            w.ts=gt;
            a[u].push_back(w);
            w.x=u;
            w.ts=gt;
            a[v].push_back(w);
    }
    for (int i=1;i<=n;i++)
    {
        d[i]=1e15;
        dd[i]=0;
    }
    Dijkstra(1);
    cout<<d[n];
    f.close();
    g.close();
    return 0;
}
