#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N=2*1e5+5;
const long long oo=1e18;

typedef pair<long long, int> ii;

int n, m, k, l, typ[N];
long long f[N][100];
vector<ii> ke[N];

void dij()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<(1<<k);j++) f[i][j]=+oo;
    }

    priority_queue<ii, vector<ii>, greater<ii> > h;

    h.push({f[1][typ[1]]=0, 1*100+typ[1]});

    while (!h.empty())
    {
        int u=h.top().se/100, mask=h.top().se%100;
        long long s=h.top().fi;
        h.pop();

        if (f[u][mask]!=s) continue;

        for (ii p:ke[u])
        {
            int v=p.se;
            int mask2=(mask|typ[v]);
            long long w=p.fi;

            if (s+w<f[v][mask2])
            {
                h.push({f[v][mask2]=s+w, v*100+mask2});
            }
        }
    }
}

int cbit(int i)
{
    int r=0;
    for (;i;i&=(i-1)) r++;
    return r;
}

void solve()
{
    cin>>n>>m>>k>>l;
    for (int i=1;i<=n;i++)
    {
        typ[i]=0;

        int s;cin>>s;
        for (int j=1;j<=s;j++)
        {
            int x;cin>>x;
            typ[i]|=(1<<(x-1));
        }
    }

    for (int i=1;i<=m;i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        ke[u].push_back({w, v});
        ke[v].push_back({w, u});
    }

    dij();

    long long ans=oo;
    for (int i=0;i<(1<<k);i++)
        if (cbit(i)>=l) ans=min(ans, f[n][i]);

    if (ans==oo) ans=-1;
    cout<<ans;
}

int main()
{
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    solve();

    return 0;
}
