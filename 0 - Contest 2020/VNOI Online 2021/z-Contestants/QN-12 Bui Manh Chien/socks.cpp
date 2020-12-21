#include<bits/stdc++.h>
#define N 500010
#define ll long long
#define add push_back
using namespace std;
int n,dd[N],red,q,col[N],t[N],vis[N],deg[N],dem,g[N],f[N];
vector<int>ed[N];
void sub1()
{
    for(int i=1; i<=n; i++)
        red+=dd[i];
    if(red>1)
        cout<<"1\n";
    while(q--)
    {
        int x;
        cin>>x;
        if(dd[x])
        {
            red--;
            dd[x]=0;
        }
        else
        {
            red++;
            dd[x]=1;
        }
        cout<<(red>1)<<"\n";
    }
}
void DFS(int u,int c)
{
    vis[u]=1;
    col[u]=c;
    for(int v:ed[u])
    {
        if(vis[v])
            continue;
        DFS(v,c);
    }
}
void sub2()
{
    int st;
    for(int i=1; i<=n; i++)
        if(deg[i]==3)
        {
            st=i;
            break;
        }
    vis[st]=1;
    for(int i=0; i<ed[st].size(); i++)
    {
        int v=ed[st][i];
        DFS(v,i+1);
    }
    for(int i=1; i<=n; i++)
        if(dd[i])
        {
            red++;
            t[col[i]]++;
        }
    for(int i=1; i<=3; i++)
        if(t[i])
            dem++;
    if(dem==3)
        cout<<"2\n";
    if(dem==2)
        cout<<"1\n";
    if(dem==1)
    {
        if(red>1)
            cout<<"1\n";
        else
            cout<<"0\n";
    }
    while(q--)
    {
        int x;
        dem=0;
        cin>>x;
        if(dd[x])
        {
            dd[x]=0;
            red--;
            t[col[x]]--;
        }
        else
        {
            dd[x]=1;
            red++;
            t[col[x]]++;
        }
        for(int i=1; i<=3; i++)
            if(t[i])
                dem++;
        if(dem==3)
            cout<<"2\n";
        if(dem==2)
            cout<<"1\n";
        if(dem==1)
        {
            if(red>1)
                cout<<"1\n";
            else
                cout<<"0\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        dd[i]=x;
    }
    for(int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        ed[u].add(v);
        ed[v].add(u);
        deg[u]++;
        deg[v]++;
    }
    bool checksub1=true;
    for(int i=1; i<=n; i++)
        if(deg[i]>2)
            checksub1=false;
    if(checksub1)
        sub1();
    else
        sub2();
}
