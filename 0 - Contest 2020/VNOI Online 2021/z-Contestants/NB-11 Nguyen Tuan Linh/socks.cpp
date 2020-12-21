#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define task "socks"
#define pb push_back
using namespace std;
typedef long long ll;
const int MAX = 500000;
vector<int> g[MAX+5];
int trace[MAX+5],child[MAX+5],path,seetop,a[MAX+5],l[MAX+5],flag[MAX+5];
int n,q;
void dfs(int u,int p)
{
    child[u]=a[u];
    //cout<<u<<endl;
    for(auto v : g[u]) if(v!=p)
    {
        dfs(v,u);
        child[u]+=child[v];
    }
}

void update(int s,int t)
{
    l[s]=1;
    if(l[t]) l[t]=0; else ++path;
    while(t!=s) flag[t=trace[t]]=1;
}

void findpath(int u,int p,int s)
{
    if(seetop) return ;
    trace[u]=p;
    if(flag[u]==1)
    {
        seetop=u;
        update(s,u);
        return ;
    }
    for(auto v : g[u]) if(v!=p && 1 + 1 == 2) findpath(v,u,s);
}

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>a[i];

    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    int root=0;
    rep(i,1,n) if(a[i])
    {
        root=i;
        break;
    }


    if(root) dfs(root,root);

    rep(i,1,n) if(child[i])
    {
        if(i==root)
        {
            int cnt=0;
            for(auto v : g[i]) if(child[v]) cnt++;
            if(cnt==1) l[i]=1;
        }
        else if(child[i]==1&&a[i]) l[i]=1;
        flag[i]=1;
    }

    rep(i,1,n) path+=l[i];
    if(path<2) cout<<"0\n";else cout<<(path+1)/2<<'\n';

    while(q--)
    {
        int x;cin>>x;
        if(path==0)
        {
            l[x]=flag[x]=1;
            path++;
            cout<<"0\n";
            continue;
        }

        if(!flag[x])
        {
            seetop=0;

            findpath(x,x,x);
            cout<<x<<' '<<seetop<<'\n';
        }
    }
}
