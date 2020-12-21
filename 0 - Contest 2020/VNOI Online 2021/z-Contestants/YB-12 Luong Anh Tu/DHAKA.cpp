#include<bits/stdc++.h>
#define file "DHAKA"
#define oo 999999999
#define pii pair<int,int>
using namespace std;
int n,m,k,l;
vector<int> h[100002];
vector<pii> g[100002];
int d2[100003];
int d1[100003];
bool kt[100002];
set<int> hoa;
int minn=999999999;

void update(int i)
{
    if (i>=minn) return;
    set<int> st;
    for (int i=1; i<=n; i++)
    if (kt[i]==1)
    {
      for(auto vv:h[i])
       st.insert(vv);
    }
    if (st.size()>=l) minn=i;
}
void dfs(int s,int i)
{
    kt[s]=1;
    if (s == n)
        update(i);
    else
    for (auto vv:g[s])
    if (kt[vv.second]==0)
        dfs(vv.second,i+vv.first);
    kt[s]=0;
}

void dijkstra(int s, int d[])
{
    for(int i=1; i<=n; i++)
        d[i]=oo;
    d[s]=0;
    priority_queue<pii, vector<pii>, greater<pii>> st;
    st.push({0,s});
    while (st.size())
    {
        int u=st.top().second;
        int du=st.top().first;
        st.pop();
        if (du != d[u]) continue;
        for (auto vv:g[u])
        {
            int v=vv.second;
            int dv=vv.first;
            if (du+dv<d[v])
            {
                d[v]=du+dv;
                st.push({d[v],v});
            }
        }
    }
}
void solve1() // l==0
{
    dijkstra(1,d1);
    cout<<d1[n];
}

void solve2() // k==1
{
    dijkstra(1,d1);
    dijkstra(n,d2);
    if (l==0)
    {
        cout<<d1[n]; return;
    }
    int ans=oo;
    for (auto vv:hoa)
        ans=min(ans,d1[vv]+d2[vv]);
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);

    cin>>n>>m>>k>>l;
    for(int i=1; i<=n; i++)
    {
        int nn,tmp;
        cin>>nn;
        for (int ii=1; ii<=nn; ii++)
        {
            cin>>tmp;
            h[i].push_back(tmp);
            hoa.insert(i);
        }
    }

    for (int i=1; i<=m; i++)
    {
        int u,v,ts;
        cin>>u>>v>>ts;
        g[u].push_back({ts,v});
        g[v].push_back({ts,u});
    }

    if (l==0) solve1(); else
        if (k==1) solve2(); else
       {
         dfs(1,0);
          if (minn == 999999999) cout<<-1; else
          cout<<minn;
       }
    return 0;

}
