#include<bits/stdc++.h>
using namespace std;
#define Soloz "dhaka"
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
#define Bit(i,x) (((x)>>(i))&1)
#define Mask(i) (1LL<<(i))
const int maxn=1e5+5;
vector < pair < int, int > > adj[maxn];

long long d[maxn][40];
vector < int > color[maxn];
int n,m;
int k,l;
const int mod=1e18;

struct Data
{
    long long val;
    int u,num;
    friend bool operator <(const Data &a,const Data &b)
    {
        return a.val<b.val ;
    }
    friend bool operator >(const Data &a,const Data &b)
    {
        return a.val>b.val ;
    }
};
priority_queue < Data, vector < Data >, greater < Data > > q;

inline void dijk()
{
    FOR(i,1,n)
    FOR(j,0,Mask(k)-1)
    d[i][j]=mod;
    int huy=0;
    for(auto v : color[1])
        huy=huy|(Mask(v-1));
    d[1][huy]=0;
    q.push({0,1,huy});
    while(!q.empty())
    {
        long long val=q.top().val;
        int u=q.top().u;
        int num=q.top().num;
        q.pop();
        for(auto node : adj[u])
        {
            int v=node.F;
            int w=node.S;
            int newnum=num;
            if(color[v].size()!=0)
                for(auto Color : color[v])
                    newnum=newnum|(Mask(Color-1));
            if(d[v][newnum]>d[u][num]+w)
            {
                d[v][newnum]=d[u][num]+w;
                q.push({d[v][newnum],v,newnum});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Soloz".inp","r",stdin);
    freopen(Soloz".out","w",stdout);
    cin>>n>>m>>k>>l;
    FOR(i,1,n)
    {
        int s;
        cin>>s;
        FOR(j,1,s)
        {
            int y;
            cin>>y;
            color[i].ep(y);
        }
    }

    FOR(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].ep(v,w);
        adj[v].ep(u,w);
    }

    dijk();
    long long ans=mod;
    FOR(i,0,Mask(k)-1)
    {
        int num=__builtin_popcount(i);
        if(num>=l)
            ans=min(ans,d[n][i]);
    }
    if(ans==mod)
        ans=-1;
    cout<<ans;
    return 0;
}
