#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define ll long long
#define ld double
#define up_b upper_bound
#define low_b lower_bound
#define mp make_pair
#define pb push_back

typedef pair<int,int> pii;

const int oo=1e9;
const int mod=1e9+7;
const int N=5e5;

template<class T> void ckmax(T &a,T b) {a=max(a,b);}
template<class T> void ckmin(T &a,T b) {a=min(a,b);}

ll Power(int x,int y)
{
    ll ans=1;
    for (ll t=x;y;y>>=1)
    {
        if (y&1) ans=(ans*t)%mod;
        t=(t*t)%mod;
    }
    return  ans;
}
ll Rev(int x)
{
    return Power(x,mod-2);
}
int a[N+5];
vector<int> dsk[N+5];
map<int,int> M[N+5];
ll f[N+5][40];
typedef pair<ll,pii> iii;
int n,m,k,l;
void dijkstra(int s,int mask)
{
    for (int i=1;i<=n;i++)
    for (int j=0;j<(1<<k);j++) f[i][j]=1e18;
    f[s][mask]=0;
    priority_queue<iii,vector<iii> , greater<iii> > H;
    H.push(mp(0,mp(s,mask)));
    while (!H.empty())
    {
        iii res=H.top();H.pop();
        if (f[res.Y.X][res.Y.Y]<res.X) continue;
        pii u=res.Y;
        for (int v:dsk[u.X])
        {
            int S=u.Y|a[v];
            if (f[v][S]>f[u.X][u.Y]+M[u.X][v])
            {
                f[v][S]=f[u.X][u.Y]+M[u.X][v];
                H.push(mp(f[v][S],mp(v,S)));
            }
        }
    }
}
void solve()
{
    cin>>n>>m>>k>>l;
    for (int i=1;i<=n;i++)
    {
        int t;cin>>t;
        while (t--)
        {
            int x;cin>>x;
            a[i]=a[i]|(1<<(x-1));
        }
    }
    for (int i=1;i<=m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        M[x][y]=M[y][x]=w;
        dsk[x].pb(y);
        dsk[y].pb(x);
    }
    dijkstra(1,a[1]);
    ll mn=1e18;
    for (int i=0;i<(1<<k);i++)
    {
        int d=0;
        for (int j=0;j<k;j++) if (i>>j&1) d++;
        if (d>=l) ckmin(mn,f[n][i]);
    }
    if (mn==1e18) cout<<-1;
    else cout<<mn;
}
int main()
{
    freopen("DHAKA.inp","r",stdin);
    freopen("DHAKA.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();

}

