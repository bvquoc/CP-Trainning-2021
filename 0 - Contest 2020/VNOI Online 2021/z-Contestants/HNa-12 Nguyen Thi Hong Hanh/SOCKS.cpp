#include <bits/stdc++.h>

using namespace std;
const int N=5e5+5;
#define TASK "SOCKS"
int n,q;
bool on[N];
vector<int>adj[N];
bool T1=true,T2=false;
int in[N],out[N],cnt;
int par[20][N],h[N];
void inp()
{
    cin>>n>>q;
    for(int i=1; i<=n; ++i)
        cin>>on[i];
    for(int i=1; i<n; ++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void Sub()
{
    int cnt3=0;
    for(int i=1; i<=n; ++i)
    {
        T1&=(adj[i].size()<=2);
        cnt3+=(adj[i].size()==3);
    }
    if(cnt3==1)
        T2=true;
}
struct Sub1
{
    int res=0;
    void Update(int x)
    {
        on[x]^=1;
        if(on[x])
            ++res;
        else --res;
    }
    void solve()
    {
        for(int i=1; i<=n; ++i)
            res+=on[i];
        cout<<(res>=2)<<'\n';
        while(q--)
        {
            int x;
            cin>>x;
            Update(x);
            cout<<(res>=2)<<'\n';
        }
    }
} sub1;
int gt[N];
void dfs(int u,int p)
{
    in[u]=++cnt;
    h[u]=h[p]+1;
    gt[cnt]=u;
    par[0][u]=p;
    for(auto v:adj[u])
        if(v!=p)
            dfs(v,u);
    out[u]=cnt;
}
bool isChild(int par,int child)
{
    return (in[par]<=in[child]&&out[child]<=out[par]);
}
struct Sub2
{
    int cnt1=0,cnt2=0,cnt3=0,cnt;
    int res=0;
    int pos,Left,Right;
    void Update(int x,int d)
    {
        on[x]^=1;
        if(x==pos)
            cnt+=d;
        else if(isChild(x,pos))
            cnt1+=d;
        else if(isChild(Left,x))
            cnt2+=d;
        else if(isChild(Right,x))
            cnt3+=d;
        //cout<<cnt<<' '<<cnt1<<' '<<cnt2<<' '<<cnt3<<'\n';
        res=0;
        if(cnt1)
        {
            res=((cnt2!=0)+(cnt3!=0));
            return;
        }
        if((cnt2&&cnt3)||(cnt2>1)||(cnt3>1))
        {
            res=1;
            return;
        }
        if(cnt&&(cnt2||cnt3))
            res=1;
    }
    void solve()
    {
        for(int i=1; i<=n; ++i)
            if(adj[i].size()==1)
            {
                dfs(i,0);
                break;
            }
        for(int i=1; i<=n; ++i)
        {
            if(adj[i].size()==3)
            {
                pos=i;
                break;
            }
        }
        for(auto x:adj[pos])
            if(in[pos]<in[x])
            {
                if(Left)
                    Right=x;
                else
                    Left=x;
            }
        for(int i=1; i<=n; ++i)
        {
            if(on[i])
            {
                on[i]=false;
                Update(i,1);
            }
        }
        cout<<res<<'\n';
        while(q--)
        {
            int x;
            cin>>x;
            Update(x,(on[x])?(-1):(1));
            cout<<res<<'\n';
        }
    }
} sub2;
/*void RMQ()
{
    for(int x=1; x<=log2(n); ++x)
        for(int i=1; i<=n; ++i)
            par[x][i]=par[x-1][par[x-1][i]];
}
int LCA(int u,int v)
{
    if((u==0)||(v==0))return max(u,v);
    if(h[u]<h[v])swap(u,v);
    int d=h[u]-h[v];
    for(int i=log2(n);i>=0;--i)
        if((d>>i)&1)
        u=par[i][u];
    if(u==v)return u;
    for(int i=log2(n);i>=0;--i)
        if(par[i][u]!=par[i][v])
        u=par[i][u],v=par[i][v];
    return par[0][u];
}
struct SegmentTree
{
    int t[4*N],id[N];
    void init(int node,int l,int r)
    {
        if(l==r)
        {
            id[l]=node;
            if(on[gt[l]])
                t[node]=gt[l];
            return;
        }
        int mid=(l+r)>>1;
        init(node*2,l,mid);
        init(node*2+1,mid+1,r);
        t[node]=LCA(t[node*2],t[node*2+1]);
    }
    void Update(int x,int u)
    {
        int node=id[x];
        on[u]^=1;
        t[node]=(on[u])?(u):(0);
        for(node>>=1;node;node>>=1)
            t[node]=LCA(t[node*2],t[node*2+1]);
    }
}IT;*/
struct Sub3
{
    bool ok[N];
    int cnt=0;
    int root;
    void dfs2(int u,int p)
    {
        ok[u]=false;
        for(auto v:adj[u])
        {
            if(v==p)
                continue;
            dfs2(v,u);
            ok[u]|=ok[v];
        }
        if(u==root)
        {
            int res=0;
            for(auto v:adj[u])
                res+=ok[v];
            cnt+=(res<=1);
            return;
        }
        if(on[u]&&(!ok[u]))
            ++cnt;
        ok[u]|=on[u];
    }
    int Calc()
    {
        cnt=0;
        for(int i=1; i<=n; ++i)
            if(on[i])
            {
                root=i;
                dfs2(i,0);
                break;
            }
        return max(0,cnt-1);
    }
    void solve()
    {
        //dfs(1,0);
        //RMQ();
        //IT.init(1,1,n);
        cout<<Calc()<<'\n';
        while(q--)
        {
            int x;
            cin>>x;
            on[x]^=1;
            cout<<Calc()<<'\n';
        }
    }
}sub3;
void solve()
{
    Sub();
    if(T1)
    {
        sub1.solve();
        return;
    }
    if(T2)
    {
        sub2.solve();
        return;
    }
    sub3.solve();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    inp();
    solve();
    return 0;
}
