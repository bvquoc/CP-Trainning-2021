#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
const int N=1e5+5;
const int lim=1e9+7;
typedef pair<int,int> ii;
int n,m,k,l,bm[N];
long long res;
long long f[1<<5][N];
vector <ii> a[N];
void dp(int u)
{
    for (int j=0;j<a[u].size();j++)
    {
        for (int t=0;t<(1 << k);t++)
            {
                if (f[t][u]!=lim)
                {
                    int v=a[u][j].s;
                    int w=a[u][j].f;
                    int newmask=t | bm[v];
                    if (f[newmask][v]>f[t][u]+w) f[newmask][v]=f[t][u]+w,dp(v);
                }
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    cin>>n>>m>>k>>l;
    for (int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for (int j=1;j<=k;j++)
        {
            int x;
            cin>>x;
            bm[i]=bm[i] | (1 << (x-1));
        }
    }
    for (int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].pb(ii(w,v));
        a[v].pb(ii(w,u));
    }
//===========================================
    for (int i=1;i<=n;i++)
        for (int t=0;t<(1 << k);t++) f[t][i]=lim;
    f[bm[1]][1]=0;
//===========================================
    dp(1);
    res=lim;
    for (int t=0;t<(1 << k);t++)
    {
        if (__builtin_popcount(t)>=l) res=min(res,f[t][n]);
    }
    if (res==lim) {cout<<-1;exit(0);}
    cout<<res;
}
