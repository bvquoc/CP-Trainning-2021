#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
typedef pair<ll,int> pir;
#define fi first
#define se second
vector<pir> g[maxn];
int n,k,m,l;
int melon[maxn];
void enter()
{
    cin>>n>>m>>k>>l;
    _for(i,1,n+1)
    {
        int s;
        cin>>s;
        _for(j,0,s)
        {
            int t;
            cin>>t;
            melon[i] |= (1<<(t-1));
        }
    }
    _for(i,1,m+1)
    {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        g[u].push_back(pir(c,v));
        g[v].push_back(pir(c,u));
    }
}

ll f[maxn][1<<6];
bool d[maxn][1<<6];
struct node
{
    int u, tt;
    ll val;
    node(){}
    node(int aa,ll bb,int cc)
    {
        u = aa; val=  bb; tt = cc;
    }
};
bool operator>(const node & x1,const node& x2)
{
    return x1.val > x2.val;
}
const ll oo = 1e16;

void dijkstra()
{
    _for(i,1,n+1)
        _for(j,0,(1<<k))
            f[i][j] = oo;
    priority_queue<node,vector<node>,greater<node>> heap;
    f[1][0] = 0;
    heap.push(node(1, ll(0) ,0));
    while(!heap.empty())
    {
        node q = heap.top();
        heap.pop();
        if (!d[q.u][q.tt])
        {
            d[q.u][q.tt] = true;
            for(auto i:g[q.u])
            {
                if (!d[i.se][q.tt | melon[i.se]])
                {
                    if (q.val + i.fi < f[i.se][q.tt | melon[i.se]])
                    {
                        f[i.se][q.tt | melon[i.se]] = q.val + i.fi;
                        heap.push(node(i.se, q.val + i.fi, q.tt | melon[i.se]));
                    }
                }
            }
        }
    }
    ll ans = oo;
    _for(i,1,(1<<k))
    {
        if (__builtin_popcount(i) >=l && d[n][i])
        {
            ans = min(ans, f[n][i]);
        }
    }
    if (ans == oo) cout<<"-1";
    else cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);
    enter();
    dijkstra();
    return 0;
}
