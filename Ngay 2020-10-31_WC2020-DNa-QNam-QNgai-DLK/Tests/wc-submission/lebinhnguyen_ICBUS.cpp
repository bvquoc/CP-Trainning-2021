#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pairt;
vector<int> st[5001],a[5001];
int tr[5001],A[5001][5001],c[5001],d[5001],di[5001],n,k;
void bfs(int ss)
{
    for(int i=1;i<=n;i++)
        tr[i]=1e9;
    tr[ss]=0;
    A[ss][ss]=0;
    queue<int> stt;
    for(int i=0;i<st[ss].size();i++)
        stt.push(st[ss][i]),tr[st[ss][i]]=1;
    while(!stt.empty())
    {
        int u=stt.front();
        stt.pop();
        if(A[ss][u]==1e9)
        {
            a[ss].push_back(u);
            A[ss][u]=c[ss];
            //cout<<tr[u]<<" "<<u<<endl;
            if(tr[u]<d[ss])
            for(int i=0;i<st[u].size();i++)
            {

                int v=st[u][i];
                //cout<<v<<" "<<tr[v]<<" "<<ss<<endl;
                if(tr[v]==1e9)
                {

                stt.push(v);
                tr[v]=tr[u]+1;
                }
            }
        }
    }
}
void dijkstra()
{
    priority_queue< pairt , vector<pairt> ,greater <pairt> > q;
    fill(di+2,di+1+n,1e9);
    di[1]=0;
    q.push({0,1});
    while(!q.empty())
    {
        int cmp=q.top().f;
        int u=q.top().s;
        q.pop();
        if (di[u]==cmp)
        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i];
            int tt=A[u][v];
            if(di[v] > di[u]+tt)
                {
                    di[v]=di[u]+tt;
                    q.push({di[v],v});
                }
        }
    }
}
void build()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        A[i][j]=1e9;
    for(int i=1;i<=n;i++)
        bfs(i);
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>c[i]>>d[i];
    for(int i=1;i<=k;i++)
    {
        int u,v;
        cin>>u>>v;
        st[u].push_back(v);
        st[v].push_back(u);
    }
    build();
    /*for(int i=1;i<=n;i++)
    {
        cout<<i<<endl;
        for(int j:a[i]) cout<<j<<" "<<A[i][j]<<endl;
    }*/
    dijkstra();
    cout<<di[n];
}
