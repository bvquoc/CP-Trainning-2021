#include <bits/stdc++.h>
#define fi first
#define se second
#define sec second.first
#define thr second.second
using namespace std;
const int N=1e5+12;
const long long INF=1e18;
typedef pair<long long,long long> ii;
typedef pair<long long,ii> iii;
long long n,m,k,l;
long long dua[N];
long long d[N][6];
vector <ii> a[N];
long long cnt(long long x)
{
    return __builtin_popcount(x);
}
void dijsktra()
{
    priority_queue <iii, vector<iii>, greater<iii> > q;
    d[1][cnt(dua[1])]=0;
    q.push( iii( 0, {1, dua[1]} ) );
    while (q.size())
    {
        long long u=q.top().sec, du=q.top().fi, get=q.top().thr;
        q.pop();
        if (du!=d[u][cnt(get)]) continue;
        for(long long i=0; i<a[u].size(); i++)
        {
            long long v = a[u][i].fi, c=a[u][i].se;
            long long num = cnt(get | dua[v]);
            if (d[v][num] > d[u][cnt(get)] + c)
            {
                d[v][num] = d[u][cnt(get)] + c;
                q.push(iii(d[v][num], {v , get | dua[v]} ));
            }
        }
    }
}
int main()
{
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    cin>>n>>m>>k>>l;
    for(int i=1; i<=n; i++)
    {
        int sz;
        cin>>sz;
        for(int j=1; j<=sz; j++)
        {
            int x;
            cin>>x;
            dua[i]=dua[i]|(1<<(x-1));
        }
    }
    for(int i=1; i<=m; i++)
    {
        long long u,v,c;
        cin>>u>>v>>c;
        a[u].push_back(ii(v,c));
        a[v].push_back(ii(u,c));
    }
    for(int i=1; i<=n; i++) fill(d[i]+1,d[i]+5+1,INF);
    dijsktra();
    long long ans=INF;
    for(int i=l; i<=k; i++)
        ans=min(ans,d[n][i]);
    cout<<((ans==INF)?-1:ans);
}
