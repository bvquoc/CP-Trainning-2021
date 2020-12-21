#include <bits/stdc++.h>
#define name "DECOR"
#define pb push_back
using namespace std;
const int N=1e5+100;

int n,m,k,a[N],u,v,Rank[N];
char ch;
vector <int> ke[N];

namespace sub1
{
    int dau,L,res,f[N];
    void solve()
    {
        for (int i=1; i<=n; i++)
        {
            f[i]=f[i-1]+a[i];
        }
        L=1;
        for (int R=1; R<=n; R++)
        {
            while (L < R && R-L+1 - (f[R]-f[L-1])>k ) L++;
            if (R-L+1>res)
            {
                res=(R-L+1);
                dau=L;
            }
        }
        cout<<L<<" "<<res<<'\n';
    }
}


int pa[N];

int cha(int x)
{
    while (pa[x]!=x) x=pa[x];
    return x;
}

void Union(int u,int v)
{
    u=cha(u); v=cha(v);
    if (u!=v)
    {
        if (Rank[u]<Rank[v]) swap(u,v);
        pa[v]=u; Rank[u]+=Rank[v]+1;
    }
}

int l;
int In[N],L,R;

void init()
{
    R=k;
    for (int i=1; i<=n; i++)
    {
        int p=cha(i);
        if (!In[p]) In[p]=++l;
        ke[In[p]].pb(i);
        In[i]=In[p];
        R+=a[i];
    }
}

int chong[N],vo[N],vs[N];

bool timvo(int u)
{
    if (vs[u]) return 0;
    vs[u]=1;
    for (auto v:ke[In[u]])
    {
        if (v!=u)
        {
            if (!chong[v] || timvo(chong[v]))
            {
                chong[v]=u;
                vo[u]=v;
                return 1;
            }
        }
    }
    return 0;
}

bool xet(int L, int R)
{
    for (int i=L; i<=R; i++)
    {
        vs[i]=chong[i]=vo[i]=0;
    }
    int res=0;
    for (int i=L; i<=R; i++)
    {
        if (a[i] || vo[i] || timvo(i))
        {
            res++;
        }
    }
    return (res+k>=(R-L+1));
}

int vt,res;

void sub2()
{
    init(); bool kt;
    L=1;
    while (L<=R)
    {
        int mid=(L+R)>>1; kt=0;
        for (int i=1; i<=n-mid+1; i++)
        {
            if (xet(i,i+mid-1))
            {
                vt=i; kt=1; break;
            }
        }
        if (kt)
        {
            res=mid;
            L=mid+1;
        }
        else R=mid-1;
    }

    cout<<vt<<" "<<res<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(name".inp","r"))
    {
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>ch;
        a[i]=ch-'0';
        pa[i]=i;
        Rank[i]=1;
    }

    for (int i=1; i<=m; i++)
    {
        cin>>u>>v;
        Union(u,v);
    }

    if (m==0)
    {
        sub1::solve();
    }
   // else
        sub2();
}
