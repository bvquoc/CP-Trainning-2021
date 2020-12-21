#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long LL;
const int MAXN=1+5e5;
const int inf=1+1e9;
const LL mod=1e9+7;
int n,q,deg[MAXN],ma,cnt,cnt1,cur,cl,res[4];
int a[MAXN],col[MAXN];
vector<int> g[MAXN];
void sol1()
{
    if(cnt>=2) cout<<1<<'\n';
    else cout<<0<<'\n';
    for(int i=1; i<=q; ++i)
    {
        int x;
        cin>>x;
        if(a[x]==1)
        {
            a[x]=0;
            --cnt;
        }
        else
        {
            a[x]=1;
            ++cnt;
        }
        if(cnt>=2) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
}
void dfs(int u,int du)
{
    for(int i=0; i<g[u].size(); ++i)
    {
        int v=g[u][i];
        if(v==du) continue;
        if(u==cur) cl=i+1;
        col[v]=cl;
        dfs(v,u);
    }
}
void sol2()
{
    cnt=0;
    for(int i=1; i<=n; ++i)
    {
        if(deg[i]==3)
        {
            cur=i;
            col[i]=0;
            dfs(i,i);
            break;
        }
    }
    for(int i=1; i<=n; ++i)
    {
        //cout<<col[i]<<'\n';
        if(a[i]==1)
        {
            res[col[i]]++;
            cnt++;
        }
    }
    if(cnt<=1) cout<<0<<'\n';
    if(res[1]>0&&res[2]>0&&res[3]>0) cout<<2<<'\n';
    if(res[1]>0&&res[2]==0&&res[3]==0&&cnt>1) cout<<1<<'\n';
    if(res[1]==0&&res[2]>0&&res[3]==0&&cnt>1) cout<<1<<'\n';
    if(res[1]>0&&res[2]==0&&res[3]==0&&cnt>1) cout<<1<<'\n';
    if(res[1]==0&&res[2]==0&&res[3]>0&&cnt>1) cout<<1<<'\n';
    if(res[1]>0&&res[2]>0&&res[3]==0) cout<<1<<'\n';
    if(res[1]>0&&res[2]==0&&res[3]>0) cout<<1<<'\n';
    if(res[1]==0&&res[2]>0&&res[3]>0) cout<<1<<'\n';
    for(int i=1; i<=q; ++i)
    {
        int x;
        cin>>x;
        if(a[x]==1)
        {
            a[x]=0;
            cnt--;
            res[col[x]]--;
        }
        else
        {
            a[x]=1;
            cnt++;
            res[col[x]]++;
        }
        if(cnt<=1) cout<<0<<'\n';
        if(res[1]>0&&res[2]>0&&res[3]>0) cout<<2<<'\n';
        if(res[1]>0&&res[2]==0&&res[3]==0&&cnt>1) cout<<1<<'\n';
        if(res[1]==0&&res[2]>0&&res[3]==0&&cnt>1) cout<<1<<'\n';
        if(res[1]>0&&res[2]==0&&res[3]==0&&cnt>1) cout<<1<<'\n';
        if(res[1]==0&&res[2]==0&&res[3]>0&&cnt>1) cout<<1<<'\n';
        if(res[1]>0&&res[2]>0&&res[3]==0) cout<<1<<'\n';
        if(res[1]>0&&res[2]==0&&res[3]>0) cout<<1<<'\n';
        if(res[1]==0&&res[2]>0&&res[3]>0) cout<<1<<'\n';
    }

}
int vis[MAXN],cnt2,ans,kt;
void dfs1(int u,int du)
{
    if(g[u].size()==1&&cnt2>0)
    {
        kt =1;
        return;
    }
    for(int i=0; i<g[u].size(); ++i)
    {
        int v=g[u][i];
        if(v==du) continue;
        if(kt==1) return;
        if(a[v]==1&&vis[v]==0)
        {
            ++cnt2;
            vis[v]=1;
        }
        dfs1(v,u);
    }
}
int main()
{
#define TASK "SOCKS"
    if(fopen(TASK ".inp","r"))
    {
        freopen(TASK ".inp","r",stdin);
        freopen(TASK ".out","w",stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1; i<=n; ++i)
    {
        cin>>a[i];
        if(a[i]==1) ++cnt;
    }
    for(int i=1; i<n; ++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    for(int i=1; i<=n; ++i)
    {
        ma=max(ma,deg[i]);
        if(deg[i]==3) ++cnt1;
    }
//==============================================================

    if(ma==2)
    {
        sol1();
        return 0;
    }

//==============================================================

    if(ma==3&&cnt1==1)
    {
        sol2();
    }

//===============================================================
    if(cnt<=1) cout<<0<<'\n';
    else
    {
        for(int i=1; i<=n; ++i)
        {
            if(a[i]==1&&vis[i]==0)
            {
                ++ans;
                cnt2=0;
                kt=0;
                vis[i]=1;
                dfs1(i,i);
            }
        }

        cout<<ans<<'\n';
    }
    for(int i=1; i<=q; ++i)
    {
        int x;
        cin>>x;
        if(a[x]==0)
        {
            a[x]=1;
            ++cnt;
        }
        else
        {
            a[x]=0;
            --cnt;
        }
        if(cnt<=1) cout<<0<<'\n';
        else
        {
            for(int i=1; i<=n; ++i) vis[i]=0;
            ans=0;
            for(int i=1; i<=n; ++i)
            {
                if(a[i]==1&&vis[i]==0)
                {
                    ++ans;
                    cnt2=0;
                    kt=0;
                    vis[i]=1;
                    dfs1(i,i);
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
