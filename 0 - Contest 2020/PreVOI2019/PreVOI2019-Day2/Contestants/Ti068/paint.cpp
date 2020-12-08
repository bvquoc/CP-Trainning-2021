                                        ///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo "paint"
#define MOD 1000000007
#define maxn 1000111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))

using namespace std;
int color[30];
int cnt[maxn];
int par[maxn];
vector<int> ke[maxn];
int n;
int pos;
char kt[maxn];
int visit[maxn];
int Find(int u)
{
    int v=par[u];
    if(u!=v)
        return par[u]=Find(v);
    return u;
}
void dfs(int u,char color)
{
    visit[u]=1;
    kt[u]=color;
    for(int v:ke[u])
    {
        if(visit[v]==1) continue;
        dfs(v,color);
    }
}
void nhap()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            pos++;
            char x;
            cin>>x;
            if(color[x-'a']==0)
            {
                color[x-'a']=pos;
                cnt[pos]=x-'a';
            }
            else
            {
                int g=Find(color[x-'a']);
                ke[pos].push_back(g);
                ke[g].push_back(pos);
                cnt[pos]=x-'a';
                par[pos]=g;
            }
        }
        else
        {
            char x,y;
            cin>>x>>y;
            int x1=x-'a';
            int y1=y-'a';
            int u=Find(color[x1]);
            int v=Find(color[y1]);
            if(u==0&&v==0) continue;
            if(u==0)
            {
                continue;
            }
            if(v==0)
            {
                cnt[u]=y1;
                color[x1]=0;
                continue;
            }
            if(u!=v)
            {
                par[u]=v;
                ke[u].push_back(v);
                ke[v].push_back(u);
            }
            color[x1]=0;
        }
    }
    for(int i=1;i<=pos;i++)
    {
        if(visit[i]==1) continue;
        int p=Find(i);
        char k=char(cnt[p]+'a');
        dfs(i,k);
    }
    for(int i=1;i<=pos;i++)
    {
        cout<<kt[i];
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Zo".inp","r",stdin);
    freopen(Zo".out","w",stdout);
    nhap();
}
