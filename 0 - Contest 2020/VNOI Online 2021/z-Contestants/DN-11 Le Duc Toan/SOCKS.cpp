#include<bits/stdc++.h>

using namespace std;

#define task "SOCKS"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()
#define endl '\n'

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};

const ll mod=1000000007; /// 998244353
const int base=311;
const int N=5e5+5;

int par[N];
int n,q,c[N];
vector<int> adj[N];

void sub1()
{
    int cnt=0;

    for(int i=1;i<=n;++i)
    {
        cnt+=c[i];
    }

    if(cnt) cout<<1;
    else cout<<0;
    cout<<endl;

    while(q--)
    {
        int x;
        cin>>x;

        if(c[x])
        {
            c[x]=0;
            --cnt;
        }
        else
        {
            c[x]=1;
            ++cnt;
        }

        if(cnt>=2) cout<<1<<endl;
        else cout<<0<<endl;
    }
}

void dfs(int u, int pre, int root)
{
    par[u]=root;

    for(int v:adj[u]) if(v!=pre)
    {
        dfs(v,u,root);
    }
}
void sub2()
{
    int root=0;

    for(int i=1;i<=n;++i)
    {
        if(zs(adj[i])==3)
        {
            root=i;
            break;
        }
    }

    int Count=0;

    for(int i:adj[root])
    {
        ++Count;
        dfs(i,root,Count);
    }

    vector<int> cnt(4,0);

    for(int i=1;i<=n;++i)
    {
        if(c[i]) cnt[par[i]]++;
    }

    int C=0;
    for(int i=1;i<=3;++i) C+=(cnt[i]>0);

    if(C==0) cout<<0;
    else if(C==1)
    {
        int dem=c[root];
        for(int i=1;i<=3;++i) dem+=cnt[i];

        if(dem>=2) cout<<1;
        else cout<<0;
    }
    else if(C==2) cout<<1;
    else cout<<2;

    cout<<endl;

    while(q--)
    {
        int x;
        cin>>x;

        if(c[x]==1)
        {
            c[x]=0;
            --cnt[par[x]];
        }
        else
        {
            c[x]=1;
            ++cnt[par[x]];
        }

        int C=0;
        for(int i=1;i<=3;++i) C+=(cnt[i]>0);

        if(C==0) cout<<0;
        else if(C==1)
        {
            int dem=c[root];
            for(int i=1;i<=3;++i) dem+=cnt[i];

            if(dem>=2) cout<<1;
            else cout<<0;
        }
        else if(C==2) cout<<1;
        else cout<<2;

        cout<<endl;
    }
}
void sub3()
{
    while(q--)
    {
        cout<<0<<endl;
    }
}
void gogo()
{
    cin>>n>>q;

    for(int i=1;i<=n;++i)
    {
        cin>>c[i];
    }
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }


    int ok=1;
    for(int i=1;i<=n;++i) ok&=(zs(adj[i])<=2);

    if(ok)
    {
        sub1();
        return;
    }

    ok=1;
    int cnt=0;

    for(int i=1;i<=n;++i)
    {
        cnt+=(zs(adj[i])==3);
        ok&=(zs(adj[i])<=3);
    }

    if(cnt==1&&ok)
    {
        sub2();
        return;
    }

    sub3();
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    gogo();
    return 0;
}







