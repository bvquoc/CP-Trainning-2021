#include<bits/stdc++.h>
using namespace std;
#define Soloz "socks"
#define F first
#define S second
#define pb push_back
typedef long long ll;
#define fore(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();++it)

template<class T> inline void Write(T x)
{
    if(x<0)
    {
        putchar('-');
        x*=-1;
    }
    if(x>9) Write(x/10);
    putchar(x%10+'0');
}
template<class T>inline void Read(T &x)
{
    char c;
    for(c=getchar(); (c>'9'||c<'0')&&c!='-'; c=getchar());
    T y;
    if(c=='-')x=0,y=-1;
    else x=c-'0',y=1;
    for(c=getchar(); c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=y;
}

mt19937 Rand(time(0));
#define endl "\n"
#define al(a) ((a).begin(),(a).end())
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define ep emplace_back
const int maxn=5e5+5;
int n,q;
int deg[maxn];
vector < int > adj[maxn];
int numRed=0,numWhite=0;
int color[maxn];
int save[maxn];

void sub1()
{
    while(q--)
    {
        int node;
        cin>>node;
        color[node]^=1;
        if(color[node]==0)
            --numRed;
        else
            ++numRed;
        if(numRed<=1)
            cout<<"0\n";
        else
            cout<<"1\n";
    }
    exit(0);
}

struct EulerTour
{
    int high[maxn],topo[maxn<<1];
    int rmq[20][maxn<<1];
    int In[maxn],Out[maxn];
    int Times=0;
    int Size=0;
    int L[maxn],R[maxn];

    void dfs(int u, int par=-1)
    {
        In[u]=++Times;
        topo[++Size]=u;
        for(auto v : adj[u])
        {
            if(v==par)
                continue;
            high[v]=high[u]+1;
            dfs(v,u);
            topo[++Size]=u;
        }
        Out[u]=Times;
    }

    void RMQ()
    {
        for(int i=1; i<=n; ++i)
        {
            L[i]=1e9;
            R[i]=-1;
        }
        for(int i=1; i<=Size; ++i)
        {
            L[topo[i]]=min(L[topo[i]],i);
            R[topo[i]]=max(R[topo[i]],i);
            rmq[0][i]=topo[i];
        }
        for(int i=1; i<=18; ++i)
        {
            for(int j=1; j<=Size; ++j)
            {
                rmq[i][j]=rmq[i-1][j];
                if(j+(1ll<<(i-1))<=Size)
                {
                    if(high[rmq[i-1][j]]>high[rmq[i-1][j+(1ll<<(i-1))]])
                        rmq[i][j]=rmq[i-1][j+(1ll<<(i-1))];
                }
            }
        }
    }

    int LCA(int u, int v)
    {
        u=L[u];
        v=R[v];
        if(u>v)
            swap(u,v);
        int Log=log2(v-u+1);
        if(high[rmq[Log][u]]>high[rmq[Log][v-(1ll<<Log)+1]])
            return rmq[Log][v-(1ll<<Log)+1];
        return rmq[Log][u];
    }
} EL;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Soloz".inp","r",stdin);
    freopen(Soloz".out","w",stdout);
    cin>>n>>q;
    FOR(i,1,n)
    {
        cin>>color[i];
        if(color[i]==1)
            numRed++;
        else
            numWhite++;
    }
    int DegMax=0;
    FOR(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].ep(v);
        adj[v].ep(u);
        deg[u]++;
        deg[v]++;
        DegMax=max(DegMax,deg[u]);
        DegMax=max(DegMax,deg[v]);
    }
    if(DegMax<=2)
        sub1();
    int root;
    vector < int > prepar;
    if(DegMax<=3)
    {
        int num=0;
        FOR(i,1,n)
        if(deg[i]==3)
        {
            ++num;
            root=i;
        }
        if(num==1)
        {
            EL.dfs(root);
            EL.RMQ();
            FOR(i,1,n)
            if(EL.high[i]==1)
            {
                prepar.ep(i);
            }
            FOR(i,1,n)
            {
                if(color[i]==0)
                    continue;
                for(auto v: prepar)
                {
                    int u=i;
                    if(EL.In[v]<=EL.In[u] && EL.Out[u]<=EL.Out[v])
                        save[v]++;
                }
            }
            while(q--)
            {
                int node;
                cin>>node;
                color[node]^=1;
                if(color==0)
                    --numRed;
                else
                    ++numRed;
                if(color[node]==0)
                {
                    for(auto v : prepar)
                        if(EL.In[v]<=EL.In[node] && EL.Out[node]<=EL.Out[v])
                            save[v]--;
                }
                else
                {
                     for(auto v : prepar)
                        if(EL.In[v]<=EL.In[node] && EL.Out[node]<=EL.Out[v])
                            save[v]++;
                }

                int numzero=0;
                for(auto v: prepar)
                    if(save[v]>0)
                    ++numzero;
                cerr<<numzero<<endl;
                if(color[root]==1 && numzero==0)
                {
                    cout<<"0\n";
                    continue;
                }
                if(color[root]==1 && numzero==1)
                {
                    cout<<"1\n";
                    continue;
                }
                if(numRed<=1)
                {
                    cout<<"0\n";
                    continue;
                }
                if(numRed>1 && numzero>=2)
                {
                    cout<<numzero-1<<"\n";
                    continue;
                }
                if(numRed>1 && numzero==1)
                {
                    cout<<"1\n";
                    continue;
                }
            }
        }
    }
    return 0;
}
