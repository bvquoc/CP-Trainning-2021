#include <bits/stdc++.h>
#define fort(i,a,b) for(LL i=a;i<=b;i++)
#define x first
#define y second
#define MP make_pair
#define pb push_back
#define LL long long
using namespace std;
typedef pair<LL,LL> ii;
typedef pair<LL,pair<LL,LL> > iii;
const LL oo=1e15;
const LL N=1e5+5;
LL n,m,l,k,bit[N],d[N][50],rs;
priority_queue<iii, vector<iii> ,greater<iii> >pq;
vector<vector<ii> > a;
void diji(LL x)
{
    fort(i,1,n)
     fort(tt,0,(1<<k)-1)
      d[i][tt]=oo;
    d[1][0]=0;
    fort(i,1,n)
     fort(tt,0,(1<<k)-1)
       pq.push(MP(d[i][tt],MP(i,tt)));
    while (pq.size())
    {
        iii c=pq.top();pq.pop();
        if (__builtin_popcount(c.y.y)>=l&&c.y.x==n)
        {
            rs=c.x;
            return;
        }
        for(ii i:a[c.y.x])
            if (d[i.x][c.y.y|bit[i.x]]>c.x+i.y)
        {
            d[i.x][c.y.y|bit[i.x]]=c.x+i.y;
            pq.push(MP(d[i.x][c.y.y|bit[i.x]],MP(i.x,c.y.y|bit[i.x])));
        }
    }
}
int main()
{
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k>>l;
    a.resize(n+1);
    fort(i,1,n)
    {
        LL x;
        cin>>x;
        fort(j,1,x)
         {
             LL y;
             cin>>y;
             bit[i]^=(1<<y-1);
         }
    }
    fort(i,1,m)
    {
        LL u,v,w;
        cin>>u>>v>>w;
        a[u].pb(MP(v,w));
        a[v].pb(MP(u,w));
    }
    diji(1);
    if (rs==oo) cout<<"-1\n";else cout<<rs<<'\n';
    return 0;
}
