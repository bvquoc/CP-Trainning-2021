#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define se second

const ll INF=1e18;
const ll nmax=1e5+1;
const ll mod=1e9+7;

typedef pair<ll, ll> pa;
typedef vector<ll> ve;
typedef vector<ve> vve;
typedef vector<pa> vpa;

ifstream fi("SOCKS.INP");
ofstream fo("SOCKS.OUT");

ll n, q;
ll tt[1001];
ll kq=0;
vve dsk;
ve mau;
ll dfs(ll u)
{
    mau[u]=1;
    ll res=0;
    for(ll j=0; j<dsk[u].size(); ++j)
        if(!mau[dsk[u][j]])
        {
            ll d=dfs(dsk[u][j]);
            res+=d;
        }
    return max(tt[u], res);
}
int main()
{
    ios_base::sync_with_stdio(0), fi.tie(0), fo.tie(0);
    fi>>n>>q;
    dsk.assign(n+1, ve());
    for(ll i=1; i<=n; ++i)
        fi>>tt[i];
    for(ll i=1; i<n; ++i)
    {
        ll u, v;
        fi>>u>>v;
        dsk[u].push_back(v);
        dsk[v].push_back(u);
    }
    ll p=dfs(1);
   // fo<<(p*(p-1))/2<<'\n';
   fo<<1<<'\n';
    for(ll i=1; i<=q; ++i)
    {
        mau.assign(n+1, 0);
        ll cur;
        fi>>cur;
        tt[cur]=(tt[cur]+1)%2;
        ll res=dfs(1);
       // fo<<(res*(res-1))/2<<'\n';
       fo<<1<<'\n';
    }


}
