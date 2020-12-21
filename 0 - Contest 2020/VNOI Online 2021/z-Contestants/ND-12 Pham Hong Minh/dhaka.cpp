#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define sefi second.first
#define sese second.second
#define piii pair <ll , pair < ll,ll> >
using namespace std;

const ll N = 100005;
struct _
{
    ll id,gt;
};
vector <_> ds[N];
ll f[N][45],res,sl,n,m,k,l,w,u,v,trt,_trt,_gt,a,p[11],tt[N],gt;
priority_queue < piii , vector < piii > , greater < piii > > pq;

int main()
{
    freopen("dhaka.inp","r",stdin); freopen("dhaka.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> l;

    p[0] = 1;
    for (ll i = 1;i<=k;++i) p[i] = p[i-1] + p[i-1];

    memset(tt,0,sizeof(tt));
    for (ll i = 1;i<=n;++i)
    {
        cin >> sl;
        for (ll j = 1;j <= sl;++j)
        {
            cin >> a;
            tt[i] = tt[i] + p[a - 1];
        }
    }

    for (ll i = 1;i<=m;++i)
    {
        cin >> u >> v >> w;
        ds[u].pb({v,w});
        ds[v].pb({u,w});
    }

    memset(f,-1,sizeof(f)); res = -1;
    f[1][tt[1]] = 0;
    pq.push({0,{tt[1],1}});

    while (!pq.empty())
    {
        piii tam = pq.top(); pq.pop();
        u = tam.sese; trt = tam.sefi; gt = tam.fi;
        if (u == n)
        {
           if (__builtin_popcount(trt) >= l)
           {
               if (res == -1 || res > gt) res = gt;
           }
        }

        for (auto z:ds[u])
        {
            v = z.id; w = z.gt;
            _trt = (trt | tt[v]);
            _gt = w + gt;
            if (f[v][_trt] == -1 || f[v][_trt] > _gt)
            {
                f[v][_trt] = _gt;
                pq.push({_gt,{_trt,v}});
            }
        }
    }

    cout << res;

    return 0;
}
