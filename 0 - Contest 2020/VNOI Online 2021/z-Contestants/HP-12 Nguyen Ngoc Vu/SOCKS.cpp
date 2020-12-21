#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(i,x) for(auto &i:x)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r)
{
    return l+rng()%(r-l+1);
}
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define pii pair<int,int>
#define fi first
#define se second
#define batbit(i,x) (x|(1ll<<i))
#define getbit(i,x) ((x>>i)&1)

const int mn=5e5+10;
int a[mn],n,q,cnt,fal,tu[mn],dd[4],deg[mn],dem,root;
vector<int> ke[mn];

void dfs(int u,int p,int par)
{
    if(ke[u].size()!=3)
    {
        dd[u]=par;
        if(a[u]) tu[par]++;
    }
    forv(v,ke[u]) if(v!=p)
    {
        if(ke[u].size()==3) par++;
        dfs(v,u,par);
    }
}

main()
{
    freopen("SOCKS.INP","r",stdin);
    freopen("SOCKS.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    forinc(i,1,n)
    {
        cin >> a[i];
        if(a[i]) cnt++;
    }
    forinc(i,1,n-1)
    {
        int u,v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
        deg[u]++;
        deg[v]++;
        if(deg[u]==3) dem++,fal=u;
        if(deg[v]==3) dem++,fal=v;
    }
    if(dem==1)
    {
        forinc(i,1,n) if(deg[i]!=3) root=i;
        dfs(root,0,1);
        if(tu[1]&&tu[2]&&tu[3]) cout << 2 << "\n";
        else if((tu[1]&&tu[2])||(tu[2]&&tu[3])||(tu[3]&&tu[1])||(tu[1]+a[fal]>1)||(tu[2]+a[fal]>1)||(tu[3]+a[fal]>1)) cout << 1 << "\n";
        else cout << 0 << "\n";
        forinc(oo,1,q)
        {
            int x;
            cin >> x;
            if(a[x])
            {
                tu[dd[x]]--;
                a[x]=1-a[x];
            }
            else tu[dd[x]]++,a[x]=1-a[x];
             if(tu[1]&&tu[2]&&tu[3]) cout << 2 << "\n";
            else if((tu[1]&&tu[2])||(tu[2]&&tu[3])||(tu[3]&&tu[1])||(tu[1]+a[fal]>1)||(tu[2]+a[fal]>1)||(tu[3]+a[fal]>1)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        return 0;
    }
    if(cnt>1) cout << 1 << "\n";
    else cout << 0 << "\n";
    forinc(i,1,q)
    {
        int x;
        cin >> x;
        if(a[x]==1) a[x]=0,cnt--;
        else a[x]=1,cnt++;
        if(cnt>1) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}
