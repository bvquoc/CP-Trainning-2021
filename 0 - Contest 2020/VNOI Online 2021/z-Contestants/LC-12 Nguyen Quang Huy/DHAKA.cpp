#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define mod 1000000007
#define pii pair <int ,int>
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define mp make_pair
#define maxn 100005
#define task "DHAKA"
#define piii pair <ll,pair <int,int>>

using namespace std;

int n,m,k,l,M[maxn];
ll ans=1e18,d[maxn][50];
vector <pii> ke[maxn];
priority_queue <piii, vector <piii>, greater <piii> > pq;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m>>k>>l;
    for(int i=1; i<=n; i++) {
        int t,x;
        cin>>t;
        for(int j=1; j<=t; j++) {
            cin>>x;
            M[i]+=(1<<(x-1));
        }
    }
    for(int i=1; i<=m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        ke[u].PB(mp(v,w));
        ke[v].PB(mp(u,w));
    }
    for(int i=1; i<=n; i++)
        for(int mask=0; mask<(1<<k); mask++)
            d[i][mask]=1e18;
    d[1][M[1]]=0;
    pq.push(mp(d[1][M[1]],mp(M[1],1)));
    while(!pq.empty()) {
        int u=pq.top().y.y;
        int mask=pq.top().y.x;
        pq.pop();
        for(pii v:ke[u])
            if(d[v.x][mask|M[v.x]]>d[u][mask]+1ll*v.y) {
                d[v.x][mask|M[v.x]]=d[u][mask]+1ll*v.y;
                pq.push(mp(d[v.x][mask|M[v.x]],mp(mask|M[v.x],v.x)));
            }
    }
    for(int mask=0; mask<(1<<k); mask++) {
        int cnt=__builtin_popcount(mask);
        if(cnt>=l)
            ans=min(ans,d[n][mask]);
    }
    if(ans==1e18)
        cout<<-1;
    else
        cout<<ans;
}
