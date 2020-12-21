#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5;
#define TASK "DECOR"
#define ll long long
int n,m,k;
int a[N];
/*ll Rand(ll l,ll r)
{
    ll mod=r-l+1;
    return l+(1ll*rand()*rand()%mod+1ll*INT_MAX*rand()%mod+1ll*rand()*RAND_MAX%mod)%mod;
}
void SinhTest()
{
    freopen("DECOR.inp","w",stdout);
    srand(time(NULL));
    n=Rand(1,2000),m=Rand(1,n/2),k=Rand(1,n);
    k=10;
    cout<<n<<' '<<m<<' '<<k<<'\n';
    for(int i=1;i<=n;++i)
        cout<<(rand()&1);
    cout<<'\n';
    while(m--)
    {
        int u,v;
        u=Rand(1,n),v=Rand(1,n);
        cout<<u<<' '<<v<<'\n';
    }
}*/
struct DisjointSet
{
    int root[N],cnt[N];
    int GetRoot(int u)
    {
        return (root[u])?(root[u]=GetRoot(root[u])):(u);
    }
    void join(int u,int v)
    {
        int p=GetRoot(u);
        int q=GetRoot(v);
        if(p!=q)
        {
            root[p]=q;
            cnt[q]+=cnt[p];
        }
    }
} DSU;
void inp()
{
    cin>>n>>m>>k;
    for(int i=1; i<=n; ++i)
    {
        char c;
        cin>>c;
        a[i]=(c=='0');
        if(!a[i])
            DSU.cnt[i]=1;
        a[i]+=a[i-1];
    }
    for(int i=1; i<=m; ++i)
    {
        int u,v;
        cin>>u>>v;
        DSU.join(u,v);
    }
}
struct Sub12
{
    int dd[N];
    void solve()
    {
        int ans=-1,l=0,r=0;
        dd[0]=1;
        for(int i=1; i<=n; ++i)
        {
            if(a[i]<=k)
            {
                if(i>ans)
                {
                    ans=i;
                    l=1,r=i;
                }
            }
            else
            {
                int p=dd[a[i]-k];
                if((i-p+1)>ans)
                {
                    ans=i-p+1;
                    l=p,r=i;
                }
            }
            if(!dd[a[i]])
                dd[a[i]]=i+1;
        }
        if(ans==-1)
        {
            cout<<-1;
            return;
        }
        cout<<l<<' '<<r<<'\n';
    }
} sub12;
struct Sub3
{
    int sz[N];
    void solve()
    {
        int ans=0,L,R;
        for(int r=1; r<=n; ++r)
        {
            int x=k;
            for(int i=1; i<=n; ++i)
                sz[i]=DSU.cnt[i];
            int l=r;
            for(; l>=1; --l)
            {
                int p=DSU.GetRoot(l);
                if(sz[p])
                    --sz[p];
                else
                {
                    if(x)
                        --x;
                    else
                        break;
                }
            }
            ++l;
            if((r-l+1)>ans)
                ans=r-l+1,L=l,R=r;
        }
        if(ans==0)
            cout<<-1;
        else
            cout<<L<<' '<<R<<'\n';
    }
} sub3;
struct Sub4
{
    int sz[N];
    int res=0;
    void solve()
    {
        int ans=0,L,R;
        int l=1;
        for(int r=1;r<=n;++r)
        {
            int p=DSU.GetRoot(r);
            ++sz[p];
            if(sz[p]>DSU.cnt[p])
                ++res;
            while(res>k)
            {
                int par=DSU.GetRoot(l);
                --sz[par];
                if(sz[par]>=DSU.cnt[par])--res;
                ++l;
            }
            if((r-l+1)>ans)
            {
                ans=r-l+1;
                L=l,R=r;
            }
        }
        if(ans==0)
            cout<<-1;
        else
            cout<<L<<' '<<R;
    }
}sub4;
void solve()
{
    /*if(m==0)
    {
        sub12.solve();
        return;
    }*/
   // sub3.solve();
    sub4.solve();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //SinhTest();return 0;
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    inp();
    solve();
    return 0;
}
